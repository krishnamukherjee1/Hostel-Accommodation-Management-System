#include "../include/StudentManager.h"
#include <iostream>

using namespace std;

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