#include "../include/Application.h"
#include <iostream>

using namespace std;

void Application::run()
{
    int choice = 0;

    while (choice != 5)
    {
        showMenu();

        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            manager.displayAllStudents();
            break;

        case 3:
            searchStudent();
            break;

        case 4:
            deleteStudent();
            break;

        case 5:
            cout << "\nThank you for using the system.\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }
    }
}

void Application::showMenu()
{
    cout << "\n=====================================\n";
    cout << " Hostel Accommodation Management System\n";
    cout << "=====================================\n";

    cout << "1. Add Student\n";
    cout << "2. Display All Students\n";
    cout << "3. Search Student\n";
    cout << "4. Delete Student\n";
    cout << "5. Exit\n";

    cout << "\nEnter your choice: ";
}

void Application::addStudent()
{
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
    manager.addStudent(newStudent);
    // Debugging output to verify that the student was added
    // cout << "\nDEBUG: After adding:\n";
    // manager.displayAllStudents();
    cout << "\nStudent added successfully!\n";
}

void Application::deleteStudent()
{
    int id;

    cout << "\n===== Delete Student =====\n";

    cout << "Enter Student ID: ";
    cin >> id;

    if (manager.deleteStudentByID(id))
    {
        cout << "\nStudent deleted successfully!\n";
    }
    else
    {
        cout << "\nStudent not found.\n";
    }
}

void Application::searchStudent()
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
