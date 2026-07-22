#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <vector>

using namespace std;

class Room
{
private:
    int roomNumber;
    string block;
    int floor;
    int capacity;

    vector<int> studentIDs;

public:
    Room();
    Room(
        int roomNumber,
        string block,
        int floor,
        int capacity);

    int getRoomNumber();
    string getBlock();
    int getFloor();
    int getCapacity();

    vector<int> getStudentIDs();
    bool isAvailable();
    void display();

    void addStudent(int studentID);
    bool removeStudent(int studentID);
    int getOccupiedBeds();
};

#endif