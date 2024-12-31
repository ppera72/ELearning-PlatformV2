/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *loginPage;
    QPushButton *registerButton;
    QLabel *emailLoginLabel;
    QLabel *passwordLoginLabel;
    QLineEdit *emailLoginInput;
    QLineEdit *passwordLoginInput;
    QPushButton *loginButton;
    QPushButton *exitButton;
    QWidget *registerWidnow;
    QPushButton *backToLoginPageButton;
    QLabel *surnameRegisterLabel;
    QLineEdit *emailRegisterInput;
    QLabel *studentMajorRegisterLabel;
    QLabel *fullNameRegisterLabel;
    QLineEdit *surnameRegisterInput;
    QLabel *emailRegisterLabel;
    QLineEdit *passwordRegisterInput;
    QLabel *passwordRegisterLabel;
    QPushButton *registerToDatabaseButton;
    QDateEdit *dateOfBirthRegisterEdit;
    QLabel *dateOfBirthRegisterLabel;
    QRadioButton *studentRegisterRadioButton;
    QRadioButton *professorRegisterRadioButton;
    QLineEdit *nameRegisterInput;
    QComboBox *studentMajorRegisterCombo;
    QComboBox *professorTitleRegisterCombo;
    QLabel *professorSpecRegisterLabel;
    QLabel *professorTitleRegisterLabel;
    QComboBox *professorSpecRegisterCombo;
    QWidget *studentMainPage;
    QPushButton *SMLogOutButton;
    QLabel *SMWelcomeLabel;
    QLabel *SMNameLabel;
    QPushButton *SMChangeEmailButton;
    QPushButton *SMChangePasswordButton;
    QPushButton *SMChangeNameButton;
    QPushButton *SMChangeSurnameButton;
    QLabel *SMUpcomingTasksLabel;
    QComboBox *SMUpcomingTasksCombo;
    QWidget *professorMainPage;
    QLabel *label_2;
    QPushButton *PMLogOutButton;
    QLabel *PMNameLabel;
    QPushButton *PMChangeEmailButton;
    QLabel *PMWelcomeLabel;
    QPushButton *PMChangePasswordButton;
    QPushButton *PMChangeSurnameButton;
    QPushButton *PMChangeNameButton;
    QPushButton *PMAddNewAssignmentButton;
    QPushButton *PMAddNewTestButton;
    QWidget *addTestPage;
    QLabel *ATLabel;
    QLabel *ATTitleLabel;
    QLabel *ATEndDateLabel;
    QLineEdit *ATTitleInput;
    QDateEdit *ATEndDateDateEdit;
    QLabel *ATBeginDateLabel;
    QDateEdit *ATBeginDateDateEdit;
    QLabel *ATCourceCodeLabel;
    QLabel *ATQuestionsLabel;
    QPushButton *ATAddQuestionsButton;
    QPushButton *ATAddTestButton;
    QPushButton *ATCancelButton;
    QListWidget *ATQuestionsList;
    QComboBox *ATCourceCodeCombo;
    QWidget *ATAddQuestionsPage;
    QLabel *ATAQLabel;
    QLabel *ATAQNumberOfQuestionsLabel;
    QSpinBox *ATAQNumberOfQuestionsSpinBox;
    QPushButton *ATAQAddQuestionsButton;
    QListWidget *ATAQQuestionsList;
    QPushButton *ATAQConfirmQuestionsButton;
    QPushButton *ATAQCancelButton;
    QLabel *ATAQQuestionsLabel;
    QWidget *addAssignmentPage;
    QLabel *AALabel;
    QLabel *AATitleLabel;
    QLabel *AADescriptionLabel;
    QLabel *AABeginDateLabel;
    QLabel *AAEndDateLabel;
    QDateEdit *AABeginDateDateEdit;
    QDateEdit *AAEndDateDateEdit;
    QLineEdit *AATitleInput;
    QLineEdit *AADesctiptionInput;
    QPushButton *AAAddButton;
    QPushButton *AACancelButton;
    QLabel *AACourceCodeLabel;
    QComboBox *AACourceCodeCombo;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, -20, 800, 621));
        stackedWidget->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);
        loginPage = new QWidget();
        loginPage->setObjectName("loginPage");
        registerButton = new QPushButton(loginPage);
        registerButton->setObjectName("registerButton");
        registerButton->setGeometry(QRect(590, 60, 80, 24));
        emailLoginLabel = new QLabel(loginPage);
        emailLoginLabel->setObjectName("emailLoginLabel");
        emailLoginLabel->setGeometry(QRect(270, 270, 49, 16));
        passwordLoginLabel = new QLabel(loginPage);
        passwordLoginLabel->setObjectName("passwordLoginLabel");
        passwordLoginLabel->setGeometry(QRect(250, 310, 61, 20));
        emailLoginInput = new QLineEdit(loginPage);
        emailLoginInput->setObjectName("emailLoginInput");
        emailLoginInput->setGeometry(QRect(330, 270, 191, 24));
        passwordLoginInput = new QLineEdit(loginPage);
        passwordLoginInput->setObjectName("passwordLoginInput");
        passwordLoginInput->setGeometry(QRect(330, 310, 191, 24));
        passwordLoginInput->setEchoMode(QLineEdit::EchoMode::Password);
        loginButton = new QPushButton(loginPage);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(340, 380, 101, 41));
        loginButton->setCheckable(false);
        exitButton = new QPushButton(loginPage);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(590, 510, 80, 24));
        stackedWidget->addWidget(loginPage);
        registerWidnow = new QWidget();
        registerWidnow->setObjectName("registerWidnow");
        backToLoginPageButton = new QPushButton(registerWidnow);
        backToLoginPageButton->setObjectName("backToLoginPageButton");
        backToLoginPageButton->setGeometry(QRect(400, 480, 131, 24));
        surnameRegisterLabel = new QLabel(registerWidnow);
        surnameRegisterLabel->setObjectName("surnameRegisterLabel");
        surnameRegisterLabel->setGeometry(QRect(108, 130, 61, 20));
        emailRegisterInput = new QLineEdit(registerWidnow);
        emailRegisterInput->setObjectName("emailRegisterInput");
        emailRegisterInput->setGeometry(QRect(210, 170, 113, 24));
        studentMajorRegisterLabel = new QLabel(registerWidnow);
        studentMajorRegisterLabel->setObjectName("studentMajorRegisterLabel");
        studentMajorRegisterLabel->setEnabled(true);
        studentMajorRegisterLabel->setGeometry(QRect(50, 350, 91, 20));
        fullNameRegisterLabel = new QLabel(registerWidnow);
        fullNameRegisterLabel->setObjectName("fullNameRegisterLabel");
        fullNameRegisterLabel->setGeometry(QRect(108, 80, 61, 20));
        surnameRegisterInput = new QLineEdit(registerWidnow);
        surnameRegisterInput->setObjectName("surnameRegisterInput");
        surnameRegisterInput->setGeometry(QRect(200, 120, 113, 24));
        emailRegisterLabel = new QLabel(registerWidnow);
        emailRegisterLabel->setObjectName("emailRegisterLabel");
        emailRegisterLabel->setGeometry(QRect(108, 180, 61, 20));
        passwordRegisterInput = new QLineEdit(registerWidnow);
        passwordRegisterInput->setObjectName("passwordRegisterInput");
        passwordRegisterInput->setGeometry(QRect(210, 220, 113, 24));
        passwordRegisterInput->setEchoMode(QLineEdit::EchoMode::Password);
        passwordRegisterLabel = new QLabel(registerWidnow);
        passwordRegisterLabel->setObjectName("passwordRegisterLabel");
        passwordRegisterLabel->setGeometry(QRect(108, 220, 61, 20));
        registerToDatabaseButton = new QPushButton(registerWidnow);
        registerToDatabaseButton->setObjectName("registerToDatabaseButton");
        registerToDatabaseButton->setGeometry(QRect(240, 480, 80, 24));
        dateOfBirthRegisterEdit = new QDateEdit(registerWidnow);
        dateOfBirthRegisterEdit->setObjectName("dateOfBirthRegisterEdit");
        dateOfBirthRegisterEdit->setGeometry(QRect(210, 260, 110, 25));
        dateOfBirthRegisterLabel = new QLabel(registerWidnow);
        dateOfBirthRegisterLabel->setObjectName("dateOfBirthRegisterLabel");
        dateOfBirthRegisterLabel->setGeometry(QRect(100, 270, 71, 16));
        studentRegisterRadioButton = new QRadioButton(registerWidnow);
        studentRegisterRadioButton->setObjectName("studentRegisterRadioButton");
        studentRegisterRadioButton->setGeometry(QRect(110, 310, 91, 22));
        professorRegisterRadioButton = new QRadioButton(registerWidnow);
        professorRegisterRadioButton->setObjectName("professorRegisterRadioButton");
        professorRegisterRadioButton->setGeometry(QRect(270, 310, 91, 22));
        nameRegisterInput = new QLineEdit(registerWidnow);
        nameRegisterInput->setObjectName("nameRegisterInput");
        nameRegisterInput->setGeometry(QRect(200, 70, 113, 24));
        studentMajorRegisterCombo = new QComboBox(registerWidnow);
        studentMajorRegisterCombo->addItem(QString());
        studentMajorRegisterCombo->addItem(QString());
        studentMajorRegisterCombo->addItem(QString());
        studentMajorRegisterCombo->addItem(QString());
        studentMajorRegisterCombo->addItem(QString());
        studentMajorRegisterCombo->addItem(QString());
        studentMajorRegisterCombo->addItem(QString());
        studentMajorRegisterCombo->addItem(QString());
        studentMajorRegisterCombo->addItem(QString());
        studentMajorRegisterCombo->setObjectName("studentMajorRegisterCombo");
        studentMajorRegisterCombo->setGeometry(QRect(50, 380, 231, 24));
        professorTitleRegisterCombo = new QComboBox(registerWidnow);
        professorTitleRegisterCombo->addItem(QString());
        professorTitleRegisterCombo->addItem(QString());
        professorTitleRegisterCombo->addItem(QString());
        professorTitleRegisterCombo->addItem(QString());
        professorTitleRegisterCombo->addItem(QString());
        professorTitleRegisterCombo->setObjectName("professorTitleRegisterCombo");
        professorTitleRegisterCombo->setGeometry(QRect(590, 380, 121, 24));
        professorSpecRegisterLabel = new QLabel(registerWidnow);
        professorSpecRegisterLabel->setObjectName("professorSpecRegisterLabel");
        professorSpecRegisterLabel->setGeometry(QRect(330, 350, 131, 16));
        professorTitleRegisterLabel = new QLabel(registerWidnow);
        professorTitleRegisterLabel->setObjectName("professorTitleRegisterLabel");
        professorTitleRegisterLabel->setGeometry(QRect(590, 350, 81, 16));
        professorSpecRegisterCombo = new QComboBox(registerWidnow);
        professorSpecRegisterCombo->addItem(QString());
        professorSpecRegisterCombo->addItem(QString());
        professorSpecRegisterCombo->addItem(QString());
        professorSpecRegisterCombo->addItem(QString());
        professorSpecRegisterCombo->addItem(QString());
        professorSpecRegisterCombo->addItem(QString());
        professorSpecRegisterCombo->addItem(QString());
        professorSpecRegisterCombo->addItem(QString());
        professorSpecRegisterCombo->addItem(QString());
        professorSpecRegisterCombo->setObjectName("professorSpecRegisterCombo");
        professorSpecRegisterCombo->setGeometry(QRect(330, 380, 231, 24));
        stackedWidget->addWidget(registerWidnow);
        studentMainPage = new QWidget();
        studentMainPage->setObjectName("studentMainPage");
        SMLogOutButton = new QPushButton(studentMainPage);
        SMLogOutButton->setObjectName("SMLogOutButton");
        SMLogOutButton->setGeometry(QRect(110, 270, 80, 24));
        SMWelcomeLabel = new QLabel(studentMainPage);
        SMWelcomeLabel->setObjectName("SMWelcomeLabel");
        SMWelcomeLabel->setGeometry(QRect(70, 110, 61, 16));
        SMNameLabel = new QLabel(studentMainPage);
        SMNameLabel->setObjectName("SMNameLabel");
        SMNameLabel->setGeometry(QRect(140, 110, 49, 16));
        SMChangeEmailButton = new QPushButton(studentMainPage);
        SMChangeEmailButton->setObjectName("SMChangeEmailButton");
        SMChangeEmailButton->setGeometry(QRect(30, 170, 111, 24));
        SMChangePasswordButton = new QPushButton(studentMainPage);
        SMChangePasswordButton->setObjectName("SMChangePasswordButton");
        SMChangePasswordButton->setGeometry(QRect(150, 170, 111, 24));
        SMChangeNameButton = new QPushButton(studentMainPage);
        SMChangeNameButton->setObjectName("SMChangeNameButton");
        SMChangeNameButton->setGeometry(QRect(30, 220, 111, 24));
        SMChangeSurnameButton = new QPushButton(studentMainPage);
        SMChangeSurnameButton->setObjectName("SMChangeSurnameButton");
        SMChangeSurnameButton->setGeometry(QRect(150, 220, 111, 24));
        SMUpcomingTasksLabel = new QLabel(studentMainPage);
        SMUpcomingTasksLabel->setObjectName("SMUpcomingTasksLabel");
        SMUpcomingTasksLabel->setGeometry(QRect(480, 110, 101, 16));
        SMUpcomingTasksCombo = new QComboBox(studentMainPage);
        SMUpcomingTasksCombo->setObjectName("SMUpcomingTasksCombo");
        SMUpcomingTasksCombo->setGeometry(QRect(480, 150, 281, 24));
        stackedWidget->addWidget(studentMainPage);
        professorMainPage = new QWidget();
        professorMainPage->setObjectName("professorMainPage");
        label_2 = new QLabel(professorMainPage);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 470, 49, 16));
        PMLogOutButton = new QPushButton(professorMainPage);
        PMLogOutButton->setObjectName("PMLogOutButton");
        PMLogOutButton->setGeometry(QRect(120, 280, 80, 24));
        PMNameLabel = new QLabel(professorMainPage);
        PMNameLabel->setObjectName("PMNameLabel");
        PMNameLabel->setGeometry(QRect(150, 110, 49, 16));
        PMChangeEmailButton = new QPushButton(professorMainPage);
        PMChangeEmailButton->setObjectName("PMChangeEmailButton");
        PMChangeEmailButton->setGeometry(QRect(40, 170, 111, 24));
        PMWelcomeLabel = new QLabel(professorMainPage);
        PMWelcomeLabel->setObjectName("PMWelcomeLabel");
        PMWelcomeLabel->setGeometry(QRect(80, 110, 61, 16));
        PMChangePasswordButton = new QPushButton(professorMainPage);
        PMChangePasswordButton->setObjectName("PMChangePasswordButton");
        PMChangePasswordButton->setGeometry(QRect(160, 170, 111, 24));
        PMChangeSurnameButton = new QPushButton(professorMainPage);
        PMChangeSurnameButton->setObjectName("PMChangeSurnameButton");
        PMChangeSurnameButton->setGeometry(QRect(160, 220, 111, 24));
        PMChangeNameButton = new QPushButton(professorMainPage);
        PMChangeNameButton->setObjectName("PMChangeNameButton");
        PMChangeNameButton->setGeometry(QRect(40, 220, 111, 24));
        PMAddNewAssignmentButton = new QPushButton(professorMainPage);
        PMAddNewAssignmentButton->setObjectName("PMAddNewAssignmentButton");
        PMAddNewAssignmentButton->setGeometry(QRect(550, 140, 141, 24));
        PMAddNewTestButton = new QPushButton(professorMainPage);
        PMAddNewTestButton->setObjectName("PMAddNewTestButton");
        PMAddNewTestButton->setGeometry(QRect(550, 200, 141, 24));
        stackedWidget->addWidget(professorMainPage);
        addTestPage = new QWidget();
        addTestPage->setObjectName("addTestPage");
        ATLabel = new QLabel(addTestPage);
        ATLabel->setObjectName("ATLabel");
        ATLabel->setGeometry(QRect(260, 50, 241, 51));
        ATLabel->setBaseSize(QSize(0, 0));
        QFont font;
        font.setPointSize(28);
        ATLabel->setFont(font);
        ATTitleLabel = new QLabel(addTestPage);
        ATTitleLabel->setObjectName("ATTitleLabel");
        ATTitleLabel->setGeometry(QRect(50, 120, 51, 31));
        QFont font1;
        font1.setPointSize(14);
        ATTitleLabel->setFont(font1);
        ATEndDateLabel = new QLabel(addTestPage);
        ATEndDateLabel->setObjectName("ATEndDateLabel");
        ATEndDateLabel->setGeometry(QRect(440, 240, 81, 31));
        ATEndDateLabel->setFont(font1);
        ATTitleInput = new QLineEdit(addTestPage);
        ATTitleInput->setObjectName("ATTitleInput");
        ATTitleInput->setGeometry(QRect(190, 130, 491, 24));
        ATEndDateDateEdit = new QDateEdit(addTestPage);
        ATEndDateDateEdit->setObjectName("ATEndDateDateEdit");
        ATEndDateDateEdit->setGeometry(QRect(570, 240, 101, 25));
        ATBeginDateLabel = new QLabel(addTestPage);
        ATBeginDateLabel->setObjectName("ATBeginDateLabel");
        ATBeginDateLabel->setGeometry(QRect(440, 190, 101, 31));
        ATBeginDateLabel->setFont(font1);
        ATBeginDateDateEdit = new QDateEdit(addTestPage);
        ATBeginDateDateEdit->setObjectName("ATBeginDateDateEdit");
        ATBeginDateDateEdit->setGeometry(QRect(570, 190, 101, 25));
        ATCourceCodeLabel = new QLabel(addTestPage);
        ATCourceCodeLabel->setObjectName("ATCourceCodeLabel");
        ATCourceCodeLabel->setGeometry(QRect(40, 190, 121, 31));
        ATCourceCodeLabel->setFont(font1);
        ATQuestionsLabel = new QLabel(addTestPage);
        ATQuestionsLabel->setObjectName("ATQuestionsLabel");
        ATQuestionsLabel->setGeometry(QRect(40, 300, 111, 31));
        ATQuestionsLabel->setFont(font1);
        ATAddQuestionsButton = new QPushButton(addTestPage);
        ATAddQuestionsButton->setObjectName("ATAddQuestionsButton");
        ATAddQuestionsButton->setGeometry(QRect(320, 500, 111, 31));
        ATAddTestButton = new QPushButton(addTestPage);
        ATAddTestButton->setObjectName("ATAddTestButton");
        ATAddTestButton->setGeometry(QRect(90, 500, 101, 31));
        ATCancelButton = new QPushButton(addTestPage);
        ATCancelButton->setObjectName("ATCancelButton");
        ATCancelButton->setGeometry(QRect(580, 500, 101, 31));
        ATQuestionsList = new QListWidget(addTestPage);
        ATQuestionsList->setObjectName("ATQuestionsList");
        ATQuestionsList->setGeometry(QRect(190, 300, 501, 151));
        ATCourceCodeCombo = new QComboBox(addTestPage);
        ATCourceCodeCombo->addItem(QString());
        ATCourceCodeCombo->addItem(QString());
        ATCourceCodeCombo->addItem(QString());
        ATCourceCodeCombo->addItem(QString());
        ATCourceCodeCombo->addItem(QString());
        ATCourceCodeCombo->addItem(QString());
        ATCourceCodeCombo->addItem(QString());
        ATCourceCodeCombo->addItem(QString());
        ATCourceCodeCombo->addItem(QString());
        ATCourceCodeCombo->setObjectName("ATCourceCodeCombo");
        ATCourceCodeCombo->setGeometry(QRect(170, 200, 231, 24));
        stackedWidget->addWidget(addTestPage);
        ATAddQuestionsPage = new QWidget();
        ATAddQuestionsPage->setObjectName("ATAddQuestionsPage");
        ATAQLabel = new QLabel(ATAddQuestionsPage);
        ATAQLabel->setObjectName("ATAQLabel");
        ATAQLabel->setGeometry(QRect(220, 50, 341, 51));
        ATAQLabel->setBaseSize(QSize(0, 0));
        ATAQLabel->setFont(font);
        ATAQNumberOfQuestionsLabel = new QLabel(ATAddQuestionsPage);
        ATAQNumberOfQuestionsLabel->setObjectName("ATAQNumberOfQuestionsLabel");
        ATAQNumberOfQuestionsLabel->setGeometry(QRect(40, 160, 191, 31));
        ATAQNumberOfQuestionsLabel->setFont(font1);
        ATAQNumberOfQuestionsSpinBox = new QSpinBox(ATAddQuestionsPage);
        ATAQNumberOfQuestionsSpinBox->setObjectName("ATAQNumberOfQuestionsSpinBox");
        ATAQNumberOfQuestionsSpinBox->setGeometry(QRect(260, 160, 81, 31));
        ATAQAddQuestionsButton = new QPushButton(ATAddQuestionsPage);
        ATAQAddQuestionsButton->setObjectName("ATAQAddQuestionsButton");
        ATAQAddQuestionsButton->setGeometry(QRect(70, 480, 111, 31));
        ATAQQuestionsList = new QListWidget(ATAddQuestionsPage);
        ATAQQuestionsList->setObjectName("ATAQQuestionsList");
        ATAQQuestionsList->setGeometry(QRect(240, 240, 491, 192));
        ATAQConfirmQuestionsButton = new QPushButton(ATAddQuestionsPage);
        ATAQConfirmQuestionsButton->setObjectName("ATAQConfirmQuestionsButton");
        ATAQConfirmQuestionsButton->setGeometry(QRect(310, 480, 121, 31));
        ATAQCancelButton = new QPushButton(ATAddQuestionsPage);
        ATAQCancelButton->setObjectName("ATAQCancelButton");
        ATAQCancelButton->setGeometry(QRect(590, 480, 101, 31));
        ATAQQuestionsLabel = new QLabel(ATAddQuestionsPage);
        ATAQQuestionsLabel->setObjectName("ATAQQuestionsLabel");
        ATAQQuestionsLabel->setGeometry(QRect(40, 230, 101, 31));
        ATAQQuestionsLabel->setFont(font1);
        stackedWidget->addWidget(ATAddQuestionsPage);
        addAssignmentPage = new QWidget();
        addAssignmentPage->setObjectName("addAssignmentPage");
        AALabel = new QLabel(addAssignmentPage);
        AALabel->setObjectName("AALabel");
        AALabel->setGeometry(QRect(220, 50, 361, 51));
        AALabel->setBaseSize(QSize(0, 0));
        AALabel->setFont(font);
        AATitleLabel = new QLabel(addAssignmentPage);
        AATitleLabel->setObjectName("AATitleLabel");
        AATitleLabel->setGeometry(QRect(40, 140, 51, 31));
        AATitleLabel->setFont(font1);
        AADescriptionLabel = new QLabel(addAssignmentPage);
        AADescriptionLabel->setObjectName("AADescriptionLabel");
        AADescriptionLabel->setGeometry(QRect(40, 210, 111, 31));
        AADescriptionLabel->setFont(font1);
        AABeginDateLabel = new QLabel(addAssignmentPage);
        AABeginDateLabel->setObjectName("AABeginDateLabel");
        AABeginDateLabel->setGeometry(QRect(40, 370, 101, 31));
        AABeginDateLabel->setFont(font1);
        AAEndDateLabel = new QLabel(addAssignmentPage);
        AAEndDateLabel->setObjectName("AAEndDateLabel");
        AAEndDateLabel->setGeometry(QRect(40, 420, 81, 31));
        AAEndDateLabel->setFont(font1);
        AABeginDateDateEdit = new QDateEdit(addAssignmentPage);
        AABeginDateDateEdit->setObjectName("AABeginDateDateEdit");
        AABeginDateDateEdit->setGeometry(QRect(180, 380, 101, 25));
        AAEndDateDateEdit = new QDateEdit(addAssignmentPage);
        AAEndDateDateEdit->setObjectName("AAEndDateDateEdit");
        AAEndDateDateEdit->setGeometry(QRect(180, 430, 110, 25));
        AATitleInput = new QLineEdit(addAssignmentPage);
        AATitleInput->setObjectName("AATitleInput");
        AATitleInput->setGeometry(QRect(180, 150, 491, 24));
        AADesctiptionInput = new QLineEdit(addAssignmentPage);
        AADesctiptionInput->setObjectName("AADesctiptionInput");
        AADesctiptionInput->setGeometry(QRect(170, 220, 511, 61));
        AADesctiptionInput->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        AAAddButton = new QPushButton(addAssignmentPage);
        AAAddButton->setObjectName("AAAddButton");
        AAAddButton->setGeometry(QRect(180, 490, 121, 31));
        AACancelButton = new QPushButton(addAssignmentPage);
        AACancelButton->setObjectName("AACancelButton");
        AACancelButton->setGeometry(QRect(490, 490, 101, 31));
        AACourceCodeLabel = new QLabel(addAssignmentPage);
        AACourceCodeLabel->setObjectName("AACourceCodeLabel");
        AACourceCodeLabel->setGeometry(QRect(40, 300, 121, 31));
        AACourceCodeLabel->setFont(font1);
        AACourceCodeCombo = new QComboBox(addAssignmentPage);
        AACourceCodeCombo->addItem(QString());
        AACourceCodeCombo->addItem(QString());
        AACourceCodeCombo->addItem(QString());
        AACourceCodeCombo->addItem(QString());
        AACourceCodeCombo->addItem(QString());
        AACourceCodeCombo->addItem(QString());
        AACourceCodeCombo->addItem(QString());
        AACourceCodeCombo->addItem(QString());
        AACourceCodeCombo->addItem(QString());
        AACourceCodeCombo->setObjectName("AACourceCodeCombo");
        AACourceCodeCombo->setGeometry(QRect(180, 310, 231, 24));
        stackedWidget->addWidget(addAssignmentPage);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(tooltip)
        stackedWidget->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        registerButton->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        emailLoginLabel->setText(QCoreApplication::translate("MainWindow", "Email:", nullptr));
        passwordLoginLabel->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        emailLoginInput->setPlaceholderText(QString());
