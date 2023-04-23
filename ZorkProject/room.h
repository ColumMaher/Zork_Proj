#ifndef ROOM_H
#define ROOM_H
#include <string>
#include <QString>
#include "item.h"
#include "enemy.h"
#include <QDebug>
#include <vector>
class Room{
private:
    QString desc;
    char roomChar;
    std::vector<Item> items;
    std::vector<Enemy> enemies;
    char north;
    char south;
    char west;
    char east;
    friend void takeItem(Item& item); //Friendship!
    friend void dropItem(Item& item);
public:
    Room(char roomChar, QString description, std::vector<Item>& items, std::vector<Enemy>& enemies, char north, char east, char south, char west);
    Room();
    template<class T>//template function :)
    T setNorth (T c){
        this->north = c;
    }
    void setDesc(QString& d){
        desc = d;
    }
    QString getDesc(){
        return desc;
    }
    char getChar(){
            return this->roomChar;
        }
        void addItem(Item& item){
            items.push_back(item);
        }
        std::vector<Item>& getItems(){
            return items;
        }
        std::vector<Enemy>& getEnemies(){
            return enemies;
        }
        void removeItem(Item& item){
            for(int i = 0; i < 6; i++){
                if(items[i].getName() == item.getName()){
                    items.erase(items.begin() + i);
                    break;
                }
            };
        }
        void addEnemy(Enemy& enemy){
            enemies.push_back(enemy);
        }
        void removeEnemy(Enemy& enemy){
            for(int i = 0; i < 6; i++){
                if(enemies[i].getName() == enemy.getName()){
                    enemies.erase(enemies.begin() + i);
                    break;
                }
            };
        }
        char getNorth(){
            return this->north;
        }
        char getEast(){
            return this->east;
        }
        char getSouth(){
            return this->south;
        }
        char getWest(){
            return this->west;
        }
        void setEast(char c){
            this->east = c;
        }
        void setSouth(char c){
            this->south = c;
        }
        void setWest(char c){
            this->west = c;
        }
};

#endif // ROOM_H
