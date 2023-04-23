#include "player.h"
#include "room.h"
#include <string>
std::vector<Item> items1;
std::vector<Enemy> enemies1;
Room nully = Room(0, 0, items1, enemies1, 0, 0, 0, 0);
Room& room1 = nully;
Player::Player():Player(12, room1)
{
}
Player::~Player(){

}
int Player::attack(Creature* c, int damage)
{
    return c->getHealth() - damage;
}
