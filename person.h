#ifndef PERSON_H
#define PERSON_H

#include <QString>
#include "date.h"

class Person
{
private:
    std::string name, surname, email, password;
    int id;
    Date dateOfBirth;
public:
    Person(int id, std::string n, std::string s, Date dateOB, std::string e, std::string p);
    Person();

    int Id() const;
    std::string Name() const;
    std::string Surname() const;
    char Status() const;
    std::string Email() const;
    std::string Password() const;
    Date getDate() const;

    void Id(int i);
    void Name(std::string n);
    void Surname(std::string s);
    void Status(char s);
    void Email(std::string e);
    void Password(std::string p);
    void setDate(Date dateOB);
};

#endif // PERSON_H
