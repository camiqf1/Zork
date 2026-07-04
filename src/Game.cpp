#include "Game.h"
#include <iostream>


Game::Game()
 {
    this ->createWorld();
}

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

void Game::createWorld()
{
    Room* outside = new Room("Outside Mansion", "You stand before a tall abandoned mansion. The front door waits in silence.");
    Room* entranceHall = new Room("Entrance Hall", "A dark hall filled with dust, old portraits, and eerie air.");
    Room* library = new Room("Library", "Old books cover the walls. A strange sadness fills the room.");
    Room* kitchen = new Room("Kitchen", "Rusty pans hang from the ceiling. Something smells rotten.");
    Room* attic = new Room("Attic", "The attic is full of forgotten objects and moonlight.");
    Room* masterBedroom = new Room("Master Bedroom", "A locked door stands before you. The air feels heavy and cold.");

    Item* lantern = new Item("lantern", "An old lantern. It helps you see inside the mansion.");
    Item* backpack = new Item("backpack", "A worn backpack that can store items.");
    Item* map = new Item("map", "A faded map of the mansion.");
    Item* musicBox = new Item("music box", "A delicate music box. It's melody feels strangely familiar.");
    Item* key = new Item("key", "A big bronze key. You are not sure what it opens.");

    outside->addItem(lantern);
    entranceHall->addItem(backpack);
    library->addItem(map);
    attic->addItem(musicBox);
    kitchen->addItem(key);

    Player* player = new Player("Player", "A brave visitor trying to help the sad ghost.", outside);

    world.setPlayer(player);

    world.addEntity(outside);
    world.addEntity(entranceHall);
    world.addEntity(library);
    world.addEntity(kitchen);
    world.addEntity(attic);
    world.addEntity(masterBedroom);

    world.addEntity(lantern);
    world.addEntity(backpack);
    world.addEntity(map);
    world.addEntity(musicBox);
    world.addEntity(key);
    world.addEntity(player);
}
