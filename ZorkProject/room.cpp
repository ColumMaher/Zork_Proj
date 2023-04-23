#include "room.h"
#include <string>
#include <QString>
#include "item.h"
Room::Room(char roomChar, QString description, std::vector<Item>& items, std::vector<Enemy>& enemies, char north, char east, char south, char west)
{
    this->roomChar = roomChar;
    this->desc = description;
    this->north = north;
    this->south = south;
    this->west = west;
    this->east = east;
    this->items = items;
    this->enemies = enemies;
}
Room::Room(){}
