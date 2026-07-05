#include "Game.h"
#include <iostream>
#include <string>


Game::Game()
 {
    this->createWorld();
 }  

//World intro
void Game::showIntro()
{
    std::cout << "=========================================\n";
    std::cout << "           HELP THE SAD GHOST\n";
    std::cout << "=========================================\n\n";
    std::cout << "You stand outside an abandoned mansion.\n";
    std::cout << "A cold breeze blows.\n";
    std::cout << "Locals say a sad ghost is trapped inside.\n\n";

    std::cout << "Find essential items to help you.\n";
    std::cout << "Find what the ghost cherished most.\n";
    std::cout << "Unlock the master bedroom,\n";
    std::cout << "and help the ghost find peace.\n\n";

    std::cout << "Type 'help' to see available commands.\n\n";
}

//World layout
void Game::createWorld()
{
    Room* outsidePorch = new Room("Outside Porch", "You stand on the porch of the abandoned mansion.");
    Room* entranceHall = new Room("Entrance Hall", "A dark hall filled with dust, old portraits, and eerie air.");
    Room* library = new Room("Library", "Old books cover the walls. A strange sadness fills the room.");
    Room* kitchen = new Room("Kitchen", "Rusty pans hang from the ceiling. Something smells rotten.");
    Room* office = new Room("Office", "An old office with a broken desk and scattered papers.");
    Room* masterBedroom = new Room("Master Bedroom", "A locked door stands before you. The air feels heavy and cold.");
    Room* secondFloor = new Room("Second Floor", "The stairs end in a narrow hallway.");

    Item* lantern = new Item("lantern", "An old lantern. It helps you see inside the mansion.");
    Item* backpack = new Item("backpack", "A worn backpack that can store items.");
    Item* map = new Item("map", "A faded map of the mansion.");
    Item* musicBox = new Item("music box", "A delicate music box. Its melody feels strangely familiar.");
    Item* key = new Item("key", "A big bronze key. You are not sure what it opens.");

    outsidePorch->addItem(lantern);
    entranceHall->addItem(backpack);
    library->addItem(map);
    office->addItem(musicBox);
    kitchen->addItem(key);

    //Player
    Player* player = new Player(
    "Ghost Hunter",
    "You are a ghost hunter hired by the new owners to help the sad ghost find peace.",
    outsidePorch);

    world.setPlayer(player);

   //Create Exits 
   Exit* porchToHall = new Exit("Front Door", "The old wooden door leads into the mansion.", Direction::NORTH, outsidePorch, entranceHall);
   Exit* hallToPorch = new Exit("Front Door", "The door leads back outside.", Direction::SOUTH, entranceHall, outsidePorch);

   Exit* hallToKitchen = new Exit("Kitchen Door", "A swinging wooden door leads into the kitchen.", Direction::EAST, entranceHall, kitchen);
   Exit* kitchenToHall = new Exit("Kitchen Door", "The kitchen door leads back to the entrance hall.", Direction::WEST, kitchen, entranceHall);

   Exit* hallToOffice = new Exit("Office Door", "A cracked wooden door leads into the office.", Direction::WEST, entranceHall, office);
   Exit* officeToHall = new Exit("Office Door", "The office door leads back to the entrance hall.", Direction::EAST, office, entranceHall);

   Exit* hallToSecondFloor = new Exit("Stairs", "The staircase leads to the second floor.", Direction::NORTH, entranceHall, secondFloor);
   Exit* secondFloorToHall = new Exit("Stairs", "The stairs lead back down to the entrance hall.", Direction::SOUTH, secondFloor, entranceHall);

   Exit* secondFloorToLibrary = new Exit("Library Door", "A tall door leads into the library.", Direction::WEST, secondFloor, library);
   Exit* libraryToSecondFloor = new Exit("Library Door", "The library door leads back to the second floor hallway.", Direction::EAST, library, secondFloor);

   Exit* secondFloorToBedroom = new Exit("Master Bedroom Door", "A large locked door blocks your way.", Direction::EAST, secondFloor, masterBedroom);
   Exit* bedroomToSecondFloor = new Exit("Master Bedroom Door", "The door leads back to the second floor hallway.", Direction::WEST, masterBedroom, secondFloor);

   secondFloorToBedroom->setLocked(true);
    
   //Exits
   outsidePorch->addExit(porchToHall);
   entranceHall->addExit(hallToPorch);
   entranceHall->addExit(hallToKitchen);
   entranceHall->addExit(hallToOffice);
   entranceHall->addExit(hallToSecondFloor);

   kitchen->addExit(kitchenToHall);
   office->addExit(officeToHall);

   secondFloor->addExit(secondFloorToHall);
   secondFloor->addExit(secondFloorToLibrary);
   secondFloor->addExit(secondFloorToBedroom);

   library->addExit(libraryToSecondFloor);
   masterBedroom->addExit(bedroomToSecondFloor);
    
    //Rooms
    world.addEntity(outsidePorch);
    world.addEntity(entranceHall);
    world.addEntity(library);
    world.addEntity(kitchen);
    world.addEntity(office);
    world.addEntity(masterBedroom);
    world.addEntity(secondFloor);

    //Exits
    world.addEntity(porchToHall);
    world.addEntity(hallToPorch);
    world.addEntity(hallToKitchen);
    world.addEntity(kitchenToHall);
    world.addEntity(hallToOffice);
    world.addEntity(officeToHall);
    world.addEntity(hallToSecondFloor);
    world.addEntity(secondFloorToHall);
    world.addEntity(secondFloorToLibrary);
    world.addEntity(libraryToSecondFloor);
    world.addEntity(secondFloorToBedroom);
    world.addEntity(bedroomToSecondFloor);

    //Items
    world.addEntity(lantern);
    world.addEntity(backpack);
    world.addEntity(map);
    world.addEntity(musicBox);
    world.addEntity(key);
    world.addEntity(player);

}

void Game::start()
{
    this->showIntro();
    this->showCurrentRoom();

    std::string command;

    while (this->running)
    {
        std::cout << "\n> ";
        std::getline(std::cin, command);

        this->processCommand(command);

        if (this->checkWinCondition())
        {
            this->endGame();
        }
    }
}

void Game::showCurrentRoom()
{
    Player* player = world.getPlayer();
    Room* currentRoom = player->getCurrentRoom();

    std::cout << "\nYou are in: " << currentRoom->getName() << "\n";
    std::cout << currentRoom->getDescription() << "\n";

    std::vector<Item*> items = currentRoom->getItems();
   if (items.empty())
{
    std::cout << "There are no items here.\n";
}
else
{
    std::cout << "You see:\n";

    for (Item* item : items)
    {
        std::cout << "- " << item->getName()
                  << ": "
                  << item->getDescription()
                  << "\n";
    }
}

    std::vector<Exit*> exits = currentRoom->getExits();
   if (exits.empty())
{
    std::cout << "There are no exits.\n";
}
else
{
    std::cout << "Exits:\n";

    for (Exit* exit : exits)
{
    std::cout << "- "
              << directionToString(exit->getDirection())
              << " ("
              << exit->getName()
              << ")\n";
}
}
}

//Directions
std::string Game::directionToString(Direction direction)
{
    switch (direction)
    {
        case Direction::NORTH:
            return "north";
        case Direction::SOUTH:
            return "south";
        case Direction::EAST:
            return "east";
        case Direction::WEST:
            return "west";
        case Direction::UP:
            return "up";
        case Direction::DOWN:
            return "down";
        default:
            return "unknown";
    }
}

void Game::processCommand