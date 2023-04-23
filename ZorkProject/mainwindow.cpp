#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inventory.h"
#include "dead.h"
#include "rangarok.h"
#include "player.h"
#include "room.h"
#include "example.h"
#include <QDebug>
#include <iostream>
#include <QString>
#include <string>
#define output_health(s) ui->playerHealth->setText(s) //Advanced Pre-Processor Directive or Macro :)))))
#define None 0
using namespace std;


std::vector<Item> items;
std::vector<Enemy> enemies;
Room nullx = Room(0, 0, items, enemies, 0, 0, 0, 0);
Room& room = nullx;
Player Hero;
Player Hero3 = Player(3, nullx);  //despite Hero being called first, it will be initiated 2nd due to the Object Construction Sequence


vector<Room> rooms;

Item nullItem = Item("null");
Item trueNullItem = Item("null");
Item& selectedItem = nullItem;
Item Mjolnir = Item("Mjolnir");
Item theKey = Item("The Key");
Item BlackWhitePotion = Item("Black-White Potion");
Item RedBluePotion = Item("Red-Blue Potion");
Item PinkYellowPotion = Item("Pink-Yellow Potion");

Enemy null = Enemy("null", None, None);
Enemy trueNull = Enemy("null", None, None);
Enemy& selectedEnemy = null;
Enemy Vidarr = Enemy("Víðarr", 100, 20);
Enemy Eisurfala = Enemy("Eisurfála", 100, 35);
Enemy Chains = Enemy("Chains", 1 , 5);

