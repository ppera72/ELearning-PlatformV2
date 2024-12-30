#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "userdata.h"
#include "student.h"
#include "professor.h"
#include "assignments.h"

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
    Student currentStudent;
    Professor currentProfessor;
    Assignments assignments;

    bool checkEmail(QString email);
    bool checkPassword(QString password);
    bool checkNames(QString name, QString surname);


private:
    Ui::MainWindow *ui;
    void on_loginButton_clicked();
    void on_registerButton_clicked();

    void on_registerToDatabaseButton_clicked();
    void on_backToLoginPageButton_clicked();
    void on_exitButton_clicked();
    bool checkIfInDatabase(std::string email, std::vector<std::string> data);
    bool checkIfPassMatches(std::string email, std::string password, std::vector<std::string> data);
    Student getStudData(std::vector<std::string> data);
    Professor getProfData(std::vector<std::string> data);

    void on_SMLogOutButton_clicked();
    void on_PMLogOutButton_clicked();

    void on_SMChangeEmailButton_clicked();
    void on_SMChangePasswordButton_clicked();
    void on_SMChangeNameButton_clicked();
    void on_SMChangeSurnameButton_clicked();

    void on_PMAddNewAssignment_clicked();
    void on_PMAddNewTest_clicked();

    void on_AAAddButton_clicked();
    void on_AACancelButton_clicked();

    void on_ATAddQuestionsButton_clicked();
    void on_ATAddTestButton_clicked();
    void on_ATCancelButton_clicked();
    void on_ATAQAddQuestionsButton_clicked();
    void on_ATAQConfirmQuestionsButton_clicked();
    void on_ATAQCancelButtonn_clicked();

};
#endif // MAINWINDOW_H
