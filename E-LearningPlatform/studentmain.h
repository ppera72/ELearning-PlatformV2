#pragma once


#include "qsqldatabase.h"
#include "datachange.h"
#include <QDialog>

namespace Ui {
class studentMain;
}

class studentMain : public QDialog
{
    Q_OBJECT

public:
    explicit studentMain(QWidget *parent = nullptr);
    ~studentMain();

    QString userEmail, userPassword;
    void bole();
    dataChange DataChange;

private:
    Ui::studentMain *ui;
    void on_changeEmailButton_clicked();
    void on_changePasswordButton_clicked();
    void on_changeNameButton_clicked();
    void on_changeSurnameButton_clicked();

};