struct makeEnemy
{
    QString n;
    int h:8;
    int d:8;
};

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Example example = Example(); //I call example here

    std::vector<Item> itemsA;
    std::vector<Enemy> enemiesA;
    Room A = Room('A', "You knew using the shortcut through the mountains was dangerous, but sliding into a crevasse and getting swallowed by Mt. Eivor itself was unexpected.\nYour armour is lost, your sword shattered, but a faint light jaunts from the North, through the blackness that surrounds.\nWhat do you do?", itemsA, enemiesA, 'B', 0, 0, 0);

    Item SmallPot = Item("Weak Potion");
    std::vector<Item> itemsB;
    itemsB.insert(itemsB.end(), {SmallPot});

    struct makeEnemy Keeper = {"Keeper", 15, 3}; //Bit structure being called  !
    Enemy KeeperMummy = Enemy(Keeper.n, Keeper.h, Keeper.d);

    std::vector<Enemy> enemiesB;
    enemiesB.insert(enemiesB.end(), {KeeperMummy});

    Room B = Room('B', "The light shines from a great lantern, strung over the shoulder of an ancient undead. It struggles under the weight, but its task is complete.\nCarved bas-reliefs in walls, a hundred feet long, stretch towards the West.\nThey depict a great battle, Ragnarok, and at the centre the Great Wolf Fenris swallows Odin whole.\nThe Western Door is locked, barred by chains as thick as trunks, but the way East is clear.", itemsB, enemiesB, 0, 'D', 'A', 0);

    std::vector<Item> itemsC;


    std::vector<Enemy> enemiesC;
    enemiesC.insert(enemiesC.end(), {Chains});
    Room C = Room('C', "The great Wolf of the river Ván, Fenris, lies chained before you. Ichor soaked fur sticks to his ailing body, scars deep as your waist is wide run along the titan. Some loose chains lash about throughout the room, tring to warn you from your task. Fenrir lasily opens one eye, considers you, then shuts it again. \nYour task is at an end. Act, free the world by dooming it.", itemsC, enemiesC, 0, 'B', 0, 0);




    Item Spear = Item("Spear");
    Item Potion = Item("Potion");
    std::vector<Item> itemsD;
    itemsD.insert(itemsD.end(), {Spear, Potion});

    Enemy* Hati = new Enemy("Hati", 25, 5);
    Enemy* Skoll = new Enemy("Sköll ", 12, 30);
    Enemy arr[2] = {*Hati, *Skoll}; //Array and pointers (:

    std::vector<Enemy> enemiesD;
    enemiesD.insert(enemiesD.end(), {arr[0], arr[1]});

    Room D = Room('D', "Two wolves, one black and one white, Hati and Sköll, pace around the room. As you watch they keep perfect distance from each other, circling an intricately carved Spear in the centre of the room.\nSuddenly they stop, sensing you, and charge!\nThere is a door North, a way West, and a long drawn cave to the East.", itemsD, enemiesD, 'F', 'E', 0, 'B');
    delete Hati; //Memory managed >:)
    delete Skoll;



    Item GreaterPot = Item("Strong Potion");
    std::vector<Item> itemsE;
    itemsE.insert(itemsE.end(), {GreaterPot});


    Enemy Angrboda = Enemy("Angrboða", 75, 35);

    std::vector<Enemy> enemiesE;
    enemiesE.insert(enemiesE.end(), {Angrboda});

    Room E = Room('E', "The cave narrows and forms into a small chamber, and at its end a throne. A beautiful woman, Angrboða, Mother of Fenrir, Jörmungandr, and Wife to Loki, sits crying in the chair. Black tears run down her face, but as she sees you, they form into shards of ice.\n She snaps them from her eyes, and screams.\nThe cave widens to the West.", itemsE, enemiesE, 0, 0, 0, 'D');

    std::vector<Item> itemsF;
    itemsF.insert(itemsF.end(), {GreaterPot});

    Enemy FireImp = Enemy("Fire Imp", 21, 10);
    Enemy IceImp = Enemy("Ice Imp", 1, 20);
    Enemy AirImp = Enemy("Air Imp", 15, 15);
    Enemy EarthImp = Enemy("Earth Imp", 31, 5);

    std::vector<Enemy> enemiesF;
    enemiesF.insert(enemiesF.end(), {EarthImp, IceImp, AirImp, FireImp});

    Room F = Room('F', "Four Imps are crowded around a Tafl board, yipping and hollering in some harsh language foreign to your ears. 'Neftz! Asht! Ashtz!' They say, spreading their wings and powering towards you.\nThere is a path North, a bridge across a ravine East, and a door South.", itemsF, enemiesF, 'H', 'G', 'D', 0);


    std::vector<Item> itemsG;
    itemsG.insert(itemsG.end(), {Potion, Potion});

    std::vector<Enemy> enemiesG;
    enemiesG.insert(enemiesG.end(), {Vidarr});

    Room G = Room('G', "The bridge East leads you to a well lit chamber, where an ethereal and ghostly figure kneels. He wears a helmet with antlers five feet long, and wields a Hammer like none you have ever seen.\n'Hail, Warrior' he says, standing up.\n'I am Víðarr, Son of Odin, and have need of your help. If you can defeat me, in this weakened form, I will give you Mjölnir. I took it from my brothers body, unbroken, slain as he was by Jörmungandr.'\n'Fight me, and use this weapon to release Ragnarok, so that I may destroy Fenrir and begin the world anew.'", itemsG, enemiesG, 0, 0, 0, 'F');

    std::vector<Item> itemsH;
    itemsH.insert(itemsH.end(), {RedBluePotion, BlackWhitePotion, PinkYellowPotion});

    std::vector<Enemy> enemiesH;
    enemiesH.insert(enemiesH.end(), {});

    Room H = Room('H', "The way leads to a small room, where on a plinth stands three potions.\nFour are hanging,\nFour are walking,\nTwo point the way out,\nTwo ward the dogs off,\nOne ever dirty\nDangles behind it.\nThis riddle ponder\nO great Warrior!\nTo the West you hear... Waves? And hammering? There is also a path South.", itemsH, enemiesH, 0, 0, 'F', 'I');


    std::vector<Item> itemsI;
    itemsI.insert(itemsI.end(), {});

    Enemy ArcherJotunn = Enemy("Archer Jotunn", 50, 20);
    Enemy JotunnChild = Enemy("Jotunn Child", 20, 10);
    Enemy SorcererJotunn = Enemy("Sorcerer Jotunn", 20, 35);
    std::vector<Enemy> enemiesI;
    enemiesI.insert(enemiesI.end(), {Eisurfala, ArcherJotunn, JotunnChild, SorcererJotunn});

    Room I = Room('I', "Your eyes have never seen something so vast. You've made it to the coast, here where Jörmungandr lies dead, and Thor also, nine paces away.\nFour Jotunn, one fiery, one with a bow, one young, and one old, are working at taking a great scale from the Serpent. You spot a large key on the Fiery One's belt, and draw your weapon.\n The way back is East.", itemsI, enemiesI, 0, 'H', 0, 0);



    Item ShatteredSword = Item("Shattered Sword");
    rooms.insert(rooms.end(), {A, B, C, D, E, F, G, H, I});

    Hero.addItem(ShatteredSword);
    Hero.setEquipped(ShatteredSword);
    Hero.setHealth(50);
    Hero.setCurrentRoom(rooms.at(0));
    directionTick();
}
MainWindow::~MainWindow()
{
    delete ui;
}

