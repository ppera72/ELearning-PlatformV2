#pragma once

#include "studentmain.h"
#include "professormain.h"
#include "qsqldatabase.h"
#include <QDialog>
#include <QMainWindow>
#include <QDebug>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QSqlError>


namespace Ui {
class loginWindow;
}

class loginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit loginWindow(QWidget *parent = nullptr);
    ~loginWindow();

    studentMain StudentMain;
    professorMain ProfessorMain;
    QSqlDatabase db;

    bool checkEmail(QString email);
    bool checkPassword(QString password);
    bool checkNames(QString name, QString surname);

private:
    Ui::loginWindow *ui;

    void on_loginButton_clicked();

    void on_registerButton_clicked();

    void on_backToLoginPageButton_clicked();

    void on_registerToDatabaseButton_clicked();


    bool checkIfInStudentDatabase(QString emailToCheck, QString passwordToCheck);
    bool checkIfInProfDatabase(QString emailToCheck, QString passwordToCheck);


    void on_passwordRegisterHelpButton_clicked();
};

