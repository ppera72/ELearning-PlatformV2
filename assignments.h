#ifndef ASSIGNMENTS_H
#define ASSIGNMENTS_H

#include <string>
#include <vector>
class Assignments
{
public:
    int assignmentLastID, testLastID;

    std::vector<std::string> assignmentList;
    std::vector<std::string> testList;
    std::vector<std::string> currentTestData;

    const std::string assignmentFile = "assignments.txt";
    const std::string testFile = "tests.txt";

    void loadData();
    int getLastID(std::vector<std::string> data);

    void addToFile(std::string filePath, std::string message);

    void startTest();
    std::vector<std::string> getTestData(std::string test);
    void sendAssginment(std::string filePath);
    // void gradeAssignment(std::string filePath); ???

};

#endif // ASSIGNMENTS_H
