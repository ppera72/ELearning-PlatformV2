#include "professor.h"

Professor::Professor(int id, std::string n, std::string s, Date dateOB, std::string e, std::string p, std::string t, std::string sSp) : Person(id, n, s, dateOB, e, p), title(t), sciSpec(sSp) {
}

Professor::Professor(){
    Id(0);
    Name("");
    Surname("");
    Date Date("01.01.2000");
    Email("");
    Password("");
    Title("");
    SciSpec("");
}

std::string Professor::Title()
{
    return title;
}

std::string Professor::SciSpec()
{
    return sciSpec;
}

void Professor::Title(std::string t){
    title = t;
}

void Professor::SciSpec(std::string s){
    sciSpec = s;
}
