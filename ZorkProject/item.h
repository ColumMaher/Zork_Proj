#ifndef ITEM_H
#define ITEM_H
#include <QString>
#include <QDebug>
class Item
{
private:
    QString name;
    bool weapon = false;
    bool potion = false;
    bool key = false;
    int damage;
    int heal;
    char room;
    char current;
    char direction;
public:
    Item(QString name);
    Item(const Item& item);
    Item();
    ~Item();
    QString getName(){
            return this->name;
        }
    int getDamage(){
        return this->damage;
    }
    int getHeal(){
        return this->heal;
    }
    void setDamage(int dmg){
        this->damage = dmg;
    }
    bool isWeapon(){
        return this->weapon;
    }
    bool isKey(){
        return this->key;
    }
    bool isPotion(){
        return this->potion;
    }
    char getRoom(){
        return this->room;
    }
    char getCurrent(){
        return this->current;
    }
    char getDirection(){
        return this->direction;
    }
};

#endif // ITEM_H
