#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <sstream>
#include <iostream>
#include <string>
#include <QInputDialog>
#include <algorithm>
#include <ctime>
#include <QButtonGroup>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(width(), height());

    setWindowFlag(Qt::WindowCloseButtonHint, false);
    setWindowFlag(Qt::WindowMaximizeButtonHint, false);

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

    connect(ui->ATAddQuestionsButton, &QPushButton::clicked, this, &MainWindow::on_ATAddQuestionsButton_clicked);
    connect(ui->ATAddTestButton, &QPushButton::clicked, this, &MainWindow::on_ATAddTestButton_clicked);
    connect(ui->ATCancelButton, &QPushButton::clicked, this, &MainWindow::on_ATCancelButton_clicked);
    connect(ui->ATAQAddQuestionsButton, &QPushButton::clicked, this, &MainWindow::on_ATAQAddQuestionsButton_clicked);
    connect(ui->ATAQConfirmQuestionsButton, &QPushButton::clicked, this, &MainWindow::on_ATAQConfirmQuestionsButton_clicked);
    connect(ui->ATAQCancelButton, &QPushButton::clicked, this, &MainWindow::on_ATAQCancelButton_clicked);

    connect(ui->SMStartSelectedTestButton, &QPushButton::clicked, this, &MainWindow::on_SMStartSelectedTestButton_clicked);
    connect(ui->SMStartSelectedAssignmentButton, &QPushButton::clicked, this, &MainWindow::on_SMStartSelectedAssignmentButton_clicked);

    connect(ui->SMSTACancelButton, &QPushButton::clicked, this, &MainWindow::on_SMSTACancelButton_clicked);
    connect(ui->SMSTASendAssignmentButton, &QPushButton::clicked, this, &MainWindow::on_SMSTASendAssignmentButton_clicked);
    connect(ui->SMSTAAddFileButton, &QPushButton::clicked, this, &MainWindow::on_SMSTAAddFileButton_clicked);

    connect(ui->PMGradeSelectedAssignmentButton, &QPushButton::clicked, this, &MainWindow::on_PMGradeSelectedAssignmentButton_clicked);
    connect(ui->PMGTACancelButton, &QPushButton::clicked, this, &MainWindow::on_PMGTACancelButton_clicked);
    connect(ui->PMGTAViewSelectedFileButton, &QPushButton::clicked, this, &MainWindow::on_PMGTAViewSelectedFileButton_clicked);
    connect(ui->PMGTAGradeTheAssignmentButton, &QPushButton::clicked, this, &MainWindow::on_PMGTAGradeTheAssignmentButton_clicked);
    connect(ui->PMGTAVTFBackButton, &QPushButton::clicked, this, &MainWindow::on_PMGTAVTFBackButton_clicked);



    ui->dateOfBirthRegisterEdit->setDate(QDate::currentDate());
    ui->AABeginDateDateEdit->setDate(QDate::currentDate());
    ui->AAEndDateDateEdit->setDate(QDate::currentDate());
    ui->ATBeginDateDateEdit->setDate(QDate::currentDate());
    ui->ATEndDateDateEdit->setDate(QDate::currentDate());


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


std::string emailLoginInput, passwordLoginInput; // for input

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
                qDebug()<<currentStudent.CourseCode();
                for(auto&& assignment : assignments.assignmentListForDisplay){
                    if(assignment.find(currentStudent.CourseCode()) != std::string::npos){
                        //qDebug()<<assignment;
                        ui->SMUpcomingAssignmentsList->addItem(QString::fromStdString(assignment));
                    }
                }
                for(auto&& test : assignments.testListForDisplay){
                    if(test.find(currentStudent.CourseCode()) != std::string::npos){
                        //qDebug()<<test;
                        ui->SMUpcomingTestsList->addItem(QString::fromStdString(test));
                    }
                }

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
    for(auto&& a : assignments.testList){
        qDebug()<<a;
    }
}
// PROFESSOR MAIN PAGE END

// ADD ASSIGNMENT PAGE
std::string AATitle, AADesc, AACourceCode;
Date AABeginDate, AAEndDate;


