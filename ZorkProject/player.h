#ifndef PLAYER_H
#define PLAYER_H
#include "creature.h"
#include "room.h"
#include "item.h"
#include <string>

class Player: public Creature{
private:
    int health;
    Room currentRoom = this->currentRoom;
    Item equipped;
    std::vector<Item> playerInventory = this->playerInventory;
public:
    Player(int h, Room& cR):health(h), currentRoom(cR){} //Initializer list!!1 :)
    Player();
    virtual ~Player();
    void setHealth(int h){
        health = h;
    }
    int getHealth(){
        return health;
    }
    void setEquipped(Item& item){
        this->equipped = item;
    }
    Item& getEquipped(){
        return equipped;
    }
    std::vector<Item>& getInventory(){
        return this->playerInventory;
    }
    void setInventory(std::vector<Item>& inv){
        this->playerInventory = inv;
    }
    Room& getCurrentRoom(){
            return this->currentRoom;
    }
    void setCurrentRoom(Room& room){
            this->currentRoom = room;
    }
    void addItem(Item& i){
        playerInventory.push_back(i);
    }
    void takeItem(Item& item){
        std::vector<Item> inventory = getInventory();
        std::vector<Item> items = getCurrentRoom().getItems();
        for(int i = 0; i < items.size(); i++){
            if(items.at(i).getName() == item.getName()){
                getCurrentRoom().removeItem(items.at(i));
                break;
            }
        }
        playerInventory.push_back(item);
    }
    void dropItem(Item& item){
        Item ite (item); //Deep Copy Constructor ! :)
        std::vector<Item> inventory = getInventory();
        std::vector<Item> items = getCurrentRoom().getItems();
        for(int i = 0; i < inventory.size(); i++){
            if(inventory.at(i).getName() == ite.getName()){
                this->playerInventory.erase(this->playerInventory.begin() + i);
                break;
            }
        }
        currentRoom.addItem(ite);
    }
    void destroyItem(Item& item){
        Item ite (item); //Deep Copy Constructor ! :)
        std::vector<Item> inventory = getInventory();
        std::vector<Item> items = getCurrentRoom().getItems();
        for(int i = 0; i < inventory.size(); i++){
            if(inventory.at(i).getName() == ite.getName()){
                this->playerInventory.erase(this->playerInventory.begin() + i);
                break;
            }
        }
    }
    virtual int attack(Creature* c, int damage);
};

#endif // PLAYER_H
