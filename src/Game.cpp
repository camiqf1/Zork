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

    std::cout << "Available commands:\n";
    std::cout << "- look\n";
    std::cout << "- go <direction>\n";
    std::cout << "- take <item>\n";
    std::cout << "- use <item>\n";
    std::cout << "- drop <item>\n";
    std::cout << "- put <item> <container>\n";
    std::cout << "- inventory\n";
    std::cout << "- help\n";
    std::cout << "- quit\n\n";
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
    Item* musicBox = new Item("musicbox", "A delicate music box. Its melody feels strangely familiar.");
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

void Game::processCommand(std::string command)
{
    if (command == "look")
    {
        handleLook();
    }
    else if (command == "inventory")
    {
        handleInventory();
    }
    else if (command == "quit")
    {
        running = false;
        std::cout << "You leave the mansion behind.\n";
    }
     else if (command.substr(0, 3) == "go ")
    {
        handleGo(command.substr(3));
    }
    else if (command.substr(0, 5) == "take ")
    {
        handleTake(command.substr(5));
    }
    else if (command.substr(0, 4) == "use ")
    {
        handleUse(command.substr(4));
    }
    else if (command.substr(0, 5) == "drop ")
    {
        handleDrop(command.substr(5));
    }
    else if (command.substr(0, 4) == "put ")
    {
    std::string input = command.substr(4);

    size_t space = input.find(' ');

    if (space == std::string::npos)
    {
        std::cout << "Usage: put <item> <container>\n";
        return;
    }

    std::string itemName = input.substr(0, space);
    std::string containerName = input.substr(space + 1);

    handlePut(itemName, containerName);
    }
    else if (command == "help")
    {
        std::cout << "Commands:\n";
        std::cout << "- look\n";
        std::cout << "- go north/south/east/west/up/down\n";
        std::cout << "- take item\n";
        std::cout << "- drop item\n";
        std::cout << "- use item\n"; 
        std::cout << "- put <item> <container>\n";
        std::cout << "- inventory\n";
        std::cout << "- quit\n";
    }
    else
    {
        std::cout << "I don't understand that command.\n";
    }
}

void Game::handleLook()
{
    showCurrentRoom();
}

void Game::handleInventory()
{
    Player* player = world.getPlayer();
    std::vector<Item*> inventory = player->getInventory();

    if (inventory.empty())
    {
        std::cout << "Your inventory is empty.\n";
    }
    else
    {
        std::cout << "Inventory:\n";
        for (Item* item : inventory)
{
    std::cout << "- "
              << item->getName()
              << ": "
              << item->getDescription()
              << "\n";

    std::vector<Item*> insideItems = item->getItems();

    for (Item* insideItem : insideItems)
    {
        std::cout << "   - "
                  << insideItem->getName()
                  << ": "
                  << insideItem->getDescription()
                  << "\n";
    }
}
}
}

void Game::handleTake(std::string itemName)
{
    Player* player = world.getPlayer();
    Room* currentRoom = player->getCurrentRoom();

    Item* item = currentRoom->removeItem(itemName);

    if (item == nullptr)
    {
        std::cout << "There is no " << itemName << " here.\n";
        return;
    }
        player->addItem(item);
        std::cout << "You picked up the " << item->getName() << ".\n";
}

void Game::handleDrop(std::string itemName)
{
    Player* player = world.getPlayer();
    Room* currentRoom = player->getCurrentRoom();

    Item* item = player->removeItem(itemName);

    if (item == nullptr)
    {
        std::cout << "You do not have a " << itemName << ".\n";
        return;
    }

    currentRoom->addItem(item);
    std::cout << "You dropped the " << item->getName() << ".\n";
}

