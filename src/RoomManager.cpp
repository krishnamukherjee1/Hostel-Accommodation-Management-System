#include "../include/RoomManager.h"

using namespace std;

void RoomManager::addRoom(Room room)
{
    rooms.push_back(room);
}

void RoomManager::displayAllRooms()
{
    if (rooms.empty())
    {
        cout << "\nNo rooms available.\n";
        return;
    }

    for (int i = 0; i < rooms.size(); i++)
    {
        cout << "\n===== Room " << i + 1 << " =====\n";

        rooms[i].display();
    }
}

Room* RoomManager::searchRoomByNumber(int roomNumber)
{
    for (int i = 0; i < rooms.size(); i++)
    {
        if (rooms[i].getRoomNumber() == roomNumber)
        {
            return &rooms[i];
        }
    }

    return nullptr;
}

bool RoomManager::roomNumberExists(int roomNumber)
{
    return searchRoomByNumber(roomNumber) != nullptr;
}

bool RoomManager::deleteRoomByNumber(int roomNumber)
{
    for (int i = 0; i < rooms.size(); i++)
    {
        if (rooms[i].getRoomNumber() == roomNumber)
        {
            rooms.erase(rooms.begin() + i);
            return true;
        }
    }

    return false;
}