void MainWindow::on_AAAddButton_clicked(){
    AATitle = ui->AATitleInput->text().toStdString();
    AADesc = ui->AADesctiptionInput->text().toStdString();
    AACourceCode = ui->AACourceCodeCombo->currentText().right(6).mid(1, 4).toStdString();
    AABeginDate = ui->AABeginDateDateEdit->text().toStdString();
    AAEndDate = ui->AAEndDateDateEdit->text().toStdString();

    if(AATitle.empty()){
        QMessageBox::warning(this, "Adding Assignment", "Title of assignment is empty!\nPlease fill it!", QMessageBox::Ok);
    }
    else if(AADesc.empty()){
        QMessageBox::warning(this, "Adding Assignment", "Title of assignment is empty!\nPlease fill it!", QMessageBox::Ok);
    }

    else if(AAEndDate.compareDates(AABeginDate) == 1 || AAEndDate.compareDates(AABeginDate) == 0){
        QMessageBox::warning(this, "Adding Assignment", "End Date of assignment cannot be earlier than Begin Date!", QMessageBox::Ok);
    }

    if(!AATitle.empty() && !AADesc.empty() && AAEndDate.compareDates(AABeginDate) == -1){
        std::stringstream helpMessage;
        std::string message, assignmentToDisplay;
        assignments.assignmentLastID = assignments.getLastID(assignments.assignmentList);
        assignments.assignmentLastID += 1;
        helpMessage<<assignments.assignmentLastID<<';'<<AATitle<<';'<<AADesc<<';'<<AACourceCode<<';'<<AABeginDate.wholeDate()<<';'<<AAEndDate.wholeDate();
        message = helpMessage.str();
        assignments.addToFile(assignments.assignmentFile, message);
        assignments.assignmentList.push_back(message);

        helpMessage.str(std::string());
        helpMessage<<assignments.assignmentLastID<<';'<<AATitle<<';'<<AACourceCode;
        assignmentToDisplay = helpMessage.str();
        assignments.assignmentListForDisplay.push_back(assignmentToDisplay);
        assignments.addToFile(assignments.assignmentFileForDisplay, assignmentToDisplay);

        ui->AATitleInput->clear();
        ui->AADesctiptionInput->clear();
        QMessageBox::information(this, "Assignment Confirm", "Assignment added successfully!", QMessageBox::Ok);
        ui->stackedWidget->setCurrentIndex(3);
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
std::string ATTitle, ATCourceCode;  // for pre SM
int ATAQNumberOfQuestions;
QList<std::string> ATQuestions, ATAQQuestions, ATQuestionsFull, AAQuestionsForDisplay;
Date ATBeginDate, ATEndDate;

void MainWindow::on_ATAddTestButton_clicked()
{
    ATTitle = ui->ATTitleInput->text().toStdString();
    ATBeginDate = ui->ATBeginDateDateEdit->text().toStdString();
    ATEndDate = ui->ATEndDateDateEdit->text().toStdString();
    ATAQNumberOfQuestions = ui->ATAQNumberOfQuestionsSpinBox->value();
    ATCourceCode = ui->ATCourceCodeCombo->currentText().right(6).mid(1, 4).toStdString();

    if(ATTitle.empty()){
        QMessageBox::warning(this, "Adding Test", "Title of test is empty!\nPlease fill it!", QMessageBox::Ok);
    }

    else if(ATEndDate.compareDates(ATBeginDate) == 1 || ATEndDate.compareDates(ATBeginDate) == 0){
        QMessageBox::warning(this, "Adding Test", "End Date of test cannot be earlier than Begin Date!", QMessageBox::Ok);
    }

    else if(ATQuestions.empty()){
        QMessageBox::warning(this, "Adding Test", "Test does not contain any questions!\nPlease add them using ""Add Questions"" button!", QMessageBox::Ok);
    }

    if(!ATQuestions.empty() && !ATTitle.empty() && ATEndDate.compareDates(ATBeginDate) == -1){

        std::vector<std::string> writedTests = {};
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Adding Test", "Are you sure you want to add test?", QMessageBox::Yes|QMessageBox::No);
        if(reply == QMessageBox::Yes){
            for(auto&& a : ATQuestionsFull){
                assignments.addToFile(assignments.testFile, a);
                assignments.testList.push_back(a);
            }
            ATQuestionsFull.clear();
            for(auto&& a : assignments.testListForDisplay){
                std::vector<std::string> helpVec = assignments.getTestData(a);
                auto cnt = std::find(writedTests.begin(), writedTests.end(), a);
                /*for(auto&& b : writedTests){
                    qDebug()<<"WT: " + b;
                }
                qDebug()<<"a: " + a;*/
                if(cnt != writedTests.end()){
                    continue;
                    //qDebug()<<"not added";
                }
                else{
                    assignments.addToFile(assignments.testFileForDisplay, a);
                    writedTests.push_back(a);
                    //qDebug()<<"Added";
                }
            }
            writedTests.clear();
            assignments.testListForDisplay.clear(); // this causes issues when prof->add test->log out->stud and stud->log out->stud/ but not when stud->
            ui->ATTitleInput->clear();
            ui->ATQuestionsList->clear();
            ui->ATAQQuestionsList->clear();
            ui->stackedWidget->setCurrentIndex(3);
        }
    }
}

void MainWindow::on_ATAddQuestionsButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}
void MainWindow::on_ATCancelButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Cancel Test", "Are you sure you want to cancel adding test?\nAll the data will be lost!", QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes){
        ui->ATTitleInput->clear();
        ui->ATQuestionsList->clear();
        ui->stackedWidget->setCurrentIndex(3);
    }
}

