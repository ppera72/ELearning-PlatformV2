#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <sstream>
#include <iostream>
#include <string>
#include <QInputDialog>


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
    connect(ui->SMChangeEmailButton, &QPushButton::clicked, this, &MainWindow::on_SMChangeEmailButton_clicked);
    connect(ui->SMChangePasswordButton, &QPushButton::clicked, this, &MainWindow::on_SMChangePasswordButton_clicked);
    connect(ui->SMChangeNameButton, &QPushButton::clicked, this, &MainWindow::on_SMChangeNameButton_clicked);
    connect(ui->SMChangeSurnameButton, &QPushButton::clicked, this, &MainWindow::on_SMChangeSurnameButton_clicked);
    connect(ui->PMAddNewAssignmentButton, &QPushButton::clicked, this, &MainWindow::on_PMAddNewAssignment_clicked);
    connect(ui->PMAddNewTestButton, &QPushButton::clicked, this, &MainWindow::on_PMAddNewTest_clicked);
    connect(ui->AAAddButton, &QPushButton::clicked, this, &MainWindow::on_AAAddButton_clicked);
    connect(ui->AACancelButton, &QPushButton::clicked, this, &MainWindow::on_AACancelButton_clicked);


    UserData.readFromFile(UserData.studFileName, true);
    UserData.readFromFile(UserData.profFileName, false);
    assignments.loadData();

    for(auto&& a : UserData.studentData){
        qDebug()<<a;
    }
    for(auto&& a : UserData.professorData){
        qDebug()<<a;
    }

    qDebug()<<"ass: start";
    for(auto&& a : assignments.assignmentList){
        qDebug()<<a;
    }

    qDebug()<<"test: start";
    for(auto&& a : assignments.testList){
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


QString nameRegisterInput, surnameRegisterInput, emailRegisterInput, passwordRegisterInput, studentMajorRegisterInput, dateOBRegisterInput, profSpecRegisterInput, profTitleRegisterInput;
bool studentRegisterRadioButton, professorRegisterRadioButton;

void MainWindow::on_registerToDatabaseButton_clicked()
{
    nameRegisterInput = ui->nameRegisterInput->text();
    surnameRegisterInput = ui->surnameRegisterInput->text();
    studentRegisterRadioButton = ui->studentRegisterRadioButton->isChecked();
    professorRegisterRadioButton = ui->professorRegisterRadioButton->isChecked();
    emailRegisterInput = ui->emailRegisterInput->text();
    passwordRegisterInput = ui->passwordRegisterInput->text();
    studentMajorRegisterInput = ui->studentMajorRegisterCombo->currentText().right(6).mid(1, 4); // getting code in brackets + removing brackets
    profSpecRegisterInput = ui->professorSpecRegisterCombo->currentText().right(6).mid(1, 4); ;  // same as ^
    profTitleRegisterInput = ui->professorTitleRegisterCombo->currentText();
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
                helpMessage<<UserData.lastID<<";"<<nameRegisterInput.toStdString()<<";"<<surnameRegisterInput.toStdString()<<";"<<dateOBRegisterInput.toStdString()<<";"<<emailRegisterInput.toStdString()<<";"<<passwordRegisterInput.toStdString()<<";"<<studentMajorRegisterInput.toStdString();
                message = helpMessage.str();
                UserData.writeToFile(UserData.studFileName, message);
                UserData.studentData.push_back(message);
            }
            else{
                UserData.lastID = UserData.getLastID(UserData.professorData);
                UserData.lastID += 1;
                helpMessage<<UserData.lastID<<";"<<nameRegisterInput.toStdString()<<";"<<surnameRegisterInput.toStdString()<<";"<<dateOBRegisterInput.toStdString()<<";"<<emailRegisterInput.toStdString()<<";"<<passwordRegisterInput.toStdString()<<";"<<profTitleRegisterInput.toStdString()<<";"<<profSpecRegisterInput.toStdString();
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
        QMessageBox::warning(this, tr("Register Attempt"), tr("Something went wrong!\nTry Again!"), QMessageBox::Ok);
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

                // pre SM:
                currentStudent = getStudData(UserData.studentData);
                ui->SMNameLabel->setText(QString::fromStdString(currentStudent.Name()));


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

                // pre PM:
                currentProfessor = getProfData(UserData.professorData);
                ui->PMNameLabel->setText(QString::fromStdString(currentProfessor.Name()));

            }
            else{
                QMessageBox::warning(this, tr("Login Attempt"), tr("Wrong password!\nPlease try again!"), QMessageBox::Ok);
            }
        }
    }
}

