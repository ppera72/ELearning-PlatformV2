#include "userdata.h"
#include <fstream>
#include <sstream>
#include <QDebug>
void userData::writeToFile(std::string filePath, std::string message)
{
    std::string path = "C:\\Users\\Patryk\\Desktop\\Praca\\C Plus Plus\\E-LearningPlatformV2\\userData\\" + filePath; // change path!!!
    std::ifstream File(path.c_str());
    if(File.good()){
        std::ofstream File(path, std::ios_base::app);
        File << message + "\n";
    }
    else{
        std::ofstream File(path);
        File << message + "\n";
    }
    File.close();
}

void userData::loadData()
{
    std::string profPath = "C:\\Users\\Patryk\\Desktop\\Praca\\C Plus Plus\\E-LearningPlatformV2\\userData\\" + profFileName; // change path!!!
    std::string studPath = "C:\\Users\\Patryk\\Desktop\\Praca\\C Plus Plus\\E-LearningPlatformV2\\userData\\" + studFileName; // change path!!!
    std::string studGradesPath = "C:\\Users\\Patryk\\Desktop\\Praca\\C Plus Plus\\E-LearningPlatformV2\\userData\\" + studGradesFileName; // change path!!!

    std::ifstream profFile(profPath.c_str());
    std::ifstream studFile(studPath.c_str());
    std::ifstream studGradesFile(studGradesPath.c_str());

    if(profFile.good()){
        std::string c;
        while(profFile >> c){
            professorData.push_back(c);
        }
        lastID = getLastID(professorData);
    }

    if(studFile.good()){
        std::string c;
        while(studFile >> c){
            studentData.push_back(c);
        }
        lastID = getLastID(studentData);
    }

    if(studGradesFile.good()){
        std::string c;
        while(studGradesFile >> c){
            studentGrades.push_back(c);
        }
    }

    profFile.close();
    studFile.close();
    studGradesFile.close();
}

int userData::getLastID(std::vector<std::string> data)
{
    int id = 0;
    if(data.size() == 0){
        return id;
    }
    std::string lastEntry = data.back();
    for(unsigned long long i = 0; i < lastEntry.length(); i++){
        if(lastEntry[i] == ';'){
            id = stoi(lastEntry.substr(0, i));
            break;
        }
    }
    return id;
}

void userData::clearFile(std::string filePath)
{
    std::string path = "C:\\Users\\Patryk\\Desktop\\Praca\\C Plus Plus\\E-LearningPlatformV2\\userData\\" + filePath; // change path!!!
    std::ifstream File(path.c_str());
    if(File.good()){
        std::ofstream File(path, std::ofstream::out | std::ofstream::trunc);
        File.close();
    }
}

std::string userData::assignAGrade(int corrAnswers, int numOfQuestions)
{
    int procent = (float)corrAnswers / numOfQuestions * 100;
    float retValue;
    switch(procent){
        case 0 ... 50:
            retValue = 2.0;
            break;
        case 51 ... 60:
            retValue = 3.0;
            break;
        case 61 ... 70:
            retValue = 3.5;
            break;
        case 71 ... 80:
            retValue = 4.0;
            break;
        case 81 ... 90:
            retValue = 4.5;
            break;
        case 91 ... 100:
            retValue = 5.0;
            break;
        default:
            retValue = 2.0;
            break;
    }
    std::ostringstream os;
    os<<retValue;
    return os.str();
}
