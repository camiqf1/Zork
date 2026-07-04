#pragma once

#include <vector>
#include "Entity.h"
#include "Player.h"

class World
{
    public:
        World();

        void addEntity(Entity* entity);

        std::vector<Entity*> getEntities();

        Player* getPlayer();
        void setPlayer(Player* player);

        void update();

    private:
        std::vector<Entity*> entities; 
        Player* player  = nullptr;
    };