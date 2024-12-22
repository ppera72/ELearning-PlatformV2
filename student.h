#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"
#include "date.h"
#include <QString>

class Student: public Person
{
public:
    char courseCode[4];

    Student(QString n, QString s, int a, QString e, QString p, Date dateOB);
    //int startTest(std::string testName); ?
    //void sendAssignment(file);

};

#endif // STUDENT_H