Student MainWindow::getStudData(std::vector<std::string> data){
    for(auto&& user: data){
        if(user.find(emailLoginInput) != std::string::npos){
            std::vector<std::string> helpVec;
            size_t pos = 0;
            size_t prev = 0;
            while((pos = user.find(';', prev)) != std::string::npos){
                helpVec.push_back(user.substr(prev, pos - prev));
                prev = pos + 1;
            }
            helpVec.push_back(user.substr(prev));

            int id = stoi(helpVec[0]);
            std::string name = helpVec[1];
            std::string surname = helpVec[2];
            Date dateOfBirth(helpVec[3]);
            std::string email = helpVec[4];
            std::string password = helpVec[5];
            std::string courseCode = helpVec[6];

            Student stud(id, name, surname, dateOfBirth, email, password, courseCode);
            return stud;
        }
    }
    return Student();
}

Professor MainWindow::getProfData(std::vector<std::string> data){
    for(auto&& user: data){
        if(user.find(emailLoginInput) != std::string::npos){
            std::vector<std::string> helpVec;
            size_t pos = 0;
            size_t prev = 0;
            while((pos = user.find(';', prev)) != std::string::npos){
                helpVec.push_back(user.substr(prev, pos - prev));
                prev = pos + 1;
            }
            helpVec.push_back(user.substr(prev));

            int id = stoi(helpVec[0]);
            std::string name = helpVec[1];
            std::string surname = helpVec[2];
            Date dateOfBirth(helpVec[3]);
            std::string email = helpVec[4];
            std::string password = helpVec[5];
            std::string title = helpVec[6];
            std::string sciSpec = helpVec[7];

            Professor prof(id, name, surname, dateOfBirth, email, password, title, sciSpec);
            return prof;
        }
    }
    return Professor();
}

void MainWindow::on_registerButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
// LOGIN PAGE END

// STUDENT MAIN PAGE

void MainWindow::on_SMChangeEmailButton_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Details Change"),tr("Your new email:"), QLineEdit::Normal,QString::fromStdString(currentStudent.Email()), &ok);
    if (ok && !text.isEmpty())
    {
        if(checkEmail(text) && !checkIfInDatabase(text.toStdString(), UserData.studentData) && !checkIfInDatabase(text.toStdString(), UserData.professorData)){
            currentStudent.Email(text.toStdString());
            QMessageBox::information(this, "Details Change", "Email has been successfully changed!", QMessageBox::Ok);
        }
        else{
            QMessageBox::warning(this, "Incorect input data", "Email is incorrect!\nPlease try again!", QMessageBox::Ok);
        }
    }
}

void MainWindow::on_SMChangePasswordButton_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Change Details"),tr("Your new password:"), QLineEdit::Normal,QString::fromStdString(currentStudent.Password()), &ok);
    if (ok && !text.isEmpty())
        qDebug()<<text;
}

void MainWindow::on_SMChangeNameButton_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Change Details"),tr("Your new name:"), QLineEdit::Normal,QString::fromStdString(currentStudent.Name()), &ok);
    if (ok && !text.isEmpty())
        qDebug()<<text;
}

void MainWindow::on_SMChangeSurnameButton_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Change Details"),tr("Your new surname:"), QLineEdit::Normal,QString::fromStdString(currentStudent.Surname()), &ok);
    if (ok && !text.isEmpty())
        qDebug()<<text;
}

