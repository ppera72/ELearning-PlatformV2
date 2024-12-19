#pragma once
#include <QDialog>

namespace Ui {
class professorMain;
}

class professorMain : public QDialog
{
    Q_OBJECT

public:
    explicit professorMain(QWidget *parent = nullptr);
    ~professorMain();

    QString userEmail, userPassword;

private:
    Ui::professorMain *ui;

    void on_test_clicked();
    void abc();
};

