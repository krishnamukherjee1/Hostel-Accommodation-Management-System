#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include <vector>
#include "Student.h"

class StudentManager
{
private:
    std::vector<Student> students;

public:
    void addStudent(const Student &student);
    void displayAllStudents();
};

#endif