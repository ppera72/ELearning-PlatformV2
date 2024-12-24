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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
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
    QLabel *welcomeLabel;
    QLabel *nameLabel;
    QPushButton *studMainChangeEmailButton;
    QPushButton *studMainChangePasswordButton;
    QPushButton *studMainChangeNameButton;
    QPushButton *studMainChangeSurnameButton;
    QWidget *professorMainPage;
    QLabel *label_2;
    QPushButton *PMLogOutButton;

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
        welcomeLabel = new QLabel(studentMainPage);
        welcomeLabel->setObjectName("welcomeLabel");
        welcomeLabel->setGeometry(QRect(70, 110, 61, 16));
        nameLabel = new QLabel(studentMainPage);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setGeometry(QRect(140, 110, 49, 16));
        studMainChangeEmailButton = new QPushButton(studentMainPage);
        studMainChangeEmailButton->setObjectName("studMainChangeEmailButton");
        studMainChangeEmailButton->setGeometry(QRect(30, 170, 111, 24));
        studMainChangePasswordButton = new QPushButton(studentMainPage);
        studMainChangePasswordButton->setObjectName("studMainChangePasswordButton");
        studMainChangePasswordButton->setGeometry(QRect(150, 170, 111, 24));
        studMainChangeNameButton = new QPushButton(studentMainPage);
        studMainChangeNameButton->setObjectName("studMainChangeNameButton");
        studMainChangeNameButton->setGeometry(QRect(30, 220, 111, 24));
        studMainChangeSurnameButton = new QPushButton(studentMainPage);
        studMainChangeSurnameButton->setObjectName("studMainChangeSurnameButton");
        studMainChangeSurnameButton->setGeometry(QRect(150, 220, 111, 24));
        stackedWidget->addWidget(studentMainPage);
        professorMainPage = new QWidget();
        professorMainPage->setObjectName("professorMainPage");
        label_2 = new QLabel(professorMainPage);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(350, 290, 49, 16));
        PMLogOutButton = new QPushButton(professorMainPage);
        PMLogOutButton->setObjectName("PMLogOutButton");
        PMLogOutButton->setGeometry(QRect(80, 540, 80, 24));
        stackedWidget->addWidget(professorMainPage);
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
        welcomeLabel->setText(QCoreApplication::translate("MainWindow", "Welcome ", nullptr));
        nameLabel->setText(QString());
        studMainChangeEmailButton->setText(QCoreApplication::translate("MainWindow", "Change Email", nullptr));
        studMainChangePasswordButton->setText(QCoreApplication::translate("MainWindow", "Change Password", nullptr));
        studMainChangeNameButton->setText(QCoreApplication::translate("MainWindow", "Change Name", nullptr));
        studMainChangeSurnameButton->setText(QCoreApplication::translate("MainWindow", "Change Surname", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "prof", nullptr));
        PMLogOutButton->setText(QCoreApplication::translate("MainWindow", "Log Out", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
