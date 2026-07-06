#pragma once

#include "Entity.h"

class Creature : public Entity
{
public:
    Creature(std::string name, std::string description);

    void update() override;
};
