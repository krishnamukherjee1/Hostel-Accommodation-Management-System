#include <iostream>
#include "../include/Student.h"

using namespace std;

Student::Student()
{
    studentID = 0;
    name = "";
    gender = "";
    branch = "";
    semester = 0;
    phone = "";
    allocatedRoomNumber = -1; // Initialize to -1 to indicate no room allocated
    cout << "Student Constructor Called!" << endl;
}

Student::Student(
    int id,
    std::string studentName,
    std::string studentGender,
    std::string studentBranch,
    int studentSemester,
    std::string studentPhone)
{
    studentID = id;
    name = studentName;
    gender = studentGender;
    branch = studentBranch;
    semester = studentSemester;
    phone = studentPhone;
    allocatedRoomNumber = -1;

    cout << "Parameterized Constructor Called!" << endl;
}

void Student::setName(std::string studentName)
{
    name = studentName;
}

void Student::display()
{
    cout << "ID: " << studentID << endl;
    cout << "Name: " << name << endl;
    cout << "Gender: " << gender << endl;
    cout << "Branch: " << branch << endl;
    cout << "Semester: " << semester << endl;
    cout << "Phone: " << phone << endl;
    cout << "Allocated Room: ";
    if (allocatedRoomNumber == -1)
        cout << "Not Allocated";
    else
        cout << allocatedRoomNumber;
    cout << endl;
}

std::string Student::getName()
{
    return name;
}

int Student::getStudentID()
{
    return studentID;
}

std::string Student::getGender()
{
    return gender;
}

std::string Student::getBranch()
{
    return branch;
}

int Student::getSemester()
{
    return semester;
}

std::string Student::getPhone()
{
    return phone;
}

int Student::getAllocatedRoomNumber()
{
    return allocatedRoomNumber;
}

void Student::setAllocatedRoomNumber(int roomNumber)
{
    allocatedRoomNumber = roomNumber;
}