/********************************************************************************
** Form generated from reading UI file 'studentmain.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTMAIN_H
#define UI_STUDENTMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_studentMain
{
public:
    QStackedWidget *stackedWidget;
    QWidget *studentMainLogin;
    QLabel *welcomeLabel;
    QLabel *nameLabel;
    QLabel *upcomingTasksLabel;
    QLabel *allTasksLabel;
    QLabel *label;
    QLabel *label_2;
    QPushButton *changeEmailButton;
    QPushButton *changePasswordButton;
    QPushButton *changeNameButton;
    QPushButton *changeSurnameButton;

    void setupUi(QDialog *studentMain)
    {
        if (studentMain->objectName().isEmpty())
            studentMain->setObjectName("studentMain");
        studentMain->resize(800, 600);
        stackedWidget = new QStackedWidget(studentMain);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 801, 601));
        studentMainLogin = new QWidget();
        studentMainLogin->setObjectName("studentMainLogin");
        welcomeLabel = new QLabel(studentMainLogin);
        welcomeLabel->setObjectName("welcomeLabel");
        welcomeLabel->setGeometry(QRect(30, 80, 61, 21));
        nameLabel = new QLabel(studentMainLogin);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setGeometry(QRect(100, 80, 61, 21));
        upcomingTasksLabel = new QLabel(studentMainLogin);
        upcomingTasksLabel->setObjectName("upcomingTasksLabel");
        upcomingTasksLabel->setGeometry(QRect(510, 60, 91, 31));
        allTasksLabel = new QLabel(studentMainLogin);
        allTasksLabel->setObjectName("allTasksLabel");
        allTasksLabel->setGeometry(QRect(90, 360, 161, 16));
        label = new QLabel(studentMainLogin);
        label->setObjectName("label");
        label->setGeometry(QRect(510, 110, 191, 141));
        label->setFrameShape(QFrame::Shape::Box);
        label_2 = new QLabel(studentMainLogin);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 400, 611, 141));
        label_2->setFrameShape(QFrame::Shape::Box);
        changeEmailButton = new QPushButton(studentMainLogin);
        changeEmailButton->setObjectName("changeEmailButton");
        changeEmailButton->setGeometry(QRect(20, 140, 120, 30));
        changePasswordButton = new QPushButton(studentMainLogin);
        changePasswordButton->setObjectName("changePasswordButton");
        changePasswordButton->setGeometry(QRect(150, 140, 120, 30));
        changeNameButton = new QPushButton(studentMainLogin);
        changeNameButton->setObjectName("changeNameButton");
        changeNameButton->setGeometry(QRect(20, 220, 120, 30));
        changeSurnameButton = new QPushButton(studentMainLogin);
        changeSurnameButton->setObjectName("changeSurnameButton");
        changeSurnameButton->setGeometry(QRect(150, 220, 120, 30));
        stackedWidget->addWidget(studentMainLogin);

        retranslateUi(studentMain);

        QMetaObject::connectSlotsByName(studentMain);
    } // setupUi

    void retranslateUi(QDialog *studentMain)
    {
        studentMain->setWindowTitle(QCoreApplication::translate("studentMain", "Dialog", nullptr));
        welcomeLabel->setText(QCoreApplication::translate("studentMain", "Welcome", nullptr));
        nameLabel->setText(QCoreApplication::translate("studentMain", "*name*", nullptr));
        upcomingTasksLabel->setText(QCoreApplication::translate("studentMain", "Upcoming Tasks:", nullptr));
        allTasksLabel->setText(QCoreApplication::translate("studentMain", "All Tasks / Completed Tasks:", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        changeEmailButton->setText(QCoreApplication::translate("studentMain", "Change Email", nullptr));
        changePasswordButton->setText(QCoreApplication::translate("studentMain", "Change Password", nullptr));
        changeNameButton->setText(QCoreApplication::translate("studentMain", "Change Name", nullptr));
        changeSurnameButton->setText(QCoreApplication::translate("studentMain", "Change Surname", nullptr));
    } // retranslateUi

};

namespace Ui {
    class studentMain: public Ui_studentMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTMAIN_H
