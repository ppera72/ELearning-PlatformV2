#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QRegularExpression>
#include <QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QWidget>
#include <QRadioButton>

loginWindow::loginWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::loginWindow)
{
    ui->setupUi(this);

    //studentMain StudentMain;
    //professorMain ProfessorMain;

    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("qt");


    connect(ui->registerButton, &QPushButton::clicked, this, &loginWindow::on_registerButton_clicked);
    connect(ui->backToLoginPageButton, &QPushButton::clicked, this, &loginWindow::on_backToLoginPageButton_clicked);
    connect(ui->loginButton, &QPushButton::clicked, this, &loginWindow::on_loginButton_clicked);
    connect(ui->registerToDatabaseButton, &QPushButton::clicked, this, &loginWindow::on_registerToDatabaseButton_clicked);
    connect(ui->passwordRegisterHelpButton, &QPushButton::clicked, this, &loginWindow::on_passwordRegisterHelpButton_clicked);

}
loginWindow::~loginWindow()
{
    delete ui;
}


// LOGIN PAGE
bool loginWindow::checkIfInStudentDatabase(QString emailToCheck, QString passwordToCheck){
    QSqlQuery loginQuery;
    QString email, password;
    loginQuery.prepare("SELECT * FROM studentLoginData WHERE studentEmail = :studentEmail AND studentPassword = :studentPassword");
    loginQuery.bindValue(":studentEmail", emailToCheck);
    loginQuery.bindValue(":studentPassword", passwordToCheck);
    loginQuery.exec();

    while(loginQuery.next()){
        email = loginQuery.value(1).toString();
        password = loginQuery.value(2).toString();
    }
    if(!email.isEmpty() && !password.isEmpty()){
        return true;
    }
    return false;
}

bool loginWindow::checkIfInProfDatabase(QString emailToCheck, QString passwordToCheck){
    QSqlQuery loginQuery;
    QString email, password;
    loginQuery.prepare("SELECT * FROM professorLoginData WHERE professorEmail = :professorEmail AND professorPassword = :professorPassword");
    loginQuery.bindValue(":professorEmail", emailToCheck);
    loginQuery.bindValue(":professorPassword", passwordToCheck);
    loginQuery.exec();

    while(loginQuery.next()){
        email = loginQuery.value(1).toString();
        password = loginQuery.value(2).toString();
    }
    if(!email.isEmpty() && !password.isEmpty()){
        return true;
    }
    return false;
}

QString emailLoginInput, passwordLoginInput;
bool studentStatus, professorStatus;

void loginWindow::on_loginButton_clicked()
{
    emailLoginInput = ui->emailLoginInput->text();
    passwordLoginInput = ui->passwordLoginInput->text();
    if (emailLoginInput.isEmpty() || passwordLoginInput.isEmpty()){
        QMessageBox::warning(this, tr("Login Verification"), tr("Provide all login details!"), QMessageBox::Ok);
    }
    else{
        if(!db.open()){
            QMessageBox::warning(this, tr("Database connection"), tr("Database is not connected!\nPlease try again later."), QMessageBox::Ok);
        }
        else{
            studentStatus = checkIfInStudentDatabase(emailLoginInput, passwordLoginInput);
            professorStatus = checkIfInProfDatabase(emailLoginInput, passwordLoginInput);
            ui->emailLoginInput->clear();
            ui->passwordLoginInput->clear();
            if(studentStatus){
                QMessageBox::information(this, tr("Login Confirmation?"), tr("Successfully logged in!"), QMessageBox::Ok);
                StudentMain.userEmail = emailLoginInput;
                StudentMain.userPassword = passwordLoginInput;
                this->hide();
                StudentMain.show();
                StudentMain.bole();
               // db.close();
            }
            else if(professorStatus){
                QMessageBox::information(this, tr("Login Confirmation?"), tr("Successfully logged in!"), QMessageBox::Ok);
                ProfessorMain.userEmail = emailLoginInput;
                ProfessorMain.userPassword = passwordLoginInput;
                this->hide();
                ProfessorMain.show();
                //db.close();

            }
            else{
                QMessageBox::warning(this, tr("Login Confirmation?"), tr("Account not in database!\nCheck your details or register a new account!"), QMessageBox::Ok);
            }
        }
    }
}

void loginWindow::on_registerButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
// LOGIN PAGE END

// REGISTER PAGE

bool loginWindow::checkEmail(QString email){
    static QRegularExpression regex("^[a-zA-Z0-9]+@([a-zA-Z]+.)+[a-zA-Z0-9]{2,4}$"); // characters/numbers @ 2-4*(characters/numbers with dots between)
    if(regex.match(email).hasMatch())
        return true;
    return false;
}

bool loginWindow::checkPassword(QString password){
    static QRegularExpression regex("^(?=.*?[A-Z])(?=.*?[a-z])(?=.*?[0-9])(?=.*?[#?!@$%^&*-]).{8,}$");  // min. 8 characters, 1 uppercase, 1 lowercase, 1 digit, 1 special character
    if(regex.match(password).hasMatch())
        return true;
    return false;
}

bool loginWindow::checkNames(QString name, QString surname){
    static QRegularExpression regex("^[a-zA-ZàáâäãåąčćęèéêëėįìíîïłńòóôöõøùúûüųūÿýżźñçčšžæÀÁÂÄÃÅĄĆČĖĘÈÉÊËÌÍÎÏĮŁŃÒÓÔÖÕØÙÚÛÜŲŪŸÝŻŹÑßÇŒÆČŠŽ∂ð ,.'-]+$");
    if(regex.match(name).hasMatch() && regex.match(surname).hasMatch())
        return true;
    return false;
}

