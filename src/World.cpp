#include "World.h"

//Constructor for the World class, initializes the world with no entities and no player

World::World()
{
    this->entities = std::vector<Entity*>();
    this->player = nullptr;
}

std::vector<Entity*> World::getEntities()
{
    return this->entities;
}

Player* World::getPlayer()
{
    return this->player;
}

void World::setPlayer(Player* player)
{
    this->player = player;
}

void World::addEntity(Entity* entity)
{
    this->entities.push_back(entity);
}

void World::update()
{
    for (Entity* entity : this->entities)
    {
        entity->update();
    }
}