#include "Entity.h"

//Constructor for the Entity class, initializes the entity with a name and description
Entity::Entity(std::string name, std::string description)
{
    this->name = name;
    this->description = description;
}

std::string Entity::getName()
{
    return this->name;
}

std::string Entity::getDescription()
{
    return this->description;
}

void Entity::update()
{
}