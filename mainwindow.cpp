#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <algorithm>
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

    UserData.readFromFile(UserData.studFileName, true);
    for(auto&& a : UserData.studentData){
        qDebug()<<a;
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

// LOGIN PAGE

QString emailLoginInput, passwordLoginInput;
bool studentStatus, professorStatus;

void MainWindow::on_exitButton_clicked()
{
    MainWindow::close();
}



void MainWindow::on_loginButton_clicked()
{
    emailLoginInput = ui->emailLoginInput->text();
    passwordLoginInput = ui->passwordLoginInput->text();
    if (emailLoginInput.isEmpty() || passwordLoginInput.isEmpty()){
        QMessageBox::warning(this, tr("Login Verification"), tr("Provide all login details!"), QMessageBox::Ok);
    }

    /*else{

    }*/
}

void MainWindow::on_registerButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
// LOGIN PAGE END

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
    if (std::find(data.begin(), data.end(), email) != data.end())
        return true;
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
    majorRegisterInput = ui->majorRegisterCombo->currentText().replace(" ","");
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
        qDebug()<<"gitra";
        QMessageBox::information(this, "Registation information", "Account added to database!", QMessageBox::Ok);
        std::stringstream helpMessage;
        std::string message;
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
        ui->stackedWidget->setCurrentIndex(0);
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

