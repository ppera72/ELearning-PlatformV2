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
};

#endif // PROFESSOR_H