void Game::handleGo(std::string direction)
{
    Player* player = world.getPlayer();
    Room* currentRoom = player->getCurrentRoom();

    std::vector<Exit*> exits = currentRoom->getExits();

    for (Exit* exit : exits)
    {
        if (directionToString(exit->getDirection()) == direction)
        {
            if (exit->isLocked())
            {
                std::cout << "The " << exit->getName() << " is locked.\n";
                std::cout << "You need a key to open it.\n";
                return;
            }

            player->setCurrentRoom(exit->getDestinationRoom());
            showCurrentRoom();
            return;
        }
    }

    std::cout << "You can't go " << direction << " from here.\n";
}

void Game::handlePut(std::string itemName, std::string containerName)
{
    Player* player = world.getPlayer();

    Item* item = player->removeItem(itemName);

    if (item == nullptr)
    {
        std::cout << "You do not have a " << itemName << ".\n";
        return;
    }

    Item* container = nullptr;
    std::vector<Item*> inventory = player->getInventory();

    for (Item* inventoryItem : inventory)
    {
        if (inventoryItem->getName() == containerName)
        {
            container = inventoryItem;
            break;
        }
    }

    if (container == nullptr)
    {
        player->addItem(item);
        std::cout << "You do not have a " << containerName << ".\n";
        return;
    }

    container->addItem(item);

    std::cout << "You put the " << item->getName()
              << " into the " << container->getName()
              << ".\n";
}

void Game::handleUse(std::string itemName)
{
    Player* player = world.getPlayer();
    Item* item = nullptr;

    std::vector<Item*> inventory = player->getInventory();

    for (Item* inventoryItem : inventory)
    {
        if (inventoryItem->getName() == itemName)
        {
            item = inventoryItem;
            break;
        }

        std::vector<Item*> insideItems = inventoryItem->getItems();

        for (Item* insideItem : insideItems)
        {
            if (insideItem->getName() == itemName)
            {
                item = insideItem;
                break;
            }
        }

        if (item != nullptr)
        {
            break;
        }
    }

    if (item == nullptr)
    {
        std::cout << "You do not have a " << itemName << ".\n";
        return;
    }

    if (itemName == "lantern")
    {
        std::cout << "You light the lantern. The darkness no longer frightens you.\n";
    }
    else if (itemName == "map")
    {
        std::cout << "\nMansion Map\n";
        std::cout << "                 Library\n";
        std::cout << "                    |\n";
        std::cout << "Master Bedroom -- Second Floor\n";
        std::cout << "                    |\n";
        std::cout << "Office -- Entrance Hall -- Kitchen\n";
        std::cout << "              |\n";
        std::cout << "         Outside Porch\n";
    }
    else if (itemName == "key")
    {
        Room* currentRoom = player->getCurrentRoom();

        if (currentRoom->getName() != "Second Floor")
        {
            std::cout << "You hold the key, but there is no locked door here.\n";
            return;
        }

        std::vector<Exit*> exits = currentRoom->getExits();

        for (Exit* exit : exits)
        {
            if (exit->getName() == "Master Bedroom Door")
            {
                exit->setLocked(false);
                std::cout << "You unlock the Master Bedroom Door.\n";
                return;
            }
        }

        std::cout << "There is no locked door here.\n";
    }
    else if (itemName == "musicbox")
    {
        Room* currentRoom = player->getCurrentRoom();

        if (currentRoom->getName() != "Master Bedroom")
        {
            std::cout << "You wind the music box, but nothing happens.\n";
            return;
        }

        std::cout << "\nThe music box begins to play.\n";
        std::cout << "A gentle melody fills the room.\n";
        std::cout << "The ghost slowly appears before you.\n";
        std::cout << "Its expression changes from sorrow to peace.\n";
        std::cout << "With one final smile, the ghost fades into the light.\n\n";

        endGame();
    }
    else
    {
        std::cout << "Nothing happens.\n";
    }
}

bool Game::checkWinCondition()
{

    return false;
}


void Game::endGame()
{
    std::cout << "You helped the sad ghost find freedom.\n";
    std::cout << "Congratulations! You have completed the game.\n";

    running = false;
}

   