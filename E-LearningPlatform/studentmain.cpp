#include "studentmain.h"
#include "qsqlquery.h"
#include "ui_studentmain.h"
#include <QInputDialog>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QSqlError>

studentMain::studentMain(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::studentMain)
{
    ui->setupUi(this);


    dataChange DataChange;

    connect(ui->changeEmailButton, &QPushButton::clicked, this, &studentMain::on_changeEmailButton_clicked);
    connect(ui->changePasswordButton, &QPushButton::clicked, this, &studentMain::on_changePasswordButton_clicked);
    connect(ui->changeNameButton, &QPushButton::clicked, this, &studentMain::on_changeNameButton_clicked);
    connect(ui->changeSurnameButton, &QPushButton::clicked, this, &studentMain::on_changeSurnameButton_clicked);
}

studentMain::~studentMain()
{
    delete ui;
}

// MAIN LOGIN PAGE

QString userName, userSurname, userMajor;
void studentMain::bole(){
    QSqlQuery query;
    query.prepare("SELECT studentAccounts.studentName, studentAccounts.studentSurname FROM studentAccounts INNER JOIN studentLoginData ON studentAccounts.studentID = studentLoginData.studentID WHERE studentLoginData.studentEmail = :email");

    query.bindValue(":email", userEmail);

    if (query.exec()) {
        while (query.next()) {
            userName = query.value(0).toString();
            userSurname = query.value(1).toString();
            qDebug() << "Imie:" << userName;
            qDebug() << "Nazwisko:" << userSurname;
        }
    } else {
        qDebug() << "Error executing query:" << query.lastError().text();
    }
}

void studentMain::on_changeEmailButton_clicked(){
    bool ok;
    QString text = QInputDialog::getText(this, tr("Input a valid email!"), tr("Your new email:"), QLineEdit::Normal, QString(), &ok);
    if (ok && !text.isEmpty()){
        DataChange.changeEmail(text, true, userEmail);
    }
    else{
        qDebug()<<"*wrong choice buzzer*";
    }
}

void studentMain::on_changePasswordButton_clicked(){
    bool ok;
    QString text = QInputDialog::getText(this, tr("Input a valid password!"), tr("Your new password:"), QLineEdit::Password, QString(), &ok);
    if (ok && !text.isEmpty()){
        DataChange.changePassword(text, true, userPassword);
    }
    else{
        qDebug()<<"*wrong choice buzzer*";
    }
}

void studentMain::on_changeNameButton_clicked(){
   bool ok;
    QString text = QInputDialog::getText(this, tr("Input a valid name!"), tr("Your new name:"), QLineEdit::Normal, QString(), &ok);
    if (ok && !text.isEmpty()){
        DataChange.changeName(text, true, userName);
    }
    else{
        qDebug()<<"*wrong choice buzzer*";
    }
}

void studentMain::on_changeSurnameButton_clicked(){
    bool ok;
    QString text = QInputDialog::getText(this, tr("Input a valid surname!"), tr("Your new surname:"), QLineEdit::Normal, QString(), &ok);
    if (ok && !text.isEmpty()){
        DataChange.changeSurname(text, true, userSurname);
    }
    else{
        qDebug()<<"*wrong choice buzzer*";
    }
}
// MAIN LOGIN PAGE END
