#include "Exit.h"

//Constructor for the Exit class, initializes the exit with a name, description, direction, source room, and destination room
Exit::Exit(std::string name,
           std::string description,
           Direction direction,
           Room* sourceRoom,
           Room* destinationRoom)
    : Entity(name, description)
{
    this->direction = direction;
    this->sourceRoom = sourceRoom;
    this->destinationRoom = destinationRoom;
}

Direction Exit::getDirection()
{
    return this->direction;
}

Room* Exit::getSourceRoom()
{
    return this->sourceRoom;
}

Room* Exit::getDestinationRoom()
{
    return this->destinationRoom;
}

bool Exit::isLocked()
{
    return this->locked;
}

void Exit::setLocked(bool locked)
{
    this->locked = locked;
}

void Exit::update()
{
    // Update logic for the exit        
}