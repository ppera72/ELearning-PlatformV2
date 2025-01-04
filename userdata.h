#ifndef USERDATA_H
#define USERDATA_H

#include <string>
#include <vector>

class userData
{
public:
    int lastID;

    const std::string studFileName = "studData.txt";
    const std::string profFileName = "profData.txt";
    const std::string studGradesFileName = "studGrades.txt";

    std::vector<std::string> studentData, professorData, studentGrades;

    void writeToFile(std::string filePath, std::string message);
    void readFromFile(std::string filePath, bool ifStud);
    int getLastID(std::vector<std::string> data);
    void clearFile(std::string filePath);
    double assignAGrade(int corrAnswers, int numOfQuestions);
};

#endif // USERDATA_H
