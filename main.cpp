#include <iostream>
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

    cout << "\n===== Student 1 =====\n";
    student1.display();

    cout << endl;

    student2.display();

    cout << endl;

    student3.display();

    cout << "=====================================\n";
    cout << " Hostel Accommodation Management System\n";
    cout << " Version 1.1\n";
    cout << "=====================================\n";

    return 0;
}