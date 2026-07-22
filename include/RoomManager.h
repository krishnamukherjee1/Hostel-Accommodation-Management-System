#ifndef ROOMMANAGER_H
#define ROOMMANAGER_H

#include <vector>
#include "Room.h"

using namespace std;

class RoomManager
{
private:
    vector<Room> rooms;

public:
    void addRoom(Room room);

    void displayAllRooms();

    Room* searchRoomByNumber(int roomNumber);

    bool roomNumberExists(int roomNumber);

    bool deleteRoomByNumber(int roomNumber);
};

#endif