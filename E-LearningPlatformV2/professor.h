#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "person.h"

class Professor: public Person
{
public:
    QString title;
    QString sciSpec;

    Professor(QString n, QString s, int a, QString e, QString p, Date dateOB);
};

#endif // PROFESSOR_H
