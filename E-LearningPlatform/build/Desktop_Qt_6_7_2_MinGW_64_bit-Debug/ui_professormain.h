/********************************************************************************
** Form generated from reading UI file 'professormain.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFESSORMAIN_H
#define UI_PROFESSORMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_professorMain
{
public:
    QStackedWidget *stackedWidget;
    QWidget *professorMainLogin;
    QPushButton *test;
    QLabel *label;
    QLabel *label_3;
    QLabel *welcomeLabel;
    QLabel *helpLabel;
    QLabel *upcomingTasksLabel;
    QPushButton *test_2;
    QLabel *nameLabel;
    QLabel *label_2;
    QLabel *allTasksLabel;

    void setupUi(QDialog *professorMain)
    {
        if (professorMain->objectName().isEmpty())
            professorMain->setObjectName("professorMain");
        professorMain->resize(800, 600);
        stackedWidget = new QStackedWidget(professorMain);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 801, 601));
        professorMainLogin = new QWidget();
        professorMainLogin->setObjectName("professorMainLogin");
        test = new QPushButton(professorMainLogin);
        test->setObjectName("test");
        test->setGeometry(QRect(130, 270, 80, 24));
        label = new QLabel(professorMainLogin);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 240, 231, 21));
        label_3 = new QLabel(professorMainLogin);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(530, 80, 191, 141));
        label_3->setFrameShape(QFrame::Shape::Box);
        welcomeLabel = new QLabel(professorMainLogin);
        welcomeLabel->setObjectName("welcomeLabel");
        welcomeLabel->setGeometry(QRect(50, 50, 61, 21));
        helpLabel = new QLabel(professorMainLogin);
        helpLabel->setObjectName("helpLabel");
        helpLabel->setGeometry(QRect(70, 160, 201, 16));
        upcomingTasksLabel = new QLabel(professorMainLogin);
        upcomingTasksLabel->setObjectName("upcomingTasksLabel");
        upcomingTasksLabel->setGeometry(QRect(530, 30, 91, 31));
        test_2 = new QPushButton(professorMainLogin);
        test_2->setObjectName("test_2");
        test_2->setGeometry(QRect(240, 200, 80, 24));
        nameLabel = new QLabel(professorMainLogin);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setGeometry(QRect(120, 50, 61, 21));
        label_2 = new QLabel(professorMainLogin);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 380, 611, 141));
        label_2->setFrameShape(QFrame::Shape::Box);
        allTasksLabel = new QLabel(professorMainLogin);
        allTasksLabel->setObjectName("allTasksLabel");
        allTasksLabel->setGeometry(QRect(50, 340, 161, 16));
        stackedWidget->addWidget(professorMainLogin);

        retranslateUi(professorMain);

        QMetaObject::connectSlotsByName(professorMain);
    } // setupUi

    void retranslateUi(QDialog *professorMain)
    {
        professorMain->setWindowTitle(QCoreApplication::translate("professorMain", "Dialog", nullptr));
        test->setText(QCoreApplication::translate("professorMain", "A", nullptr));
        label->setText(QCoreApplication::translate("professorMain", "PROF MAIN", nullptr));
        label_3->setText(QString());
        welcomeLabel->setText(QCoreApplication::translate("professorMain", "Welcome", nullptr));
        helpLabel->setText(QCoreApplication::translate("professorMain", "*buttons changing email/pass etc.*", nullptr));
        upcomingTasksLabel->setText(QCoreApplication::translate("professorMain", "Upcoming Tasks:", nullptr));
        test_2->setText(QCoreApplication::translate("professorMain", "PushButton", nullptr));
        nameLabel->setText(QCoreApplication::translate("professorMain", "*name*", nullptr));
        label_2->setText(QString());
        allTasksLabel->setText(QCoreApplication::translate("professorMain", "All Tasks / Completed Tasks:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class professorMain: public Ui_professorMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFESSORMAIN_H
