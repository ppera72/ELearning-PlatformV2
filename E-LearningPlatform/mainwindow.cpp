#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRegularExpression>
#include <QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QWidget>
#include <QRadioButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->testButton, &QPushButton::clicked, this, &MainWindow::on_testButton_clicked);
    if(professorStatus){
        ui->stackedWidget->setCurrentIndex(0);
    }
    else{
        ui->stackedWidget->setCurrentIndex(1);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_testButton_clicked()
{
    ui->testLabel1->setText(userEmail);
    ui->testLabel2->setText(userPassword);
    qDebug()<<studentStatus;
    qDebug()<<professorStatus;

}