QString operator+(QString s, int i){//Operator Overloading
    s = s + QString::number(i);
    return s;
}

void MainWindow::on_north_button_clicked()
{
   if(goDirection('N')){
       ui->output->appendPlainText("You go North");
       directionTick();
   } else {
       ui->output->appendPlainText("You cannot go North");
   }
}

void MainWindow::on_east_button_clicked()
{
    if(goDirection('E')){
        ui->output->appendPlainText("You go East");
        directionTick();
    } else {
        ui->output->appendPlainText("You cannot go East");
    }
}

void MainWindow::on_south_button_clicked()
{
    if(goDirection('S')){
        ui->output->appendPlainText("You go South");
        directionTick();
    } else {
        ui->output->appendPlainText("You cannot go South");
    }
}

void MainWindow::on_west_button_clicked()
{
    if(goDirection('W')){
        ui->output->appendPlainText("You go West");
        directionTick();
    } else {
        ui->output->appendPlainText("You cannot go West");
    }
}

void MainWindow::on_attackButton_clicked()
{
    if (selectedEnemy.getName() != trueNull.getName()){
        ui->output->appendPlainText("Attacked " + selectedEnemy.getName());

        for(int i = 0; i < Hero.getCurrentRoom().getEnemies().size(); i++){
            if (selectedEnemy.getName() == Hero.getCurrentRoom().getEnemies().at(i).getName()){
                Hero.getCurrentRoom().getEnemies().at(i).setHealth(Hero.attack(& selectedEnemy, Hero.getEquipped().getDamage()));
                selectedEnemy = Hero.getCurrentRoom().getEnemies().at(i);
            }
        }



        if(selectedEnemy.getHealth() <= 0){
            if(selectedEnemy.getName() == Vidarr.getName()){
                Hero.getCurrentRoom().addItem(Mjolnir);
                itemsTick();
            }
            if(selectedEnemy.getName() == Eisurfala.getName()){
                Hero.getCurrentRoom().addItem(theKey);
                itemsTick();
            }
            if(selectedEnemy.getName() == Chains.getName()){
                Rangarok end;
                end.setModal(true);
                end.exec();
                QApplication::quit();
            }
            ui->output->appendPlainText(selectedEnemy.getName() + " is Dead!");

            Hero.getCurrentRoom().removeEnemy(selectedEnemy);
            selectedEnemy = trueNull;
        } else {
            QString s = "Their Health Remaining ";
            int i = selectedEnemy.getHealth();
            ui->output->appendPlainText(s+i);//Operator Overloading in action
        }
        enemiesTick();
    }
}

void MainWindow::on_enemyButton_1_clicked()
{
    try{
        selectedEnemy = Hero.getCurrentRoom().getEnemies().at(0);
    }
    catch (const std::out_of_range& noEnemy){
        selectedEnemy = trueNull;
    }
}

void MainWindow::on_enemyButton_2_clicked()
{
    try{
        selectedEnemy = Hero.getCurrentRoom().getEnemies().at(1);
    }
    catch (const std::out_of_range& noEnemy){
        selectedEnemy = trueNull;
    }
}

void MainWindow::on_enemyButton_3_clicked()
{
    try{
        selectedEnemy = Hero.getCurrentRoom().getEnemies().at(2);
    }
    catch (const std::out_of_range& noEnemy){
        selectedEnemy = trueNull;
    }
}

