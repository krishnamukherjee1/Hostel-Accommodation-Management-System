#ifndef APPLICATION_H
#define APPLICATION_H

#include "StudentManager.h"
#include "RoomManager.h"

class Application
{
private:
    StudentManager studentManager;
    RoomManager roomManager;

public:
    void run();

private:
    void showMenu();
    void addStudent();
    void displayStudents();
    void searchStudent();
    void deleteStudent();

    void addRoom();
    void displayRooms();
    void searchRoom();
    void deleteRoom();

    void allocateStudent();
    void removeStudentAllocation();
};

#endif