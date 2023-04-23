#include "enemy.h"

Enemy::Enemy(QString name, int health, int damage)
{
    this->name = name;
    this->health = health;
    this->damage = damage;
}
Enemy::Enemy(){

}
Enemy::~Enemy(){

}
int Enemy::attack(Creature* c, int damage)
{
    return c->getHealth() - damage;
}
