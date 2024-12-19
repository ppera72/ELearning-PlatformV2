/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginWindow
{
public:
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
    QToolButton *nameRegisterHelpButton;
    QToolButton *surnameRegisterHelpButton;
    QToolButton *emailRegisterHelpButton;
    QToolButton *passwordRegisterHelpButton;
    QRadioButton *studentRegisterRadioButton;
    QRadioButton *professorRegisterRadioButton;
    QComboBox *majorRegisterCombo;
    QLabel *studentMajorRegisterLabel;

    void setupUi(QDialog *loginWindow)
    {
        if (loginWindow->objectName().isEmpty())
            loginWindow->setObjectName("loginWindow");
        loginWindow->resize(800, 600);
        stackedWidget = new QStackedWidget(loginWindow);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 800, 600));
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
        passwordRegisterInput->setGeometry(QRect(230, 270, 113, 24));
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
        passwordRegisterLabel->setGeometry(QRect(128, 270, 61, 20));
        backToLoginPageButton = new QPushButton(registerWidnow);
        backToLoginPageButton->setObjectName("backToLoginPageButton");
        backToLoginPageButton->setGeometry(QRect(420, 500, 131, 24));
        nameRegisterHelpButton = new QToolButton(registerWidnow);
        nameRegisterHelpButton->setObjectName("nameRegisterHelpButton");
        nameRegisterHelpButton->setGeometry(QRect(360, 90, 23, 23));
        surnameRegisterHelpButton = new QToolButton(registerWidnow);
        surnameRegisterHelpButton->setObjectName("surnameRegisterHelpButton");
        surnameRegisterHelpButton->setGeometry(QRect(360, 140, 23, 23));
        emailRegisterHelpButton = new QToolButton(registerWidnow);
        emailRegisterHelpButton->setObjectName("emailRegisterHelpButton");
        emailRegisterHelpButton->setGeometry(QRect(380, 190, 23, 23));
        passwordRegisterHelpButton = new QToolButton(registerWidnow);
        passwordRegisterHelpButton->setObjectName("passwordRegisterHelpButton");
        passwordRegisterHelpButton->setGeometry(QRect(370, 270, 23, 23));
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
        stackedWidget->addWidget(registerWidnow);

        retranslateUi(loginWindow);
        QObject::connect(exitButton, &QPushButton::clicked, loginWindow, qOverload<>(&QDialog::close));

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(loginWindow);
    } // setupUi

    void retranslateUi(QDialog *loginWindow)
    {
        loginWindow->setWindowTitle(QCoreApplication::translate("loginWindow", "Dialog", nullptr));
#if QT_CONFIG(tooltip)
        stackedWidget->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        registerButton->setText(QCoreApplication::translate("loginWindow", "Register", nullptr));
        emailLoginLabel->setText(QCoreApplication::translate("loginWindow", "Email:", nullptr));
        passwordLoginLabel->setText(QCoreApplication::translate("loginWindow", "Password:", nullptr));
        loginButton->setText(QCoreApplication::translate("loginWindow", "Login", nullptr));
        exitButton->setText(QCoreApplication::translate("loginWindow", "Exit", nullptr));
#if QT_CONFIG(tooltip)
        nameRegisterInput->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        nameRegisterInput->setPlaceholderText(QString());
        registerToDatabaseButton->setText(QCoreApplication::translate("loginWindow", "Register", nullptr));
        fullNameRegisterLabel->setText(QCoreApplication::translate("loginWindow", "Full Name:", nullptr));
        surnameRegisterLabel->setText(QCoreApplication::translate("loginWindow", "Surname:", nullptr));
        emailRegisterLabel->setText(QCoreApplication::translate("loginWindow", "Email:", nullptr));
        passwordRegisterLabel->setText(QCoreApplication::translate("loginWindow", "Password:", nullptr));
        backToLoginPageButton->setText(QCoreApplication::translate("loginWindow", "Back to Login Page", nullptr));
        nameRegisterHelpButton->setText(QCoreApplication::translate("loginWindow", "?", nullptr));
        surnameRegisterHelpButton->setText(QCoreApplication::translate("loginWindow", "?", nullptr));
        emailRegisterHelpButton->setText(QCoreApplication::translate("loginWindow", "?", nullptr));
        passwordRegisterHelpButton->setText(QCoreApplication::translate("loginWindow", "?", nullptr));
        studentRegisterRadioButton->setText(QCoreApplication::translate("loginWindow", "Student", nullptr));
        professorRegisterRadioButton->setText(QCoreApplication::translate("loginWindow", "Professor", nullptr));
        majorRegisterCombo->setItemText(0, QCoreApplication::translate("loginWindow", "Aviation and Astronautics", nullptr));
        majorRegisterCombo->setItemText(1, QCoreApplication::translate("loginWindow", "Chemical Engineering and Technology", nullptr));
        majorRegisterCombo->setItemText(2, QCoreApplication::translate("loginWindow", "Chemical Technology", nullptr));
        majorRegisterCombo->setItemText(3, QCoreApplication::translate("loginWindow", "Civil Engineering", nullptr));
        majorRegisterCombo->setItemText(4, QCoreApplication::translate("loginWindow", "Computer Engineering", nullptr));
        majorRegisterCombo->setItemText(5, QCoreApplication::translate("loginWindow", "Electrical Engineering", nullptr));
        majorRegisterCombo->setItemText(6, QCoreApplication::translate("loginWindow", "Finance and Accounting", nullptr));
        majorRegisterCombo->setItemText(7, QCoreApplication::translate("loginWindow", "Logistics", nullptr));
        majorRegisterCombo->setItemText(8, QCoreApplication::translate("loginWindow", "Modern Management", nullptr));

        studentMajorRegisterLabel->setText(QCoreApplication::translate("loginWindow", "Student Major / Professor Departament:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginWindow: public Ui_loginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
