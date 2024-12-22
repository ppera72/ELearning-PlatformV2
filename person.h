#ifndef PERSON_H
#define PERSON_H

#include <QString>
#include "date.h"

class Person
{
public:
    QString name, surname, email, password;
    int age;
    Date dateOfBirth;


    Person(QString n, QString s, int a, QString e, QString p, Date dateOB);
    QString Name() const;
    QString Surname() const;
    int Age() const;
    char Status() const;
    QString Email() const;
    QString Password() const;
    Date setDate() const;

    void Name(QString n);
    void Surname(QString s);
    void Age(int a);
    void Status(char s);
    void Email(QString e);
    void Password(QString p);
    void getDate(Date dateOB);
};

#endif // PERSON_H
