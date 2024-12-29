#include "assignments.h"
#include <fstream>

void Assignments::addTest(std::string filePath, std::string message){
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

void  Assignments::addAssginment(std::string filePath, std::string message){
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
