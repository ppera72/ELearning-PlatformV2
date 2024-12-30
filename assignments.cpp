#include "assignments.h"
#include <fstream>
#include <QDebug>
#include <string>

void Assignments::loadData()
{
    std::string pathAssignment = "C:\\Users\\Patryk\\Desktop\\Praca\\C Plus Plus\\E-LearningPlatformV2\\assignments\\" + assignmentFile; // change path!!!
    std::string pathTest = "C:\\Users\\Patryk\\Desktop\\Praca\\C Plus Plus\\E-LearningPlatformV2\\assignments\\" + testFile; // change path!!!

    std::ifstream assignmentFile(pathAssignment.c_str());
    std::ifstream testFile(pathTest.c_str());

    if(assignmentFile.good()){
        std::string c;
        while(std::getline(assignmentFile, c)){
            assignmentList.push_back(c);
        }
        assignmentLastID = getLastID(assignmentList);
    }

    if(testFile.good()){
        std::string c;
        while(std::getline(testFile, c)){
            testList.push_back(c);
        }
        testLastID = getLastID(testList);
    }

    assignmentFile.close();
    testFile.close();
}

int Assignments::getLastID(std::vector<std::string> data)
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

void Assignments::addTest(std::string filePath, std::string message){  // maybe merge with addAssignment
    std::string path = "C:\\Users\\Patryk\\Desktop\\Praca\\C Plus Plus\\E-LearningPlatformV2\\assignments\\" + filePath; // change path!!!
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

void Assignments::addAssginment(std::string filePath, std::string message){
    std::string path = "C:\\Users\\Patryk\\Desktop\\Praca\\C Plus Plus\\E-LearningPlatformV2\\assignments\\" + filePath; // change path!!!
    std::ifstream File(path.c_str());
    if(File.good()){
        std::ofstream File(path, std::ios_base::app);
        File << message + "\n";
    }
    else{
        std::ofstream File(path);
        File << message + "\n";
        qDebug()<<"Created a file";
    }
    File.close();
}
