#include "assignments.h"
#include <fstream>
#include <QDebug>
#include <string>

void Assignments::loadData()
{
    std::string pathAssignment = "C:\\Users\\Patryk\\Desktop\\Praca\\C Plus Plus\\E-LearningPlatformV2\\assignments\\" + assignmentFile; // change path!!!
    std::string pathTest = "C:\\Users\\Patryk\\Desktop\\Praca\\C Plus Plus\\E-LearningPlatformV2\\assignments\\" + testFile; // change path!!!
    std::string pathAssignmentForDisplay = "C:\\Users\\Patryk\\Desktop\\Praca\\C Plus Plus\\E-LearningPlatformV2\\assignments\\" + assignmentFileForDisplay; // change path!!!
    std::string pathTestForDisplay = "C:\\Users\\Patryk\\Desktop\\Praca\\C Plus Plus\\E-LearningPlatformV2\\assignments\\" + testFileForDisplay; // change path!!!
    std::string pathAssignmentToGrade = "C:\\Users\\Patryk\\Desktop\\Praca\\C Plus Plus\\E-LearningPlatformV2\\assignments\\" + assignmentFileToGrade; // change path!!!

    std::ifstream assignmentFile(pathAssignment.c_str());
    std::ifstream testFile(pathTest.c_str());
    std::ifstream assignmentFileForDisplay(pathAssignmentForDisplay.c_str());
    std::ifstream testFileForDisplay(pathTestForDisplay.c_str());
    std::ifstream assignmentFileToGrade(pathAssignmentToGrade.c_str());

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
    if(assignmentFileForDisplay.good()){
        std::string c;
        while(std::getline(assignmentFileForDisplay, c)){
            assignmentListForDisplay.push_back(c);
        }
    }
    if(testFileForDisplay.good()){
        std::string c;
        while(std::getline(testFileForDisplay, c)){
            testListForDisplay.push_back(c);
        }
    }
    if(assignmentFileToGrade.good()){
        std::string c;
        while(std::getline(assignmentFileToGrade, c)){
            assignmentToGrade.push_back(c);
        }
    }
    assignmentFile.close();
    testFile.close();
    assignmentFileForDisplay.close();
    testFileForDisplay.close();
    assignmentFileToGrade.close();
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

void Assignments::addToFile(std::string filePath, std::string message){  // add creating directory
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

std::vector<std::string> Assignments::getTestData(std::string test)
{
    std::vector<std::string> help;
    size_t pos = 0;
    size_t prev = 0;
    while((pos = test.find(';', prev)) != std::string::npos){
        help.push_back(test.substr(prev, pos - prev));
        prev = pos + 1;
    }
    help.push_back(test.substr(prev));
    return help;
}

