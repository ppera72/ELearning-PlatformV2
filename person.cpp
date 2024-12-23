#include "person.h"

Person::Person(int id, std::string n, std::string s, Date dateOB, std::string e, std::string p): name(n), surname(s), email(e), password(p), id(id), dateOfBirth(dateOB){}

std::string Person::Name() const
{
    return name;
}

std::string Person::Surname() const
{
    return surname;
}

std::string Person::Email() const
{
    return email;
}

std::string Person::Password() const
{
    return password;
}

Date Person::setDate() const
{
    return dateOfBirth;
}

void Person::Name(std::string n)
{
    name = n;
}

void Person::Surname(std::string s)
{
    surname = s;
}


void Person::Email(std::string e)
{
    email = e;
}

void Person::Password(std::string p)
{
    password = p;
}

void Person::getDate(Date dateOB)
{
    dateOfBirth = dateOB;
}
