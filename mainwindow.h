#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "professor.h"
#include "student.h"
#include "userdata.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    userData UserData;


private:
    Ui::MainWindow *ui;
    void on_pushButton_clicked();
    void on_loginButton_clicked();
    void on_registerButton_clicked();
    bool checkEmail(QString email);
    bool checkPassword(QString password);
    bool checkNames(QString name, QString surname);
    void on_registerToDatabaseButton_clicked();
    void on_backToLoginPageButton_clicked();
    void on_exitButton_clicked();
    bool checkIfInDatabase(std::string email, std::vector<std::string> data);
    bool checkIfPassMatches(std::string email, std::string password, std::vector<std::string> data);
    Student getStudData(std::vector<std::string> &data);
    Professor getProfData(Professor prof);
    void on_SMLogOutButton_clicked();
    void on_PMLogOutButton_clicked();
};
#endif // MAINWINDOW_H
