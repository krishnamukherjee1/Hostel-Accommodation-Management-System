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
    cout << "3. Search Student\n";
    cout << "4. Exit\n";

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

    if (manager.studentIDExists(studentID))
{
    cout << "\nStudent ID already exists!\n";
    cout << "Student was not added.\n";
    return;
}

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

void searchStudent(StudentManager &manager)
{
    int id;

    cout << "\n===== Search Student =====\n";

    cout << "Enter Student ID: ";
    cin >> id;

    Student *student = manager.searchStudentByID(id);

    if (student != nullptr)
    {
        cout << "\nStudent Found!\n\n";
        student->display();
    }
    else
    {
        cout << "\nStudent not found.\n";
    }
}

int main()
{
    StudentManager manager;
    int choice = 0;

    while (choice != 4)
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
            searchStudent(manager);
        }
        else if (choice == 4)
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