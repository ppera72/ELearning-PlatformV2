#include "professor.h"

Professor::Professor(int id, std::string n, std::string s, Date dateOB, std::string e, std::string p, std::string t, std::string sSp) : Person(id, n, s, dateOB, e, p), title(t), sciSpec(sSp) {
}

Professor::Professor(){
    id = 0;
    name = "";
    surname = "";
    email = "";
    password = "";
    title = "";
    sciSpec = "";
}