QString nameRegisterInput, surnameRegisterInput, emailRegisterInput, passwordRegisterInput, majorRegisterInput; // add date of birth, different majors
bool studentRegisterRadioButton, professorRegisterRadioButton;

void loginWindow::on_registerToDatabaseButton_clicked() // enter/leaveEvent to hover dodać do hasła, maila itp
{
    nameRegisterInput = ui->nameRegisterInput->text();
    surnameRegisterInput = ui->surnameRegisterInput->text();
    studentRegisterRadioButton = ui->studentRegisterRadioButton->isChecked();
    professorRegisterRadioButton = ui->professorRegisterRadioButton->isChecked();
    emailRegisterInput = ui->emailRegisterInput->text();
    passwordRegisterInput = ui->passwordRegisterInput->text();
    majorRegisterInput = ui->majorRegisterCombo->currentText();

    if(nameRegisterInput.isEmpty() || surnameRegisterInput.isEmpty() || emailRegisterInput.isEmpty() || passwordRegisterInput.isEmpty() || !(studentRegisterRadioButton || professorRegisterRadioButton)){
        QMessageBox::warning(this, tr("Register Verification"), tr("Provide all register details!"), QMessageBox::Ok);
    }

    if(!checkNames(nameRegisterInput, surnameRegisterInput))
        QMessageBox::warning(this, tr("Register Verification"), tr("Name or Surname is incorect!"), QMessageBox::Ok);

    if(!checkEmail(emailRegisterInput))
        QMessageBox::warning(this, tr("Register Verification"), tr("Email is incorect!"), QMessageBox::Ok);

    if(!checkPassword(passwordRegisterInput))
        QMessageBox::warning(this, tr("Register Verification"), tr("Password is incorect!"), QMessageBox::Ok);


    if(checkNames(nameRegisterInput, surnameRegisterInput) && checkEmail(emailRegisterInput) && checkPassword(passwordRegisterInput) && (studentRegisterRadioButton || professorRegisterRadioButton)){
        if(!db.open())
            QMessageBox::warning(this, tr("Database connection"), tr("Database is not connected!\nPlease try again later."), QMessageBox::Ok);
        else{
            QSqlQuery accountQuery(db), loginDataQuery(db);
            if(studentRegisterRadioButton){
                if(checkIfInStudentDatabase(emailRegisterInput, passwordRegisterInput) || checkIfInProfDatabase(emailRegisterInput, passwordRegisterInput)){
                    QMessageBox::warning(this, tr("Register Form"), tr("Account already in database!"), QMessageBox::Ok);
                }
                else{
                    db.transaction();

                    loginDataQuery.prepare("INSERT INTO studentLoginData (studentEmail, studentPassword) VALUES (:studentEmail, :studentPassword)");
                    loginDataQuery.bindValue(":studentEmail", emailRegisterInput);
                    loginDataQuery.bindValue(":studentPassword", passwordRegisterInput);
                    loginDataQuery.exec();

                    accountQuery.prepare("INSERT INTO studentAccounts (studentName, studentSurname, studentMajor) VALUES (:studentName, :studentSurname, :studentMajor)");
                    accountQuery.bindValue(":studentName", nameRegisterInput);
                    accountQuery.bindValue(":studentSurname", surnameRegisterInput);
                    accountQuery.bindValue(":studentMajor", majorRegisterInput);
                    accountQuery.exec();

                    db.commit();
                }

            }
            else{
                if(checkIfInStudentDatabase(emailRegisterInput, passwordRegisterInput) || checkIfInProfDatabase(emailRegisterInput, passwordRegisterInput)){
                    QMessageBox::warning(this, tr("Register Form"), tr("Account already in database!"), QMessageBox::Ok);
                }
                else{
                    db.transaction();

                    loginDataQuery.prepare("INSERT INTO professorLoginData (professorEmail, professorPassword) VALUES (:professorEmail, :professorPassword)"); // check if email in database
                    loginDataQuery.bindValue(":professorEmail", emailRegisterInput);
                    loginDataQuery.bindValue(":professorPassword", passwordRegisterInput);
                    loginDataQuery.exec();

                    accountQuery.prepare("INSERT INTO professorAccounts (professorName, professorSurname, professorMajor) VALUES (:professorName, :professorSurname, :professorMajor)");
                    accountQuery.bindValue(":professorName", nameRegisterInput);
                    accountQuery.bindValue(":professorSurname", surnameRegisterInput);
                    accountQuery.bindValue(":professorMajor", majorRegisterInput);
                    accountQuery.exec();

                    db.commit();
                }

            }

        }

    }
    else{
        qDebug()<<"u done fucked up";
    }
}

void loginWindow::on_passwordRegisterHelpButton_clicked()
{
    QMessageBox::information(this, tr("Password Input"), tr("Password must contain:\n - minimum 8 characters\n - minimum 1 uppercase and 1 lowercase letter\n - minimum 1 digit\n - minimum 1 special charater (#?!@$%^&*-)"), QMessageBox::Ok);
}

void loginWindow::on_backToLoginPageButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Back to Login Page", "Are you sure you want to leave?\nAll details will be lost!", QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes){
        ui->nameRegisterInput->clear();
        ui->surnameRegisterInput->clear();
        ui->emailRegisterInput->clear();
        ui->passwordRegisterInput->clear();


        ui->stackedWidget->setCurrentIndex(0);
    }
}




// REGISTER PAGE END

