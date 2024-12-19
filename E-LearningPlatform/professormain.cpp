#include "professormain.h"
#include "ui_professormain.h"
#include <QDebug>

professorMain::professorMain(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::professorMain)
{
    ui->setupUi(this);


    connect(ui->test, &QPushButton::clicked, this, &professorMain::on_test_clicked);
}

professorMain::~professorMain()
{
    delete ui;
}

void professorMain::on_test_clicked(){
    qDebug()<<userEmail;
    qDebug()<<userPassword;
}


