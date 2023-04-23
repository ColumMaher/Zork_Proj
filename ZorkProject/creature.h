#ifndef CREATURE_H
#define CREATURE_H
#include <QString>

class Creature
{
public:
    virtual int attack(Creature* c, int damage) = 0;
    virtual int getHealth() =0;
    virtual void setHealth(int newHealth) = 0;
};
#endif // CREATURE_H
