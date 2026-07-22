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
    Student *searchStudentByID(int id);
    bool studentIDExists(int id);
    bool deleteStudentByID(int id);
};

#endif