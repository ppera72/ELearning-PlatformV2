#include "person.h"

Person::Person(QString n, QString s, int a, QString e, QString p, Date dateOB): name(n), surname(s), email(e), password(p), age(a), dateOfBirth(dateOB){}

QString Person::Name() const
{
    return name;
}

QString Person::Surname() const
{
    return surname;
}

int Person::Age() const
{
    return age;
}

QString Person::Email() const
{
    return email;
}

QString Person::Password() const
{
    return password;
}

Date Person::setDate() const
{
    return dateOfBirth;
}

void Person::Name(QString n)
{
    name = n;
}

void Person::Surname(QString s)
{
    surname = s;
}

void Person::Age(int a)
{
    age = a;
}

void Person::Email(QString e)
{
    email = e;
}

void Person::Password(QString p)
{
    password = p;
}

void Person::getDate(Date dateOB)
{
    dateOfBirth = dateOB;
}
