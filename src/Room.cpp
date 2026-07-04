#include "Room.h"

Room::Room(std::string name, std::string description)
    : Entity(name, description)
{
}

void Room::addItem(Item* item)
{
    items.push_back(item);
}

std::vector<Item*> Room::getItems()
{
    return items;
}

void Room::update()
{
    // Update the room's state or perform any necessary actions
    // Can update the items in the room
    for (Item* item : items)
    {
        item->update();
    }
}

Item* Room::removeItem(std::string name)
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i]->getName() == name)
        {
            Item* item = items[i];
            items.erase(items.begin() + i);
            return item;
        }
    }

    return nullptr; // Return nullptr if the item is not found
    }