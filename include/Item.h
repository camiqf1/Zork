#pragma once

#include "Entity.h"
#include <vector>

class Item : public Entity
{
public:
    Item(std::string name, std::string description);

    void addItem(Item* item);
    Item* removeItem(std::string name);
    std::vector<Item*> getItems();

    void update() override;

private:
    std::vector<Item*> items;
};





