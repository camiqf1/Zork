#include "Item.h"

Item::Item(std::string name, std::string description)
    : Entity(name, description)
{
}

void Item::addItem(Item* item)
{
    items.push_back(item);
}

std::vector<Item*> Item::getItems()
{
    return items;
}

Item* Item::removeItem(std::string name)
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
    return nullptr;
}
void Item::update()
{
}
