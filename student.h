#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"
#include "date.h"
#include <QString>

class Student: public Person
{
private:
    std::string courseCode;
public:
    Student(int id, std::string n, std::string s, Date dateOB, std::string e, std::string p, std::string cC);
    Student();

    std::string CourseCode();
    void CourseCode(std::string cC);
};

#endif // STUDENT_H
