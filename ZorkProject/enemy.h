#ifndef ENEMY_H
#define ENEMY_H
#include "creature.h"
#include <QString>

class Enemy: public Creature{
protected:
    int health;
private:
    int damage;
    QString name;
public:
    Enemy(QString name, int health, int damage);
    Enemy();

    virtual ~Enemy();
    void setName(QString name){
        this->name = name;
    }
    void setDamage(int damage){
        this->damage = damage;
    }
    int getDamage(){
       return this->damage;
    }
    int getHealth(){
        return this->health;
    }
    QString getName(){
        return this->name;
    }
    void setHealth(int health){
        this->health = health;
    }
    virtual int attack(Creature* c, int damage);
};
#endif // ENEMY_H
