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

    std::vector<std::string> studentData, professorData;

    void writeToFile(std::string filePath, std::string message);
    void readFromFile(std::string filePath, bool ifStud);
    int getLastID(std::vector<std::string> data);
};

#endif // USERDATA_H
