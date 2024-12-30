#include "student.h"

Student::Student(int id, std::string n, std::string s, Date dateOB, std::string e, std::string p, std::string cC) : Person(id, n, s, dateOB, e, p), courseCode(cC){
}

Student::Student(){
    Id(0);
    Name("");
    Surname("");
    Date Date("01.01.2000");
    Email("");
    Password("");
    CourseCode("");
}

std::string Student::CourseCode(){
    return courseCode;
}

void Student::CourseCode(std::string cC){
    courseCode = cC;
}
