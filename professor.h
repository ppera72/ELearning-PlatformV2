#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "person.h"

class Professor: public Person
{
public:

    std::string title;
    std::string sciSpec;

    Professor(int id, std::string n, std::string s, Date dateOB, std::string e, std::string p);
    Professor();

    //void addTest(questionFile, startDate, endDate); // maybe check if structure is correct?
    //void editTest(questionFile);

    //void addAssignment(file, startDate, endDate);
    //void editAssignment(file);
    //double gradeAssignment(assignmentID);
};

#endif // PROFESSOR_H