void MainWindow::on_ATAQAddQuestionsButton_clicked()
{
    ATQuestions.clear();
    ATTitle = ui->ATTitleInput->text().toStdString();
    ATBeginDate = ui->ATBeginDateDateEdit->text().toStdString();
    ATEndDate = ui->ATEndDateDateEdit->text().toStdString();
    ATAQNumberOfQuestions = ui->ATAQNumberOfQuestionsSpinBox->value();
    ATCourceCode = ui->ATCourceCodeCombo->currentText().right(6).mid(1, 4).toStdString();

    std::string questionMain;
    if(ATAQNumberOfQuestions <= 0){
        QMessageBox::warning(this, "Adding Questions", "Number of questions cannot be less than 1!\nPlease choose another number!", QMessageBox::Ok);
    }

    for(int i = 0; i < ATAQNumberOfQuestions; i++){
        std::string helpMessage;
        std::string forDisplay;
        helpMessage = std::to_string(assignments.getLastID(assignments.testList) + 1) + ";";
        helpMessage += ATTitle + ";";
        bool okQ, okCA, okWA1, okWA2, okWA3;
        QString question = QInputDialog::getText(this, tr("Question"),tr(&"Question " [ (i + 1)]), QLineEdit::Normal,"Question", &okQ);
        if (okQ && !question.isEmpty())
        {
            helpMessage += ATCourceCode + ";";
            assignments.testListForDisplay.push_back(helpMessage);
            helpMessage += question.toStdString() + ";";
            questionMain = question.toStdString() + ';' + ATCourceCode;
            ATAQQuestions.push_back(helpMessage);
            ui->ATAQQuestionsList->addItem(QString::fromStdString(questionMain));
        }

        QString correctAnswer = QInputDialog::getText(this, tr("Correct Answer"),tr("Answer: "), QLineEdit::Normal,"Correct Answer", &okCA);
        if (okCA && !correctAnswer.isEmpty())
            helpMessage += correctAnswer.toStdString() + ";";

        QString wrongAnswer1 = QInputDialog::getText(this, tr("Wrong Answer"),tr("Wrong Answer 1:"), QLineEdit::Normal,"Wrong Answer", &okWA1);
        if (okWA1 && !wrongAnswer1.isEmpty())
            helpMessage += wrongAnswer1.toStdString() + ";";

        QString wrongAnswer2 = QInputDialog::getText(this, tr("Wrong Answer"),tr("Wrong Answer 2:"), QLineEdit::Normal,"Wrong Answer", &okWA2);
        if (okWA2 && !wrongAnswer2.isEmpty())
            helpMessage += wrongAnswer2.toStdString() + ";";

        QString wrongAnswer3 = QInputDialog::getText(this, tr("Wrong Answer"),tr("Wrong Answer 3:"), QLineEdit::Normal,"Wrong Answer", &okWA3);
        if (okWA3 && !wrongAnswer3.isEmpty())
            helpMessage += wrongAnswer3.toStdString() + ";";

        helpMessage += ATBeginDate.wholeDate() + ";" + ATEndDate.wholeDate();
        ATQuestionsFull.append(helpMessage);
    }
}

void MainWindow::on_ATAQConfirmQuestionsButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Add Test Questions", "Are you sure you want to add questions to test?", QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes){
        for(auto&& q : ATAQQuestions){
            ATQuestions.append(q);
            ui->ATQuestionsList->addItem(QString::fromStdString(q));
        }
        ATAQQuestions.clear();
        ui->stackedWidget->setCurrentIndex(4);
    }
}

void MainWindow::on_ATAQCancelButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Cancel Test Questions", "Are you sure you want to cancel adding questions to test?\nAll the data will be lost!", QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes){
        ui->ATAQNumberOfQuestionsSpinBox->setValue(0);
        ui->ATAQQuestionsList->clear();
        ui->stackedWidget->setCurrentIndex(3);
    }
}

// ADD TEST PAGE END

