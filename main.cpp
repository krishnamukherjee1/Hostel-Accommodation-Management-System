#include <iostream>
#include <vector>
#include "include/Student.h"

using namespace std;

int main()
{
    // Student student1;
    Student student1(
        101,
        "Krishna Mukherjee",
        "Male",
        "CSE",
        8,
        "9876543210");

    Student student2(
        102,
        "Rahul Sharma",
        "Male",
        "ECE",
        6,
        "9876500000");

    Student student3(
        103,
        "Priya Das",
        "Female",
        "EE",
        4,
        "9123456789");

    // Create an empty vector
    vector<Student> students;

    students.push_back(student1);
    students.push_back(student2);
    students.push_back(student3);

    for (int i = 0; i < students.size(); i++)
    {
        cout << "\n===== Student " << i + 1 << " =====\n";
        students[i].display();
    }

    return 0;
}