#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "person.h"

class Professor: public Person
{
public:

    QString title;
    QString sciSpec;

    Professor(QString n, QString s, int a, QString e, QString p, Date dateOB);

    //void addTest(questionFile, startDate, endDate); // maybe check if structure is correct?
    //void editTest(questionFile);

    //void addAssignment(file, startDate, endDate);
    //void editAssignment(file);
    //double gradeAssignment(assignmentID);
};

#endif // PROFESSOR_H
