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
    QLineEdit *nameRegisterInput;
    QLineEdit *surnameRegisterInput;
    QLineEdit *emailRegisterInput;
    QLineEdit *passwordRegisterInput;
    QPushButton *registerToDatabaseButton;
    QLabel *fullNameRegisterLabel;
    QLabel *surnameRegisterLabel;
    QLabel *emailRegisterLabel;
    QLabel *passwordRegisterLabel;
    QPushButton *backToLoginPageButton;
    QRadioButton *studentRegisterRadioButton;
    QRadioButton *professorRegisterRadioButton;
    QComboBox *majorRegisterCombo;
    QLabel *studentMajorRegisterLabel;
    QLabel *dateOfBirthRegisterLabel;
    QDateEdit *dateOfBirthRegisterEdit;
    QWidget *studentMainPage;
    QLabel *label;
    QPushButton *SMLogOutButton;
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
        nameRegisterInput = new QLineEdit(registerWidnow);
        nameRegisterInput->setObjectName("nameRegisterInput");
        nameRegisterInput->setGeometry(QRect(220, 90, 113, 24));
        surnameRegisterInput = new QLineEdit(registerWidnow);
        surnameRegisterInput->setObjectName("surnameRegisterInput");
        surnameRegisterInput->setGeometry(QRect(220, 140, 113, 24));
        emailRegisterInput = new QLineEdit(registerWidnow);
        emailRegisterInput->setObjectName("emailRegisterInput");
        emailRegisterInput->setGeometry(QRect(230, 190, 113, 24));
        passwordRegisterInput = new QLineEdit(registerWidnow);
        passwordRegisterInput->setObjectName("passwordRegisterInput");
        passwordRegisterInput->setGeometry(QRect(230, 240, 113, 24));
        passwordRegisterInput->setEchoMode(QLineEdit::EchoMode::Password);
        registerToDatabaseButton = new QPushButton(registerWidnow);
        registerToDatabaseButton->setObjectName("registerToDatabaseButton");
        registerToDatabaseButton->setGeometry(QRect(260, 500, 80, 24));
        fullNameRegisterLabel = new QLabel(registerWidnow);
        fullNameRegisterLabel->setObjectName("fullNameRegisterLabel");
        fullNameRegisterLabel->setGeometry(QRect(128, 100, 61, 20));
        surnameRegisterLabel = new QLabel(registerWidnow);
        surnameRegisterLabel->setObjectName("surnameRegisterLabel");
        surnameRegisterLabel->setGeometry(QRect(128, 150, 61, 20));
        emailRegisterLabel = new QLabel(registerWidnow);
        emailRegisterLabel->setObjectName("emailRegisterLabel");
        emailRegisterLabel->setGeometry(QRect(128, 200, 61, 20));
        passwordRegisterLabel = new QLabel(registerWidnow);
        passwordRegisterLabel->setObjectName("passwordRegisterLabel");
        passwordRegisterLabel->setGeometry(QRect(128, 240, 61, 20));
        backToLoginPageButton = new QPushButton(registerWidnow);
        backToLoginPageButton->setObjectName("backToLoginPageButton");
        backToLoginPageButton->setGeometry(QRect(420, 500, 131, 24));
        studentRegisterRadioButton = new QRadioButton(registerWidnow);
        studentRegisterRadioButton->setObjectName("studentRegisterRadioButton");
        studentRegisterRadioButton->setGeometry(QRect(130, 330, 91, 22));
        professorRegisterRadioButton = new QRadioButton(registerWidnow);
        professorRegisterRadioButton->setObjectName("professorRegisterRadioButton");
        professorRegisterRadioButton->setGeometry(QRect(290, 330, 91, 22));
        majorRegisterCombo = new QComboBox(registerWidnow);
        majorRegisterCombo->addItem(QString());
        majorRegisterCombo->addItem(QString());
        majorRegisterCombo->addItem(QString());
        majorRegisterCombo->addItem(QString());
        majorRegisterCombo->addItem(QString());
        majorRegisterCombo->addItem(QString());
        majorRegisterCombo->addItem(QString());
        majorRegisterCombo->addItem(QString());
        majorRegisterCombo->addItem(QString());
        majorRegisterCombo->setObjectName("majorRegisterCombo");
        majorRegisterCombo->setEnabled(true);
        majorRegisterCombo->setGeometry(QRect(100, 400, 251, 24));
        studentMajorRegisterLabel = new QLabel(registerWidnow);
        studentMajorRegisterLabel->setObjectName("studentMajorRegisterLabel");
        studentMajorRegisterLabel->setEnabled(true);
        studentMajorRegisterLabel->setGeometry(QRect(98, 370, 221, 20));
        dateOfBirthRegisterLabel = new QLabel(registerWidnow);
        dateOfBirthRegisterLabel->setObjectName("dateOfBirthRegisterLabel");
        dateOfBirthRegisterLabel->setGeometry(QRect(120, 290, 71, 16));
        dateOfBirthRegisterEdit = new QDateEdit(registerWidnow);
        dateOfBirthRegisterEdit->setObjectName("dateOfBirthRegisterEdit");
        dateOfBirthRegisterEdit->setGeometry(QRect(230, 280, 110, 25));
        stackedWidget->addWidget(registerWidnow);
        studentMainPage = new QWidget();
        studentMainPage->setObjectName("studentMainPage");
        label = new QLabel(studentMainPage);
        label->setObjectName("label");
        label->setGeometry(QRect(300, 200, 49, 16));
        SMLogOutButton = new QPushButton(studentMainPage);
        SMLogOutButton->setObjectName("SMLogOutButton");
        SMLogOutButton->setGeometry(QRect(90, 530, 80, 24));
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

        stackedWidget->setCurrentIndex(3);


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
#if QT_CONFIG(tooltip)
        nameRegisterInput->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        nameRegisterInput->setPlaceholderText(QString());