#if QT_CONFIG(tooltip)
        passwordLoginInput->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        loginButton->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        exitButton->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        backToLoginPageButton->setText(QCoreApplication::translate("MainWindow", "Back to Login Page", nullptr));
        surnameRegisterLabel->setText(QCoreApplication::translate("MainWindow", "Surname:", nullptr));
        studentMajorRegisterLabel->setText(QCoreApplication::translate("MainWindow", "Student Major:", nullptr));
        fullNameRegisterLabel->setText(QCoreApplication::translate("MainWindow", "Full Name:", nullptr));
        emailRegisterLabel->setText(QCoreApplication::translate("MainWindow", "Email:", nullptr));
#if QT_CONFIG(tooltip)
        passwordRegisterInput->setToolTip(QCoreApplication::translate("MainWindow", "Password must contain:\n"
"- minimum 8 characters\n"
"- minimum 1 uppercase and 1 lowercase letter\n"
"- minimum 1 digit\n"
"- minimum 1 special charater (#?!@$%^&*-)\n"
"", nullptr));
#endif // QT_CONFIG(tooltip)
        passwordRegisterLabel->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        registerToDatabaseButton->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        dateOfBirthRegisterLabel->setText(QCoreApplication::translate("MainWindow", "Date of Birth:", nullptr));
        studentRegisterRadioButton->setText(QCoreApplication::translate("MainWindow", "Student", nullptr));
        professorRegisterRadioButton->setText(QCoreApplication::translate("MainWindow", "Professor", nullptr));
