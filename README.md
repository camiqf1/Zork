# Help the Sad Ghost

## Author
Camila Queiroz Figueiredo

## Description
Help the Sad Ghost is a text adventure game written in C++. The player takes the role of a ghost hunter hired by the new owners of an abandoned mansion. Your mission is to explore the mansion, collect useful items, solve a small puzzle, and help a trapped ghost finally find peace.

## Objective
Explore the mansion and collect the items needed to complete your mission:

- Lantern
- Backpack
- Map
- Key
- Music Box

Use the key to unlock the Master Bedroom and use the music box inside the room to help the ghost find freedom.

## Features

- Text-based adventure
- Room navigation
- Inventory system
- Items can be stored inside another item (backpack)
- Locked doors
- Item interaction using the `use` command
- Win condition based on solving the final puzzle

## Commands

- `look` – Display the current room.
- `go <direction>` – Move north, south, east, or west.
- `take <item>` – Pick up an item.
- `drop <item>` – Drop an item.
- `put <item> <container>` – Store an item inside another item.
- `use <item>` – Use an item.
- `inventory` – Show your inventory.
- `help` – Display the available commands.
- `quit` – Exit the game.

## Mansion Layout

```                  
Master Bedroom -- Second Floor -- Library
                    |
Office -- Entrance Hall -- Kitchen
              |
        Outside Porch
```

## How to Compile

Using g++:

```bash
g++ -std=c++17 -Iinclude src/*.cpp -o Zork.exe
```

## How to Run

Windows:

```bash
.\Zork.exe
```

## Gameplay

1. Enter the mansion.
2. Collect useful items.
3. Explore every room.
4. Find the key.
5. Unlock the Master Bedroom.
6. Use the music box inside the Master Bedroom.
7. Help the ghost find peace.

Enjoy!