#pragma once

#include <string>
#include <vector>

#include "Entity.h"
#include "Item.h"

class Exit;

// Declaring Room class - Blueprint for rooms in the game

class Room : public Entity
{
public:
    Room(std::string name, std::string description);

    void addItem(Item* item);
    Item* removeItem(std::string name);
    std::vector<Item*> getItems();

    void addExit(Exit* exit);
    std::vector<Exit*> getExits();

    void update() override;

private:
    std::vector<Item*> items;
    std::vector<Exit*> exits;
};
