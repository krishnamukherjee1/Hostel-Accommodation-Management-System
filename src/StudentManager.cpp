#include "../include/StudentManager.h"

#include <iostream>
#include <fstream>

#include "../external/json.hpp"

using namespace std;
using json = nlohmann::json;

void StudentManager::addStudent(const Student &student)
{
    students.push_back(student);
}

void StudentManager::displayAllStudents()
{
    if (students.empty())
    {
        cout << "\nNo students available.\n";
        return;
    }

    for (int i = 0; i < students.size(); i++)
    {
        cout << "\n===== Student " << i + 1 << " =====\n";
        students[i].display();
        cout << endl;
    }
}

Student *StudentManager::searchStudentByID(int id)
{
    for (size_t i = 0; i < students.size(); i++)
    {
        if (students[i].getStudentID() == id)
        {
            return &students[i];
        }
    }

    return nullptr;
}

bool StudentManager::studentIDExists(int id)
{
    for (size_t i = 0; i < students.size(); i++)
    {
        if (students[i].getStudentID() == id)
        {
            return true;
        }
    }

    return false;
}

bool StudentManager::deleteStudentByID(int id)
{
    for (size_t i = 0; i < students.size(); i++)
    {
        if (students[i].getStudentID() == id)
        {
            students.erase(students.begin() + i);
            return true;
        }
    }

    return false;
}

void StudentManager::saveStudents()
{
    json studentsJson = json::array();

    for (const Student &student : students)
    {
        studentsJson.push_back(student.toJson());
    }

    std::ofstream file("data/students.json");

    file << studentsJson.dump(4);
}