#include "../include/Application.h"
#include <iostream>

using namespace std;

void Application::run()
{
    int choice = 0;

    const int EXIT_OPTION = 11;
    while (choice != EXIT_OPTION)
    {
        showMenu();

        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            displayStudents();
            break;

        case 3:
            searchStudent();
            break;

        case 4:
            deleteStudent();
            break;

        case 5:
            addRoom();
            break;

        case 6:
            displayRooms();
            break;

        case 7:
            searchRoom();
            break;

        case 8:
            deleteRoom();
            break;

        case 9:
            allocateStudent();
            break;

        case 10:
            removeStudentAllocation();
            break;

        case 11:
            cout << "\nThank you for using Hostel Accommodation Management System.\n";
            break;

        default:
            cout << "\nInvalid choice!\n";
        }
    }
}

void Application::showMenu()
{
    cout << "\n=====================================\n";
    cout << " Hostel Accommodation Management System\n";
    cout << "=====================================\n";

    cout << "----------- Student Management -----------\n";
    cout << "1. Add Student\n";
    cout << "2. Display All Students\n";
    cout << "3. Search Student\n";
    cout << "4. Delete Student\n";

    cout << "----------- Room Management -----------\n";
    cout << "5. Add Room\n";
    cout << "6. Display All Rooms\n";
    cout << "7. Search Room\n";
    cout << "8. Delete Room\n\n";

    cout << "----------- Allocation Management -----------\n";
    cout << "9. Allocate Student to Room\n";
    cout << "10. Remove Student Allocation\n";

    cout << "11. Exit\n";

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
    cout << "Enter Student ID: ";
    cin >> studentID;
    cin.ignore();

    if (studentManager.studentIDExists(studentID))
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
    studentManager.addStudent(newStudent);
    cout << "\nStudent added successfully!\n";
}

void Application::displayStudents()
{
    cout << "\n===== Display All Students =====\n";

    studentManager.displayAllStudents();
}

void Application::deleteStudent()
{
    int id;

    cout << "\n===== Delete Student =====\n";

    cout << "Enter Student ID: ";
    cin >> id;

    if (studentManager.deleteStudentByID(id))
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

    Student *student = studentManager.searchStudentByID(id);

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

void Application::addRoom()
{
    int roomNumber;
    string block;
    int floor;
    int capacity;

    cout << "\nEnter Room Number: ";
    cin >> roomNumber;

    if (roomManager.roomNumberExists(roomNumber))
    {
        cout << "\nRoom Number already exists!\n";
        return;
    }
    cout << "Enter Block: ";
    cin >> block;

    cout << "Enter Floor: ";
    cin >> floor;

    cout << "Enter Capacity: ";
    cin >> capacity;

    Room newRoom(roomNumber, block, floor, capacity);
    roomManager.addRoom(newRoom);

    cout << "\nRoom added successfully!\n";
}

void Application::displayRooms()
{
    cout << "\n===== Display All Rooms =====\n";
    roomManager.displayAllRooms();
}

void Application::searchRoom()
{
    int roomNumber;

    cout << "\nEnter Room Number: ";
    cin >> roomNumber;

    Room *room = roomManager.searchRoomByNumber(roomNumber);

    if (room == nullptr)
    {
        cout << "\nRoom not found!\n";
        return;
    }

    room->display();
}

void Application::deleteRoom()
{
    int roomNumber;

    cout << "\nEnter Room Number: ";
    cin >> roomNumber;

    if (roomManager.deleteRoomByNumber(roomNumber))
    {
        cout << "\nRoom deleted successfully!\n";
    }
    else
    {
        cout << "\nRoom not found!\n";
    }
}

void Application::allocateStudent()
{
    int studentID;
    int roomNumber;

    cout << "\n===== Allocate Student =====\n";

    cout << "Enter Student ID: ";
    cin >> studentID;

    Student *student = studentManager.searchStudentByID(studentID);

    if (student == nullptr)
    {
        cout << "\nStudent not found!\n";
        return;
    }

    cout << "Enter Room Number: ";
    cin >> roomNumber;
    Room *room = roomManager.searchRoomByNumber(roomNumber);

    if (room == nullptr)
    {
        cout << "\nRoom not found!\n";
        return;
    }

    if (student->getAllocatedRoomNumber() != -1)
    {
        cout << "\nStudent is already allocated to Room "
             << student->getAllocatedRoomNumber()
             << ".\n";
        return;
    }

    if (!room->isAvailable())
    {
        cout << "\nRoom is already full!\n";
        return;
    }

    room->addStudent(studentID);
    student->setAllocatedRoomNumber(roomNumber);
    cout << "\nStudent allocated successfully!\n";
}

void Application::removeStudentAllocation()
{
    int studentID;

    cout << "\n===== Remove Student Allocation =====\n";

    cout << "Enter Student ID: ";
    cin >> studentID;

    Student *student = studentManager.searchStudentByID(studentID);

    if (student == nullptr)
    {
        cout << "\nStudent not found!\n";
        return;
    }

    if (student->getAllocatedRoomNumber() == -1)
    {
        cout << "\nStudent is not allocated to any room.\n";
        return;
    }

    int roomNumber = student->getAllocatedRoomNumber();

    Room *room = roomManager.searchRoomByNumber(roomNumber);

    if (room == nullptr)
    {
        cout << "\nRoom not found!\n";
        return;
    }

    room->removeStudent(studentID);

    student->setAllocatedRoomNumber(-1);

    cout << "\nStudent allocation removed successfully!\n";
}