// SOLVE THE TEST PAGE
std::string selectedTest;
void MainWindow::on_SMStartSelectedTestButton_clicked()
{
    int correctAnswersScore = 0;
    std::string grade;
    std::string testTitle;
    // getting questions+answers

    selectedTest = ui->SMUpcomingTestsList->currentItem()->text().toStdString();
    std::vector<std::string> helpVec = assignments.getTestData(selectedTest);
    std::vector<std::string> helpQuestionsVec;
    int currentTestID = stoi(helpVec[0]);
    for(auto&& test:assignments.testList){
        helpVec.clear();
        helpVec = assignments.getTestData(test);
        if(stoi(helpVec[0]) == currentTestID){
            helpQuestionsVec.push_back(test);
            testTitle = helpVec[1];
        }
    }
    // solving
    ui->stackedWidget->setCurrentIndex(7);
    ui->SMSTTAllAnswersLabel->setText(QString::number(helpQuestionsVec.size()));
    for(auto&& test : helpQuestionsVec){
        ui->SMSTTCorrectAnswersLabel->setText(QString::number(correctAnswersScore));
        QEventLoop loop;
        std::vector<std::string> helpTestVec = assignments.getTestData(test);
        std::vector<std::string> answers = {helpTestVec[4], helpTestVec[5], helpTestVec[6], helpTestVec[7]};
        ui->SMSTTQuestionLabel->setText(QString::fromStdString(helpTestVec[3]));
        QRadioButton* ansButtons[] = {ui->SMSTTAnswer1Button, ui->SMSTTAnswer2Button, ui->SMSTTAnswer3Button, ui->SMSTTAnswer4Button};
        std::srand(std::time(nullptr));
        std::random_shuffle(answers.begin(), answers.end());  // shuffle answers
        for (int i = 0; i < 4; ++i) {
            ansButtons[i]->setText(QString::fromStdString(answers[i]));
        }

        QObject::connect(ui->SMSTTNextQuestionButton, &QPushButton::clicked, &loop, &QEventLoop::quit);  // wait for nextQuestionButton

        loop.exec();
        for(int i = 0; i < 4; i++){  // check answer
            if(ansButtons[i]->isChecked()){
                if(ansButtons[i]->text() == QString::fromStdString(helpTestVec[4])){
                    correctAnswersScore += 1;
                    break;
                }
                ansButtons[i]->setChecked(false);
            }

        }
        ui->SMSTTCorrectAnswersLabel->setText(QString::number(correctAnswersScore));
    }

    grade = UserData.assignAGrade(correctAnswersScore, helpQuestionsVec.size());

    std::string messBoxMessage = "You've completed this test\nYou've scored: " + std::to_string(correctAnswersScore) + " and got: " + grade;
    QMessageBox::information(this, "Test Completed!", QString::fromStdString(messBoxMessage), QMessageBox::Ok);
    std::stringstream message;
    message<<currentStudent.Id()<<";"<<testTitle<<";"<<grade;
    UserData.studentGrades.push_back(message.str());
    UserData.writeToFile(UserData.studGradesFileName, message.str());

    ui->SMCompletedTasksList->addItem(QString::fromStdString(selectedTest));
    ui->stackedWidget->setCurrentIndex(2);
    // delete form upcoming tests
}

// SOLVE THE TEST PAGE END

// SEND THE ASSIGNMENT PAGE
std::string selectedAssignment;
QList<std::string> filesForAssignment;
std::vector<std::string> helpAssignmentVec;
void MainWindow::on_SMStartSelectedAssignmentButton_clicked(){
    ui->stackedWidget->setCurrentIndex(8);

    // get assignment data
    selectedAssignment = ui->SMUpcomingAssignmentsList->currentItem()->text().toStdString();
    helpAssignmentVec = assignments.getTestData(selectedAssignment);
    int currentAssingmentID = stoi(helpAssignmentVec[0]);
    for(auto&& assignment : assignments.assignmentList){
        helpAssignmentVec = assignments.getTestData(assignment);
        if(stoi(helpAssignmentVec[0]) == currentAssingmentID){
            break;
        }
    }

    // display data
    ui->SMSTATitleLabel->setText(QString::fromStdString(helpAssignmentVec[1]));
    ui->SMSTADescriptionLabel->setText(QString::fromStdString(helpAssignmentVec[2]));

}

void MainWindow::on_SMSTACancelButton_clicked(){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Cancel Adding Assignment", "Are you sure you want to cancel adding assignemnt?\nAll the data will be lost!", QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes){
        ui->SMSTAFileList->clear();
        ui->stackedWidget->setCurrentIndex(2);
    }
}