#if QT_CONFIG(tooltip)
        passwordRegisterInput->setToolTip(QCoreApplication::translate("MainWindow", "Password must contain:\n"
"- minimum 8 characters\n"
"- minimum 1 uppercase and 1 lowercase letter\n"
"- minimum 1 digit\n"
"- minimum 1 special charater (#?!@$%^&*-)\n"
"", nullptr));
#endif // QT_CONFIG(tooltip)
        registerToDatabaseButton->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        fullNameRegisterLabel->setText(QCoreApplication::translate("MainWindow", "Full Name:", nullptr));
        surnameRegisterLabel->setText(QCoreApplication::translate("MainWindow", "Surname:", nullptr));
        emailRegisterLabel->setText(QCoreApplication::translate("MainWindow", "Email:", nullptr));
        passwordRegisterLabel->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        backToLoginPageButton->setText(QCoreApplication::translate("MainWindow", "Back to Login Page", nullptr));
        studentRegisterRadioButton->setText(QCoreApplication::translate("MainWindow", "Student", nullptr));
        professorRegisterRadioButton->setText(QCoreApplication::translate("MainWindow", "Professor", nullptr));
        majorRegisterCombo->setItemText(0, QCoreApplication::translate("MainWindow", "Aviation and Astronautics", nullptr));
        majorRegisterCombo->setItemText(1, QCoreApplication::translate("MainWindow", "Chemical Engineering and Technology", nullptr));
        majorRegisterCombo->setItemText(2, QCoreApplication::translate("MainWindow", "Chemical Technology", nullptr));
        majorRegisterCombo->setItemText(3, QCoreApplication::translate("MainWindow", "Civil Engineering", nullptr));
        majorRegisterCombo->setItemText(4, QCoreApplication::translate("MainWindow", "Computer Engineering", nullptr));
        majorRegisterCombo->setItemText(5, QCoreApplication::translate("MainWindow", "Electrical Engineering", nullptr));
        majorRegisterCombo->setItemText(6, QCoreApplication::translate("MainWindow", "Finance and Accounting", nullptr));
        majorRegisterCombo->setItemText(7, QCoreApplication::translate("MainWindow", "Logistics", nullptr));
        majorRegisterCombo->setItemText(8, QCoreApplication::translate("MainWindow", "Modern Management", nullptr));

        studentMajorRegisterLabel->setText(QCoreApplication::translate("MainWindow", "Student Major / Professor Departament:", nullptr));
        dateOfBirthRegisterLabel->setText(QCoreApplication::translate("MainWindow", "Date of Birth:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "stud", nullptr));
        SMLogOutButton->setText(QCoreApplication::translate("MainWindow", "Log Out", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "prof", nullptr));
        PMLogOutButton->setText(QCoreApplication::translate("MainWindow", "Log Out", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
