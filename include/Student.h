#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student
{
private:
    int studentID;
    std::string name;
    std::string gender;
    std::string branch;
    int semester;
    std::string phone;
    int allocatedRoomNumber; // Initialize to -1 to indicate no room allocated

public:
    Student();

    Student(
        int id,
        std::string studentName,
        std::string studentGender,
        std::string studentBranch,
        int studentSemester,
        std::string studentPhone);

    void setName(std::string studentName);

    std::string getName();
    int getStudentID();
    std::string getGender();
    std::string getBranch();
    int getSemester();
    std::string getPhone();

    void display();

    int getAllocatedRoomNumber();
    void setAllocatedRoomNumber(int roomNumber);
};

#endif