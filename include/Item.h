#pragma once

#include "Entity.h"

class Item : public Entity
{
public:
    Item(std::string name, std::string description);

    void update() override;
};