void MainWindow::on_enemyButton_4_clicked()
{
    try{
        selectedEnemy = Hero.getCurrentRoom().getEnemies().at(3);
    }
    catch (const std::out_of_range& noEnemy){
        selectedEnemy = trueNull;
    }
}

void MainWindow::on_enemyButton_5_clicked()
{
    try{
        selectedEnemy = Hero.getCurrentRoom().getEnemies().at(4);
    }
    catch (const std::out_of_range& noEnemy){
        selectedEnemy = trueNull;
    }

}

void MainWindow::on_enemyButton_6_clicked()
{
    try{
        selectedEnemy = Hero.getCurrentRoom().getEnemies().at(5);
    }
    catch (const std::out_of_range& noEnemy){
        selectedEnemy = trueNull;
    }
}

void MainWindow::on_inventory_clicked()
{
    Inventory inventory;
    inventory.showInventory(&Hero);
    inventory.setModal(true);
    inventory.exec();
    itemsTick();
    output_health(QString::number(Hero.getHealth()) + "/100");
    //ui->playerHealth->setText(QString::number(Hero.getHealth()) + "/100");
}

void MainWindow::on_takeButton_clicked()
{
    if (selectedItem.getName() != trueNullItem.getName()){
        if(selectedItem.getName() == BlackWhitePotion.getName()){
            Hero.getCurrentRoom().removeItem(RedBluePotion);
            Hero.getCurrentRoom().removeItem(PinkYellowPotion);
        } else if(selectedItem.getName() == RedBluePotion.getName()){
            Hero.getCurrentRoom().removeItem(BlackWhitePotion);
            Hero.getCurrentRoom().removeItem(PinkYellowPotion);
        } else if(selectedItem.getName() == PinkYellowPotion.getName()){
            Hero.getCurrentRoom().removeItem(BlackWhitePotion);
            Hero.getCurrentRoom().removeItem(RedBluePotion);
        }
        std::vector<Item> items = Hero.getCurrentRoom().getItems();
        ui->output->appendPlainText("Taken " + selectedItem.getName());

        //Add item to inventory
        Hero.takeItem(selectedItem);
        selectedItem = trueNullItem;
        itemsTick();
    }
}

void MainWindow::on_itemButton_1_clicked()
{
    std::vector<Item> items = Hero.getCurrentRoom().getItems();
    try{
        selectedItem = items.at(0);
    }
    catch (const std::out_of_range& noItem){
    }
}

void MainWindow::on_itemButton_2_clicked()
{
    std::vector<Item> items = Hero.getCurrentRoom().getItems();
    try{
        selectedItem = items.at(1);
    }
    catch (const std::out_of_range& noItem){
    }
}

void MainWindow::on_itemButton_3_clicked()
{
    std::vector<Item> items = Hero.getCurrentRoom().getItems();
    try{
        selectedItem = items.at(2);
    }
    catch (const std::out_of_range& noItem){
    }
}

void MainWindow::on_itemButton_4_clicked()
{
    std::vector<Item> items = Hero.getCurrentRoom().getItems();
    try{
        selectedItem = items.at(3);
    }
    catch (const std::out_of_range& noItem){
    }
}

void MainWindow::on_itemButton_5_clicked()
{
    std::vector<Item> items = Hero.getCurrentRoom().getItems();
    try{
        selectedItem = items.at(4);
    }
    catch (const std::out_of_range& noItem){
    }
}

void MainWindow::on_itemButton_6_clicked()
{
    std::vector<Item> items = Hero.getCurrentRoom().getItems();
    try{
        selectedItem = items.at(5);
    }
    catch (const std::out_of_range& noItem){
    }
}


