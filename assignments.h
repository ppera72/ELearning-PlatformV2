#ifndef ASSIGNMENTS_H
#define ASSIGNMENTS_H

#include <string>
#include <vector>
class Assignments
{
public:
    std::vector<std::string> assignmentList;
    std::vector<std::string> testList;

    const std::string assignmentFile = "assignments.txt";
    const std::string testFile = "tests.txt";

    void loadData();

    void addTest(std::string filePath, std::string message);
    void addAssginment(std::string filePath, std::string message);

    void startTest(); // ?
    void sendAssginment(std::string filePath);
    // void gradeAssignment(std::string filePath); ???
};

#endif // ASSIGNMENTS_H
