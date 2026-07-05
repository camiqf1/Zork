#pragma once

#include <string>
#include <vector>

#include "World.h"
#include "Room.h"
#include "Item.h"
#include "Exit.h"
#include "Player.h"

class Game
{
    public:
        Game();

        void start();

    private:
        World world;
        bool running = true;
        bool checkWinCondition();

        std::string directionToString(Direction direction);
        
        void createWorld();
        void showIntro();
        void showCurrentRoom();
        void processCommand(std::string command);

        void handleLook();
        void handleInventory();
        void handleTake(std::string itemName);
        void handleDrop(std::string itemName);
        void handleGo(std::string direction);

        void endGame();
};