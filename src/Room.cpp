#include "../include/Room.h"

using namespace std;

Room::Room()
{
    roomNumber = 0;
    block = "";
    floor = 0;
    capacity = 0;
}

Room::Room(
    int roomNumber,
    string block,
    int floor,
    int capacity)
{
    this->roomNumber = roomNumber;
    this->block = block;
    this->floor = floor;
    this->capacity = capacity;

    cout << "Room Created Successfully!" << endl;
}

int Room::getRoomNumber()
{
    return roomNumber;
}

string Room::getBlock()
{
    return block;
}

int Room::getFloor()
{
    return floor;
}

int Room::getCapacity()
{
    return capacity;
}

vector<int> Room::getStudentIDs()
{
    return studentIDs;
}

bool Room::isAvailable()
{
    return studentIDs.size() < capacity;
}

void Room::display()
{
    cout << "\nRoom Number : " << roomNumber << endl;
    cout << "Block       : " << block << endl;
    cout << "Floor       : " << floor << endl;
    cout << "Capacity    : " << capacity << endl;
    cout << "Occupied    : " << getOccupiedBeds() << endl;
    cout << "Available   : ";

    if (isAvailable())
        cout << "Yes";
    else
        cout << "No";

    cout << endl;
}

void Room::addStudent(int studentID)
{
    studentIDs.push_back(studentID);
}

int Room::getOccupiedBeds()
{
    return studentIDs.size();
}

bool Room::removeStudent(int studentID)
{
    for (int i = 0; i < studentIDs.size(); i++)
    {
        if (studentIDs[i] == studentID)
        {
            studentIDs.erase(studentIDs.begin() + i);
            return true;
        }
    }

    return false;
}