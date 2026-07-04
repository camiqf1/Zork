#pragma once

#include "Entity.h"
#include "Room.h"

enum class Direction
{
    NORTH,
    SOUTH,
    EAST,
    WEST,
    UP,
    DOWN
};

class Exit : public Entity
{
public:
    Exit(std::string name,
         std::string description,
         Direction direction,
         Room* sourceRoom,
         Room* destinationRoom);

    Direction getDirection();
    Room* getSourceRoom();
    Room* getDestinationRoom();

    bool isLocked();
    void setLocked(bool locked);

    void update() override;

private:
    Direction direction;
    Room* sourceRoom;
    Room* destinationRoom;
    bool locked = false;
};