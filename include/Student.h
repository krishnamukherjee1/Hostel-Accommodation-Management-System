#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student
{
private:
    int studentID;
    std::string name;

public:
    Student();
    void setName(std::string studentName);
    std::string getName();
};

#endif