void MainWindow::on_SMLogOutButton_clicked(){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Log Out", "Are you sure you want to log out?", QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes){
        for(auto&& user : UserData.studentData){
            if(user.find(std::to_string(currentStudent.Id())) != std::string::npos){
                std::stringstream helpMessage;
                std::string message;
                helpMessage<<currentStudent.Id()<<";"<<currentStudent.Name()<<";"<<currentStudent.Surname()<<";"<<currentStudent.dateOfBirth.wholeDate()<<";"<<currentStudent.Email()<<";"<<currentStudent.Password()<<";"<<currentStudent.CourseCode();
                message = helpMessage.str();
                UserData.studentData[currentStudent.Id() - 1] = message;
                UserData.clearFile(UserData.studFileName);
                for(auto&& a : UserData.studentData){
                    UserData.writeToFile(UserData.studFileName, a);
                }
                break;
            }
        }
        ui->stackedWidget->setCurrentIndex(0);
    }
}
// STUDENT MAIN PAGE END

// PROFESSOR MAIN PAGE
void MainWindow::on_PMLogOutButton_clicked(){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Log Out", "Are you sure you want to log out?", QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes){
        for(auto&& user : UserData.professorData){
            if(user.find(std::to_string(currentProfessor.Id())) != std::string::npos){
                std::stringstream helpMessage;
                std::string message;
                helpMessage<<currentProfessor.Id()<<";"<<currentProfessor.Name()<<";"<<currentProfessor.Surname()<<";"<<currentProfessor.dateOfBirth.wholeDate()<<";"<<currentProfessor.Email()<<";"<<currentProfessor.Password()<<";"<<currentProfessor.Title()<<";"<<currentProfessor.SciSpec();
                message = helpMessage.str();
                UserData.professorData[currentProfessor.Id() - 1] = message;
                UserData.clearFile(UserData.profFileName);
                for(auto&& a : UserData.professorData){
                    UserData.writeToFile(UserData.profFileName, a);
                }
                break;
            }
        }
        ui->stackedWidget->setCurrentIndex(0);
    }
}

void MainWindow::on_PMAddNewAssignment_clicked(){
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_PMAddNewTest_clicked(){
    ui->stackedWidget->setCurrentIndex(4);
}
// PROFESSOR MAIN PAGE END

// ADD ASSIGNMENT PAGE
std::string AATitle, AADesc, AACourceCode;
Date AABeginDate, AAEndDate;

void MainWindow::on_AAAddButton_clicked(){
    AATitle = ui->AATitleInput->text().toStdString();
    AADesc = ui->AADesctiptionInput->text().toStdString();
    AACourceCode = ui->AACourceCodeCombo->currentText().toStdString();
    AABeginDate = ui->AABeginDateDateEdit->text().toStdString();
    AAEndDate = ui->AAEndDateDateEdit->text().toStdString();

    if(AATitle.empty()){
        QMessageBox::warning(this, "Adding Assignment", "Title of assignment is empty!\nPlease fill it!", QMessageBox::Ok);
    }
    if(AADesc.empty()){
        QMessageBox::warning(this, "Adding Assignment", "Title of assignment is empty!\nPlease fill it!", QMessageBox::Ok);
    }

    // check if endDate > beginDate

    if(!AATitle.empty() && !AADesc.empty()){
        std::stringstream helpMessage;
        std::string message;
        assignments.assignmentLastID = assignments.getLastID(assignments.assignmentList);
        assignments.assignmentLastID += 1;
        helpMessage<<assignments.assignmentLastID<<';'<<AATitle<<';'<<AADesc<<';'<<AACourceCode<<';'<<AABeginDate.wholeDate()<<';'<<AAEndDate.wholeDate();
        message = helpMessage.str();
        assignments.addAssginment(assignments.assignmentFile, message);
        assignments.assignmentList.push_back(message);

        ui->AATitleInput->clear();
        ui->AADesctiptionInput->clear();
        QMessageBox::information(this, "Assignment Confirm", "Assignment added successfully!", QMessageBox::Ok);
    }
}
void MainWindow::on_AACancelButton_clicked(){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Cancel Assignment", "Are you sure you want to cancel adding assignment?\nAll the data will be lost!", QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes){
        ui->AATitleInput->clear();
        ui->AADesctiptionInput->clear();
        ui->stackedWidget->setCurrentIndex(3);
    }
}
// ADD ASSIGNMENT PAGE END

// ADD TEST PAGE

// ADD TEST PAGE END


