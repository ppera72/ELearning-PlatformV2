#include "student.h"

Student::Student(int id, std::string n, std::string s, Date dateOB, std::string e, std::string p, std::string cC) : Person(id, n, s, dateOB, e, p), courseCode(cC){
}

Student::Student(){
    id = 0;
    name = "";
    surname = "";
    email = "";
    password = "";
    courseCode = "";
}

std::string Student::CourseCode(){
    return courseCode;
}
