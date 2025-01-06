#ifndef ASSIGNMENTS_H
#define ASSIGNMENTS_H

#include <string>
#include <vector>
class Assignments
{
public:
    int assignmentLastID, testLastID;

    std::vector<std::string> assignmentList, assignmentListForDisplay, assignmentToGrade;
    std::vector<std::string> testList, testListForDisplay;
    std::vector<std::string> currentTestData;

    const std::string assignmentFile = "assignments.txt";
    const std::string testFile = "tests.txt";
    const std::string assignmentFileForDisplay = "assignmentsDisplay.txt";
    const std::string testFileForDisplay = "testsDisplay.txt";
    const std::string assignmentFileToGrade = "assignmentsToGrade.txt";

    void loadData();
    void clearFile(std::string fileName);
    int getLastID(std::vector<std::string> data);

    void addToFile(std::string filePath, std::string message);

    void startTest();
    std::vector<std::string> getTestData(std::string test);
    void sendAssginment(std::string filePath);
    // void gradeAssignment(std::string filePath); ???

};

#endif // ASSIGNMENTS_H
