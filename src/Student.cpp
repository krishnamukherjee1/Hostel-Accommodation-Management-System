#include <iostream>
#include "../include/Student.h"

using namespace std;

Student::Student()
{
    studentID = 0;
    cout << "Student Constructor Called!" << endl;
}
void Student::setName(std::string studentName)
{
    name = studentName;
}
std::string Student::getName()
{
    return name;
}