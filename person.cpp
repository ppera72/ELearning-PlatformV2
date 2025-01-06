#include "person.h"

Person::Person(int i, std::string n, std::string s, Date dateOB, std::string e, std::string p): name(n), surname(s), email(e), password(p), id(i), dateOfBirth(dateOB){}

Person::Person(){
    id = 0;
    name = "";
    surname = "";
    email = "";
    password = "";
}

int Person::Id() const
{
    return id;
}

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

Date Person::getDate() const
{
    return dateOfBirth;
}

void Person::Id(int i){
    id = i;
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

void Person::setDate(Date dateOB)
{
    dateOfBirth = dateOB;
}