#if QT_CONFIG(tooltip)
        nameRegisterInput->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        nameRegisterInput->setPlaceholderText(QString());
        studentMajorRegisterCombo->setItemText(0, QCoreApplication::translate("MainWindow", "Aviation and Astronautics [AvAs]", nullptr));
        studentMajorRegisterCombo->setItemText(1, QCoreApplication::translate("MainWindow", "Chemical Engineering and Technology [ChET]", nullptr));
        studentMajorRegisterCombo->setItemText(2, QCoreApplication::translate("MainWindow", "Chemical Technology [ChTe]", nullptr));
        studentMajorRegisterCombo->setItemText(3, QCoreApplication::translate("MainWindow", "Civil Engineering [CiEn]", nullptr));
        studentMajorRegisterCombo->setItemText(4, QCoreApplication::translate("MainWindow", "Computer Engineering [CoEn]", nullptr));
        studentMajorRegisterCombo->setItemText(5, QCoreApplication::translate("MainWindow", "Electrical Engineering [ElEn]", nullptr));
        studentMajorRegisterCombo->setItemText(6, QCoreApplication::translate("MainWindow", "Finance and Accounting [FiAc]", nullptr));
        studentMajorRegisterCombo->setItemText(7, QCoreApplication::translate("MainWindow", "Logistics [Logi]", nullptr));
        studentMajorRegisterCombo->setItemText(8, QCoreApplication::translate("MainWindow", "Modern Management [MoMa]", nullptr));

        professorTitleRegisterCombo->setItemText(0, QCoreApplication::translate("MainWindow", "BSc", nullptr));
        professorTitleRegisterCombo->setItemText(1, QCoreApplication::translate("MainWindow", "Eng.", nullptr));
        professorTitleRegisterCombo->setItemText(2, QCoreApplication::translate("MainWindow", "MSc", nullptr));
        professorTitleRegisterCombo->setItemText(3, QCoreApplication::translate("MainWindow", "PhD", nullptr));
        professorTitleRegisterCombo->setItemText(4, QCoreApplication::translate("MainWindow", "Prof.", nullptr));

        professorSpecRegisterLabel->setText(QCoreApplication::translate("MainWindow", "Professor Specialization:", nullptr));
        professorTitleRegisterLabel->setText(QCoreApplication::translate("MainWindow", "Professor Title:", nullptr));
        professorSpecRegisterCombo->setItemText(0, QCoreApplication::translate("MainWindow", "Aviation and Astronautics [AvAs]", nullptr));
        professorSpecRegisterCombo->setItemText(1, QCoreApplication::translate("MainWindow", "Chemical Engineering and Technology [ChET]", nullptr));
        professorSpecRegisterCombo->setItemText(2, QCoreApplication::translate("MainWindow", "Chemical Technology [ChTe]", nullptr));
        professorSpecRegisterCombo->setItemText(3, QCoreApplication::translate("MainWindow", "Civil Engineering [CiEn]", nullptr));
        professorSpecRegisterCombo->setItemText(4, QCoreApplication::translate("MainWindow", "Computer Engineering [CoEn]", nullptr));
        professorSpecRegisterCombo->setItemText(5, QCoreApplication::translate("MainWindow", "Electrical Engineering [ElEn]", nullptr));
        professorSpecRegisterCombo->setItemText(6, QCoreApplication::translate("MainWindow", "Finance and Accounting [FiAc]", nullptr));
        professorSpecRegisterCombo->setItemText(7, QCoreApplication::translate("MainWindow", "Logistics [Logi]", nullptr));
        professorSpecRegisterCombo->setItemText(8, QCoreApplication::translate("MainWindow", "Modern Management [MoMa]", nullptr));

        SMLogOutButton->setText(QCoreApplication::translate("MainWindow", "Log Out", nullptr));
        SMWelcomeLabel->setText(QCoreApplication::translate("MainWindow", "Welcome ", nullptr));
        SMNameLabel->setText(QString());
        SMChangeEmailButton->setText(QCoreApplication::translate("MainWindow", "Change Email", nullptr));
        SMChangePasswordButton->setText(QCoreApplication::translate("MainWindow", "Change Password", nullptr));
        SMChangeNameButton->setText(QCoreApplication::translate("MainWindow", "Change Name", nullptr));
        SMChangeSurnameButton->setText(QCoreApplication::translate("MainWindow", "Change Surname", nullptr));
        SMUpcomingTasksLabel->setText(QCoreApplication::translate("MainWindow", "Upcoming Tasks:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "prof", nullptr));
        PMLogOutButton->setText(QCoreApplication::translate("MainWindow", "Log Out", nullptr));
        PMNameLabel->setText(QString());
        PMChangeEmailButton->setText(QCoreApplication::translate("MainWindow", "Change Email", nullptr));
        PMWelcomeLabel->setText(QCoreApplication::translate("MainWindow", "Welcome ", nullptr));
        PMChangePasswordButton->setText(QCoreApplication::translate("MainWindow", "Change Password", nullptr));
        PMChangeSurnameButton->setText(QCoreApplication::translate("MainWindow", "Change Surname", nullptr));
        PMChangeNameButton->setText(QCoreApplication::translate("MainWindow", "Change Name", nullptr));
        PMAddNewAssignmentButton->setText(QCoreApplication::translate("MainWindow", "Add New Assignment", nullptr));
        PMAddNewTestButton->setText(QCoreApplication::translate("MainWindow", "Add New Test", nullptr));
        ATLabel->setText(QCoreApplication::translate("MainWindow", "Add New Test", nullptr));
        ATTitleLabel->setText(QCoreApplication::translate("MainWindow", "Title:", nullptr));
        ATEndDateLabel->setText(QCoreApplication::translate("MainWindow", "End Date:", nullptr));
        ATBeginDateLabel->setText(QCoreApplication::translate("MainWindow", "Begin Date:", nullptr));
        ATCourceCodeLabel->setText(QCoreApplication::translate("MainWindow", "Cource Code:", nullptr));
        ATQuestionsLabel->setText(QCoreApplication::translate("MainWindow", "Questions:", nullptr));
        ATAddQuestionsButton->setText(QCoreApplication::translate("MainWindow", "Add Questions", nullptr));
        ATAddTestButton->setText(QCoreApplication::translate("MainWindow", "Add Test", nullptr));
        ATCancelButton->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        ATCourceCodeCombo->setItemText(0, QCoreApplication::translate("MainWindow", "Aviation and Astronautics [AvAs]", nullptr));
        ATCourceCodeCombo->setItemText(1, QCoreApplication::translate("MainWindow", "Chemical Engineering and Technology [ChET]", nullptr));
        ATCourceCodeCombo->setItemText(2, QCoreApplication::translate("MainWindow", "Chemical Technology [ChTe]", nullptr));
        ATCourceCodeCombo->setItemText(3, QCoreApplication::translate("MainWindow", "Civil Engineering [CiEn]", nullptr));
        ATCourceCodeCombo->setItemText(4, QCoreApplication::translate("MainWindow", "Computer Engineering [CoEn]", nullptr));
        ATCourceCodeCombo->setItemText(5, QCoreApplication::translate("MainWindow", "Electrical Engineering [ElEn]", nullptr));
        ATCourceCodeCombo->setItemText(6, QCoreApplication::translate("MainWindow", "Finance and Accounting [FiAc]", nullptr));
        ATCourceCodeCombo->setItemText(7, QCoreApplication::translate("MainWindow", "Logistics [Logi]", nullptr));
        ATCourceCodeCombo->setItemText(8, QCoreApplication::translate("MainWindow", "Modern Management [MoMa]", nullptr));

        ATAQLabel->setText(QCoreApplication::translate("MainWindow", "Add New Questions", nullptr));
        ATAQNumberOfQuestionsLabel->setText(QCoreApplication::translate("MainWindow", "Number of Questions:", nullptr));
        ATAQAddQuestionsButton->setText(QCoreApplication::translate("MainWindow", "Add Questions", nullptr));
        ATAQConfirmQuestionsButton->setText(QCoreApplication::translate("MainWindow", "Confirm Questions", nullptr));
        ATAQCancelButton->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        ATAQQuestionsLabel->setText(QCoreApplication::translate("MainWindow", "Questions:", nullptr));
        AALabel->setText(QCoreApplication::translate("MainWindow", "Add New Assignment", nullptr));
        AATitleLabel->setText(QCoreApplication::translate("MainWindow", "Title:", nullptr));
        AADescriptionLabel->setText(QCoreApplication::translate("MainWindow", "Description:", nullptr));
        AABeginDateLabel->setText(QCoreApplication::translate("MainWindow", "Begin Date:", nullptr));
        AAEndDateLabel->setText(QCoreApplication::translate("MainWindow", "End Date:", nullptr));
        AAAddButton->setText(QCoreApplication::translate("MainWindow", "Add Assignment", nullptr));
        AACancelButton->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        AACourceCodeLabel->setText(QCoreApplication::translate("MainWindow", "Cource Code:", nullptr));
        AACourceCodeCombo->setItemText(0, QCoreApplication::translate("MainWindow", "Aviation and Astronautics [AvAs]", nullptr));
        AACourceCodeCombo->setItemText(1, QCoreApplication::translate("MainWindow", "Chemical Engineering and Technology [ChET]", nullptr));
        AACourceCodeCombo->setItemText(2, QCoreApplication::translate("MainWindow", "Chemical Technology [ChTe]", nullptr));
        AACourceCodeCombo->setItemText(3, QCoreApplication::translate("MainWindow", "Civil Engineering [CiEn]", nullptr));
        AACourceCodeCombo->setItemText(4, QCoreApplication::translate("MainWindow", "Computer Engineering [CoEn]", nullptr));
        AACourceCodeCombo->setItemText(5, QCoreApplication::translate("MainWindow", "Electrical Engineering [ElEn]", nullptr));
        AACourceCodeCombo->setItemText(6, QCoreApplication::translate("MainWindow", "Finance and Accounting [FiAc]", nullptr));
        AACourceCodeCombo->setItemText(7, QCoreApplication::translate("MainWindow", "Logistics [Logi]", nullptr));
        AACourceCodeCombo->setItemText(8, QCoreApplication::translate("MainWindow", "Modern Management [MoMa]", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
