#include "datachange.h"
#include <QMessageBox>
#include <QRegularExpression>
#include <QtSql/QSqlDatabase>

dataChange::dataChange(){

}

bool dataChange::checkEmail(QString email){
    static QRegularExpression regex("^[a-zA-Z0-9]+@([a-zA-Z]+.)+[a-zA-Z0-9]{2,4}$"); // characters/numbers @ 2-4*(characters/numbers with dots between)
    if(regex.match(email).hasMatch())
        return true;
    return false;
}

bool dataChange::checkPassword(QString password){
    static QRegularExpression regex("^(?=.*?[A-Z])(?=.*?[a-z])(?=.*?[0-9])(?=.*?[#?!@$%^&*-]).{8,}$");  // min. 8 characters, 1 uppercase, 1 lowercase, 1 digit, 1 special character
    if(regex.match(password).hasMatch())
        return true;
    return false;
}

bool dataChange::checkNames(QString name, QString surname){
    static QRegularExpression regex("^[a-zA-ZàáâäãåąčćęèéêëėįìíîïłńòóôöõøùúûüųūÿýżźñçčšžæÀÁÂÄÃÅĄĆČĖĘÈÉÊËÌÍÎÏĮŁŃÒÓÔÖÕØÙÚÛÜŲŪŸÝŻŹÑßÇŒÆČŠŽ∂ð ,.'-]+$");
    if(regex.match(name).hasMatch() && regex.match(surname).hasMatch())
        return true;
    return false;
}

QString tableNameData, tableNameAccount, tableID, tableEmail, tablePassword, tableUserSurname, tableUserName;
QString EMAIL;


void dataChange::checkTableNames(bool st){
    if(st){
        tableNameData = "studentLoginData";
        tableNameAccount = "studentAccounts";
        tableID = "studentID";
        tableEmail = "studentEmail";
        tablePassword = "studentPassword";
        tableUserName = "studentName";
        tableUserSurname = "studentSurname";
    }
    else{
        tableNameData = "professorLoginData";
        tableNameAccount = "professorAccounts";
        tableID = "professorID";
        tableEmail = "professoEmail";
        tablePassword = "professoPassword";
        tableUserName = "professoLoginData";
        tableUserSurname = "professoLoginData";
    }
}

void dataChange::changeEmail(QString email, bool st, QString oldEmail){
    bool ok = checkEmail(email);
    EMAIL = oldEmail;
    qDebug()<<ok;
    checkTableNames(st);
    if(ok){
        QSqlQuery query;
        query.prepare("UPDATE " + tableNameData + " SET " + tableEmail + "  = :newEmail WHERE " + tableEmail + " = :oldEmail");
        query.bindValue(":newEmail", email);
        query.bindValue(":oldEmail", oldEmail);
        if (query.exec()) {
            qDebug() << "Email updated successfully!";
        } else {
            qDebug() << "Error updating email:" << query.lastError().text();
        }
        QMessageBox msgInformation;
        msgInformation.setText("Email changed successfully!");
        msgInformation.exec();
    }
    else{
        QMessageBox msgWarning;
        msgWarning.setText("Email is incorect!\nTry again!");
        msgWarning.exec();
    }
}
void dataChange::changePassword(QString pass, bool st, QString oldPass){
    bool ok = checkEmail(pass);
    qDebug()<<ok;
    checkTableNames(st);
    if(ok){
        QSqlQuery query;
        query.prepare("UPDATE " + tableNameData + " SET " + tableEmail + "  = :newEmail WHERE " + tableEmail + " = :oldEmail");
        query.bindValue(":newEmail", pass);
        query.bindValue(":oldEmail", oldPass);
        if (query.exec()) {
            qDebug() << "Email updated successfully!";
        } else {
            qDebug() << "Error updating email:" << query.lastError().text();
        }
        QMessageBox msgInformation;
        msgInformation.setText("Email changed successfully!");
        msgInformation.exec();
    }
    else{
        QMessageBox msgWarning;
        msgWarning.setText("Email is incorect!\nTry again!");
        msgWarning.exec();
    }
}
void dataChange::changeName(QString name, bool st, QString oldName){
    bool ok = checkNames(name, name);
    qDebug()<<ok;
    checkTableNames(st);
    if(ok){
        QSqlQuery query;
        query.prepare("UPDATE " + tableNameAccount + " SET " + tableUserName + "  = :newName WHERE" + tableID + " = (SELECT " + tableID + " FROM " + tableNameAccount + " WHERE " + tableEmail + " = :email);");
        query.bindValue(":newName", name);
        query.bindValue(":oldName", oldName);
        query.bindValue(":email", EMAIL);
        if (query.exec()) {
            qDebug() << "Name updated successfully!";
        } else {
            qDebug() << "Error updating name:" << query.lastError().text();
        }
        QMessageBox msgInformation;
        msgInformation.setText("Name changed successfully!");
        msgInformation.exec();
    }
    else{
        QMessageBox msgWarning;
        msgWarning.setText("Name is incorect!\nTry again!");
        msgWarning.exec();
    }
}
void dataChange::changeSurname(QString surname, bool st, QString oldSurname){
    bool ok = checkNames(surname, surname);
    qDebug()<<ok;
    checkTableNames(st);
    if(ok){
        QSqlQuery query;
        query.prepare("UPDATE " + tableNameAccount + " SET " + tableUserSurname + "  = :newSurname WHERE " + tableUserSurname + " = :oldSurname");
        query.bindValue(":newSurname", surname);
        query.bindValue(":oldSurname", oldSurname);
        if (query.exec()) {
            qDebug() << "Surname updated successfully!";
        } else {
            qDebug() << "Error updating surname:" << query.lastError().text();
        }
        QMessageBox msgInformation;
        msgInformation.setText("Surname changed successfully!");
        msgInformation.exec();
    }
    else{
        QMessageBox msgWarning;
        msgWarning.setText("Surname is incorect!\nTry again!");
        msgWarning.exec();
    }
}
