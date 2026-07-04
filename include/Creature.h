#pragma once

#include "Enity.h"

class Creature : Public Entity
{
public:
    Creature(std::string name, std::string description);

    void update() override;
};
