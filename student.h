#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"
#include "date.h"
#include <QString>

class Student: public Person
{
public:
    std::string courseCode;

    Student(int id, std::string n, std::string s, Date dateOB, std::string e, std::string p, std::string cC);
    Student();
    //int startTest(std::string testName); ?
    //void sendAssignment(file);

};

#endif // STUDENT_H
