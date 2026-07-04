#pragma once

#include <string>
#include <vector>
#include "Item.h"
#include "Room.h"
#include "Creature.h"

class Player : public Creature
{
public:
    Player(std::string name, std::string description, Room* startingRoom);

    Room* getCurrentRoom();
    void setCurrentRoom(Room* room);

    void addItem(Item* item);
    Item* removeItem(std::string name);

    std::vector<Item*> getInventory();

private:
    Room* currentRoom;
    std::vector<Item*> inventory;
};