void MainWindow::setOutput(QString text){
    ui->output->appendPlainText(text);
}
void MainWindow::directionTick(){
    ui->output->appendPlainText("");
    ui->output->appendPlainText("");
    ui->output->appendPlainText(Hero.getCurrentRoom().getDesc());
    output_health(QString::number(Hero.getHealth()) + "/100");
    try{
        selectedEnemy = Hero.getCurrentRoom().getEnemies().at(0);
    }
    catch (const std::out_of_range& noEnemy){
    }

    enemiesTick();
    itemsTick();
}
void MainWindow::itemsTick(){
    std::vector<Item> items = Hero.getCurrentRoom().getItems();
    QString itemNames[6];

    for(int i = 0; i < items.size(); i++){
        itemNames[i] = items.at(i).getName();
    }
    ui->itemButton_1->setText(itemNames[0]);
    ui->itemButton_2->setText(itemNames[1]);
    ui->itemButton_3->setText(itemNames[2]);
    ui->itemButton_4->setText(itemNames[3]);
    ui->itemButton_5->setText(itemNames[4]);
    ui->itemButton_6->setText(itemNames[5]);

    if(Hero.getHealth() <= 0){
        ui->playerHealth->setText("0/100");
        Dead dead;
        dead.setModal(true);
        dead.exec();
        QApplication::quit();
    }
}
void MainWindow::enemiesTick(){
    std::vector<Enemy>& enemies = Hero.getCurrentRoom().getEnemies();
    QString enemyNames[6];
    for(int i = 0; i < enemies.size(); i++){
        enemyNames[i] = enemies.at(i).getName();
    }
    ui->enemyButton_1->setText(enemyNames[0]);
    ui->enemyButton_2->setText(enemyNames[1]);
    ui->enemyButton_3->setText(enemyNames[2]);
    ui->enemyButton_4->setText(enemyNames[3]);
    ui->enemyButton_5->setText(enemyNames[4]);
    ui->enemyButton_6->setText(enemyNames[5]);

    try{
        if(enemies.size() != 0){
            Enemy enemy = enemies.at(rand()%enemies.size());
            QString s = enemy.getName() + " attacks you for ";
            int i = enemy.getDamage();
            ui->output->appendPlainText(s + i + " damage!");
            Hero.setHealth(enemy.attack(& Hero, enemy.getDamage()));
            output_health(QString::number(Hero.getHealth()) + "/100");
            //ui->playerHealth->setText(QString::number(Hero.getHealth()) + "/100");
        }
    }
    catch (const std::out_of_range& noEnemy){
    }

    if(Hero.getHealth() <= 0){
        ui->playerHealth->setText("0/100");
        Dead dead;
        dead.setModal(true);
        dead.exec();
        QApplication::quit();
    }

}

bool MainWindow::goDirection(char direction){
    Room currentRoom = Hero.getCurrentRoom();
    for(int i = 0; i < rooms.size(); i++){
        if(rooms.at(i).getChar() == currentRoom.getChar()){
            rooms.at(i) = currentRoom;
        }
    }
    if(direction == 'N'){
        if(currentRoom.getNorth() != 0){
            std::vector<Room>::iterator it;
            int i = 0;
            for(it = rooms.begin() ; it != rooms.end(); it++, i++){
                if(rooms.at(i).getChar() == Hero.getCurrentRoom().getNorth()){
                    Hero.setCurrentRoom(rooms.at(i));
                    return true;
                }
            }
        }
    } else if(direction == 'E'){
        if(currentRoom.getEast() != 0){
            std::vector<Room>::iterator it;
            int i = 0;
            for(it = rooms.begin() ; it != rooms.end(); it++, i++){
                if(rooms.at(i).getChar() == Hero.getCurrentRoom().getEast()){
                    Hero.setCurrentRoom(rooms.at(i));
                    return true;
                }
            }
        }
    } else if(direction == 'S'){
        if(currentRoom.getSouth() != 0){
            std::vector<Room>::iterator it;
            int i = 0;
            for(it = rooms.begin() ; it != rooms.end(); it++, i++){
                if(rooms.at(i).getChar() == Hero.getCurrentRoom().getSouth()){
                    Hero.setCurrentRoom(rooms.at(i));
                    return true;
                }
            }
        }
    } else if(direction == 'W'){
        if(currentRoom.getWest() != 0){
            std::vector<Room>::iterator it;
            int i = 0;
            for(it = rooms.begin() ; it != rooms.end(); it++, i++){
                if(rooms.at(i).getChar() == Hero.getCurrentRoom().getWest()){
                    Hero.setCurrentRoom(rooms.at(i));
                    return true;
                }
            }
        }
    }
    return false;
}
