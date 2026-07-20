#include <iostream>
#include "include/Student.h"
#include "include/StudentManager.h"

using namespace std;

void showMenu()
{
    cout << "\n=====================================\n";
    cout << " Hostel Accommodation Management System\n";
    cout << "=====================================\n";

    cout << "1. Add Student\n";
    cout << "2. Display All Students\n";
    cout << "3. Exit\n";

    cout << "\nEnter your choice: ";
}

void addStudent(StudentManager &manager)
{
    // We'll move the existing Add Student code here

    int studentID;
    string name;
    string gender;
    string branch;
    int semester;
    string phone;

    cout << "\n===== Add Student =====\n";

    cin.ignore();

    cout << "Enter Student ID: ";
    cin >> studentID;
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Gender: ";
    getline(cin, gender);

    cout << "Enter Branch: ";
    getline(cin, branch);

    cout << "Enter Semester: ";
    cin >> semester;

    cin.ignore();

    cout << "Enter Phone: ";
    getline(cin, phone);

    Student newStudent(
        studentID,
        name,
        gender,
        branch,
        semester,
        phone);
}


int main()
{
    StudentManager manager;
    int choice = 0;

    while (choice != 3)
    {
        showMenu();

        cin >> choice;

        if (choice == 1)
        {
            addStudent(manager);
        }
        else if (choice == 2)
        {
            manager.displayAllStudents();
        }
        else if (choice == 3)
        {
            cout << "\nThank you for using the system.\n";
        }
        else
        {
            cout << "\nInvalid Choice!\n";
        }
    }

    return 0;
}