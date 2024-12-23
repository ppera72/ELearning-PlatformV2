#ifndef ASSIGNMENTS_H
#define ASSIGNMENTS_H

#include "date.h"
class Assignments
{
private:
    int testID, taskID;
    std::string fileName;
    char courseCode[4];//?
   // Date beginDate, endDate;
    double grade;
public:
    Assignments();
};

#endif // ASSIGNMENTS_H
