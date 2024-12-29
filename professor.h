#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "person.h"
#include "date.h"

class Professor: public Person
{
private:
    std::string title;
    std::string sciSpec;
public:
    Professor(int id, std::string n, std::string s, Date dateOB, std::string e, std::string p, std::string t, std::string sSp);
    Professor();

    std::string Title();
    std::string SciSpec();
};

#endif // PROFESSOR_H
