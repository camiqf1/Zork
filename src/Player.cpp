#include "Player.h"

// Constructor for the Player class, initializes the current room to the starting room
Player::Player(std::string name,
               std::string description,
               Room* startingRoom)
    : Creature(name, description)
{
    this->currentRoom = startingRoom;
}

Room* Player::getCurrentRoom()
{
    return this->currentRoom;
}

void Player::setCurrentRoom(Room* room)
{
    this->currentRoom = room;
}

std::vector<Item*> Player::getInventory()
{
    return this->inventory;
}

void Player::addItem(Item* item)
{
    this->inventory.push_back(item);
}

Item* Player::removeItem(std::string name)
{
    for (int i = 0; i < this->inventory.size(); i++)
    {
        if (this->inventory[i]->getName() == name)
        {
            Item* item = this->inventory[i];
            this->inventory.erase(this->inventory.begin() + i);
            return item;
        }
    }

    return nullptr;
}
