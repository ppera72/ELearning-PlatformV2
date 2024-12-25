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

    std::vector<std::string> studentData, professorData, studentGrades;

   /* const std::vector<std::string> studMajorCodes;
    const std::vector<std::string> profAvailableTitles = {"Eng.", "MSc", "PhD", "Prof."}; // add a option in register, add to file
    const std::vector<std::string> profAvailableSciSpec; // add majors / codes*/

    void writeToFile(std::string filePath, std::string message);
    void readFromFile(std::string filePath, bool ifStud);
    int getLastID(std::vector<std::string> data);
    void clearFile(std::string filePath);
};

#endif // USERDATA_H
