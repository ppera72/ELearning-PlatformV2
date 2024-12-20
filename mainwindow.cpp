#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <sstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::on_loginButton_clicked);
    connect(ui->registerButton, &QPushButton::clicked, this, &MainWindow::on_registerButton_clicked);
    connect(ui->registerToDatabaseButton, &QPushButton::clicked, this, &MainWindow::on_registerToDatabaseButton_clicked);
    connect(ui->backToLoginPageButton, &QPushButton::clicked, this, &MainWindow::on_backToLoginPageButton_clicked);
    connect(ui->exitButton, &QPushButton::clicked, this, &MainWindow::on_exitButton_clicked);
    connect(ui->SMLogOutButton, &QPushButton::clicked, this, &MainWindow::on_SMLogOutButton_clicked);
    connect(ui->PMLogOutButton, &QPushButton::clicked, this, &MainWindow::on_PMLogOutButton_clicked);


    UserData.readFromFile(UserData.studFileName, true);
    UserData.readFromFile(UserData.profFileName, false);
    for(auto&& a : UserData.studentData){
        qDebug()<<a;
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

// REGISTER PAGE

bool MainWindow::checkEmail(QString email){
    static QRegularExpression regex("^[a-zA-Z0-9]+@([a-zA-Z]+.)+[a-zA-Z0-9]{2,4}$"); // characters/numbers @ 2-4*(characters/numbers with dots between)
    if(regex.match(email).hasMatch())
        return true;
    return false;
}

bool MainWindow::checkPassword(QString password){
    static QRegularExpression regex("^(?=.*?[A-Z])(?=.*?[a-z])(?=.*?[0-9])(?=.*?[#?!@$%^&*-]).{8,}$");  // min. 8 characters, 1 uppercase, 1 lowercase, 1 digit, 1 special character
    if(regex.match(password).hasMatch())
        return true;
    return false;
}

bool MainWindow::checkNames(QString name, QString surname){
    static QRegularExpression regex("^[a-zA-ZàáâäãåąčćęèéêëėįìíîïłńòóôöõøùúûüųūÿýżźñçčšžæÀÁÂÄÃÅĄĆČĖĘÈÉÊËÌÍÎÏĮŁŃÒÓÔÖÕØÙÚÛÜŲŪŸÝŻŹÑßÇŒÆČŠŽ∂ð ,.'-]+$");
    if(regex.match(name).hasMatch() && regex.match(surname).hasMatch())
        return true;
    return false;
}

bool MainWindow::checkIfInDatabase(std::string email, std::vector<std::string> data){
    if(data.empty())
        return false;
    for(auto&& user: data){
        if(user.find(email) != std::string::npos){
            return true;
        }
    }
    return false;
}


QString nameRegisterInput, surnameRegisterInput, emailRegisterInput, passwordRegisterInput, majorRegisterInput, dateOBRegisterInput; // different majors
bool studentRegisterRadioButton, professorRegisterRadioButton;

void MainWindow::on_registerToDatabaseButton_clicked() // enter/leaveEvent to hover dodać do hasła, maila itp?
{
    nameRegisterInput = ui->nameRegisterInput->text();
    surnameRegisterInput = ui->surnameRegisterInput->text();
    studentRegisterRadioButton = ui->studentRegisterRadioButton->isChecked();
    professorRegisterRadioButton = ui->professorRegisterRadioButton->isChecked();
    emailRegisterInput = ui->emailRegisterInput->text();
    passwordRegisterInput = ui->passwordRegisterInput->text();
    majorRegisterInput = ui->majorRegisterCombo->currentText().replace(" ","");  //change that somehow
    dateOBRegisterInput = ui->dateOfBirthRegisterEdit->text();

    if(nameRegisterInput.isEmpty() || surnameRegisterInput.isEmpty() || emailRegisterInput.isEmpty() || passwordRegisterInput.isEmpty() || !(studentRegisterRadioButton || professorRegisterRadioButton)){
        QMessageBox::warning(this, tr("Register Verification"), tr("Provide all register details!"), QMessageBox::Ok);
    }
    else{
        if(!checkNames(nameRegisterInput, surnameRegisterInput))
            QMessageBox::warning(this, tr("Register Verification"), tr("Name or Surname is incorect!"), QMessageBox::Ok);

        if(!checkEmail(emailRegisterInput))
            QMessageBox::warning(this, tr("Register Verification"), tr("Email is incorect!"), QMessageBox::Ok);

        if(!checkPassword(passwordRegisterInput))
            QMessageBox::warning(this, tr("Register Verification"), tr("Password is incorect!"), QMessageBox::Ok);
    }

    if(checkNames(nameRegisterInput, surnameRegisterInput) && checkEmail(emailRegisterInput) && checkPassword(passwordRegisterInput) && (studentRegisterRadioButton || professorRegisterRadioButton)){
        std::stringstream helpMessage;
        std::string message;
        if(checkIfInDatabase(emailRegisterInput.toStdString(), UserData.studentData) || checkIfInDatabase(emailRegisterInput.toStdString(), UserData.professorData)){
            QMessageBox::information(this, "Registation information", "Account already in database!", QMessageBox::Ok);
        }
        else{
            if(studentRegisterRadioButton){
                UserData.lastID = UserData.getLastID(UserData.studentData);
                UserData.lastID += 1;
                helpMessage<<UserData.lastID<<";"<<nameRegisterInput.toStdString()<<";"<<surnameRegisterInput.toStdString()<<";"<<dateOBRegisterInput.toStdString()<<";"<<emailRegisterInput.toStdString()<<";"<<passwordRegisterInput.toStdString()<<";"<<majorRegisterInput.toStdString(); // change to include major code
                message = helpMessage.str();
                UserData.writeToFile(UserData.studFileName, message);
                UserData.studentData.push_back(message);
            }
            else{
                UserData.lastID = UserData.getLastID(UserData.professorData);
                UserData.lastID += 1;
                helpMessage<<UserData.lastID<<";"<<nameRegisterInput.toStdString()<<";"<<surnameRegisterInput.toStdString()<<";"<<dateOBRegisterInput.toStdString()<<";"<<emailRegisterInput.toStdString()<<";"<<passwordRegisterInput.toStdString()<<";"<<majorRegisterInput.toStdString(); // change to include major code
                message = helpMessage.str();
                UserData.writeToFile(UserData.profFileName, message);
                UserData.professorData.push_back(message);
            }
            QMessageBox::information(this, "Registation information", "Account added to database!", QMessageBox::Ok);
            ui->nameRegisterInput->clear();
            ui->surnameRegisterInput->clear();
            ui->emailRegisterInput->clear();
            ui->passwordRegisterInput->clear();
            ui->stackedWidget->setCurrentIndex(0);
        }
    }
    else{
        qDebug()<<"u done fucked up";
    }
}

void MainWindow::on_backToLoginPageButton_clicked()
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

// LOGIN PAGE

std::string emailLoginInput, passwordLoginInput;
bool studentStatus, professorStatus;

bool MainWindow::checkIfPassMatches(std::string email, std::string password, std::vector<std::string> data)
{
    if(data.empty())
        return false;
    for(auto&& user: data){
        if(user.find(email) != std::string::npos){
            if(user.find(password) != std::string::npos){
                return true;
            }
        }
    }
    return false;
}

void MainWindow::on_exitButton_clicked()
{
    MainWindow::close();
}

void MainWindow::on_loginButton_clicked()
{
    emailLoginInput = ui->emailLoginInput->text().toStdString();
    passwordLoginInput = ui->passwordLoginInput->text().toStdString();
    if (emailLoginInput.empty() || passwordLoginInput.empty()){
        QMessageBox::warning(this, tr("Login Verification"), tr("Provide all login details!"), QMessageBox::Ok);
    }
    else{
        bool ifStud = checkIfInDatabase(emailLoginInput, UserData.studentData);
        bool ifProf = checkIfInDatabase(emailLoginInput, UserData.professorData);
        if(!ifStud && !ifProf){
            QMessageBox::warning(this, tr("Login Attempt"), tr("Account not in database!\nCheck credetials or register a new account!"), QMessageBox::Ok);
        }
        if(ifStud){
            if(checkIfPassMatches(emailLoginInput, passwordLoginInput, UserData.studentData)){
                QMessageBox::information(this, "Login Attempt", "Succesfully logged in!", QMessageBox::Ok);
                ui->emailLoginInput->clear();
                ui->passwordLoginInput->clear();
                ui->stackedWidget->setCurrentIndex(2);
                // Student();
            }
            else{
                QMessageBox::warning(this, tr("Login Attempt"), tr("Wrong password!\nPlease try again!"), QMessageBox::Ok);
            }
        }
        if(ifProf){
            if(checkIfPassMatches(emailLoginInput, passwordLoginInput, UserData.professorData)){
                QMessageBox::information(this, "Login Attempt", "Succesfully logged in!", QMessageBox::Ok);
                ui->emailLoginInput->clear();
                ui->passwordLoginInput->clear();
                ui->stackedWidget->setCurrentIndex(3);
                // Professor();
            }
            else{
                QMessageBox::warning(this, tr("Login Attempt"), tr("Wrong password!\nPlease try again!"), QMessageBox::Ok);
            }
        }
    }
}

void MainWindow::on_registerButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
// LOGIN PAGE END


// STUDENT MAIN PAGE
void MainWindow::on_SMLogOutButton_clicked(){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Log Out", "Are you sure you want to log out?", QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes){
        // destructor of stud instance? / deleting him
        ui->stackedWidget->setCurrentIndex(0);
    }
}
// STUDENT MAIN PAGE END


// PROFESSOR MAIN PAGE
void MainWindow::on_PMLogOutButton_clicked(){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Log Out", "Are you sure you want to log out?", QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes){
        // destructor of prof instance? / deleting him
        ui->stackedWidget->setCurrentIndex(0);
    }
}
// PROFESSOR MAIN PAGE END


