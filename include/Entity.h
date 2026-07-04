#pragma once

#include <string>

class Entity
{
public:
    Entity(std::string name, std::string description);

    std::string getName();
    std::string getDescription();

    virtual void update();

protected:
    std::string name;
    std::string description;
};