#pragma once

#include <vector>
#include "Entity.h"
#include "Item.h"

class Room : public Entity
{
public:
    Room(std::string name, std::string description);

    void addItem(Item* item);
    Item* removeItem(std::string name);
    std::vector<Item*> getItems();

    void update() override;

private:
    std::vector<Item*> items;
};
