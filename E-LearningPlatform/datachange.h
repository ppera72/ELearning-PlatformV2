#pragma once

#include <QString>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QSqlError>




class dataChange
{
public:
    QString EMAIL;
    dataChange();
    void checkTableNames(bool st);
    bool checkEmail(QString email);
    bool checkPassword(QString password);
    bool checkNames(QString name, QString surname);

    bool student, professor;
    void changeEmail(QString email, bool st, QString oldEmail);
    void changePassword(QString pass, bool st, QString oldPass);
    void changeName(QString pass, bool st, QString oldName);
    void changeSurname(QString pass, bool st, QString oldSurname);
};