void MainWindow::on_SMSTAAddFileButton_clicked(){
    QString filter = "Text File(*.txt)";
    QString fileName = QFileDialog::getOpenFileName(this, "Select assignment file.", "C:\\", filter);

    QList<QListWidgetItem *> list = ui->SMSTAFileList->findItems(fileName, Qt::MatchExactly);  // find all files with fileName name
    if(list.size() == 0){
        ui->SMSTAFileList->addItem(fileName);
        filesForAssignment.append(fileName.toStdString());
    }
    else{
        QMessageBox::warning(this, "Adding file error!", "File already in list!", QMessageBox::Ok);
    }
}

void MainWindow::on_SMSTASendAssignmentButton_clicked(){
    if(ui->SMSTAFileList->count() == 0){
        QMessageBox::warning(this, "Sending assignment error!", "File list is empty!\nPlease add a file to your assignment!", QMessageBox::Ok);
    }
    std::stringstream message;
    message<<helpAssignmentVec[0]<<";"<<helpAssignmentVec[1]<<";"<<currentStudent.Id()<<";";
    for(auto&& assignment : filesForAssignment){
        message<<assignment<<";";
    }
    std::string mess = message.str();
    mess.pop_back();
    assignments.assignmentToGrade.push_back(mess);
    assignments.addToFile(assignments.assignmentFileToGrade, mess);

    QMessageBox::information(this, "Sending Assignment", "Assignemnt Send Successfully!", QMessageBox::Ok);
    ui->SMSTAFileList->clear();
    ui->stackedWidget->setCurrentIndex(2);

    ui->SMCompletedTasksList->addItem(QString::fromStdString(selectedAssignment));
    ui->PMAssignmentsToGradeList->addItem(QString::fromStdString(selectedAssignment));
    // delete from upcoming
}

// SEND THE ASSIGNMENT PAGE END

// GRADE THE ASSIGNMENT PAGE
std::string selectedAssignmentToGrade;
std::vector<std::string> helpGradeAssignmentVec;

void MainWindow::on_PMGradeSelectedAssignmentButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

    // get assignment data
    selectedAssignmentToGrade = ui->PMAssignmentsToGradeList->currentItem()->text().toStdString();
    helpGradeAssignmentVec = assignments.getTestData(selectedAssignmentToGrade);
    int currentAssingmentID = stoi(helpGradeAssignmentVec[0]);
    for(auto&& assignment : assignments.assignmentList){
        helpGradeAssignmentVec = assignments.getTestData(assignment);
        if(stoi(helpGradeAssignmentVec[0]) == currentAssingmentID){
            break;
        }
    }


    // searching file names for assignment id
    int senderID = 0;
    for(auto&& entry : assignments.assignmentToGrade){
        qDebug()<<entry;
        std::vector<std::string> helpEntry = assignments.getTestData(entry);

        if(currentAssingmentID == stoi(helpEntry[0])){
            ui->PMGTAListOfFiles->addItem(QString::fromStdString(helpEntry[3]));
            senderID = stoi(helpEntry[2]);
            qDebug()<<senderID;
            ui->PMGTATitleDataLabel->setText(QString::fromStdString(helpEntry[1]));
        }
    }


    // searching user
    for(auto&& user : UserData.studentData){
        std::vector<std::string> currStudent = assignments.getTestData(user);
        if(stoi(currStudent[0]) == senderID){
            std::stringstream mess;
            mess<<currStudent[1]<<" "<<currStudent[2]<<", ID:"<<currStudent[0]<<", Cource Code: "<<currStudent[6];
            ui->PMGTASenderDataLabel->setText(QString::fromStdString(mess.str()));
        }
    }
}

void MainWindow::on_PMGTACancelButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Cancel Grading Assignment", "Are you sure you want to cancel grading the assignemnt?\nAll the data will be lost!", QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes){
        ui->stackedWidget->setCurrentIndex(3);
    }
}
void MainWindow::on_PMGTAViewSelectedFileButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
    QString selectedFile = ui->PMGTAListOfFiles->currentItem()->text();
    QFile file(selectedFile);

    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "File Error", "File is empty!", QMessageBox::Ok);
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->plainTextEdit->setPlainText(text);

    file.close();
}
void MainWindow::on_PMGTAGradeTheAssignmentButton_clicked()
{
    // messagebox with grades?
    // or earlier combo with grades?
}

void MainWindow::on_PMGTAVTFBackButton_clicked(){
    ui->stackedWidget->setCurrentIndex(9);
}
// GRADE THE ASSIGNMENT PAGE END


