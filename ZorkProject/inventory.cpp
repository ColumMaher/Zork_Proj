#include "inventory.h"
#include "ui_inventory.h"
#include <QMessageBox>
Inventory::Inventory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Inventory)
{
    ui->setupUi(this);


}
Inventory::~Inventory()
{
    delete ui;
}
Player* Hero2;

void Inventory::showInventory(Player* p){
    for(int i = 0; i < p->getInventory().size(); i++){
        ui->listWidget->addItem(p->getInventory().at(i).getName());
    }

    Hero2 = p;
    ui->equippedWeapon->setText(Hero2->getEquipped().getName());
}
void Inventory::on_useButton_clicked()
{
   if(ui->listWidget->currentItem() == NULL){
      return;   //Stop Crash when no items available :)
   }
   for (int i = 0; i < Hero2->getInventory().size(); i++){
       Item& item = Hero2->getInventory().at(i);
       if((Hero2->getInventory().size()>0) && (item.getName() == ui->listWidget->currentItem()->text()) && (item.isPotion())){
           Hero2->setHealth(Hero2->getHealth() + item.getHeal());
           if(Hero2->getHealth() > 100)
               Hero2->setHealth(100);
           QMessageBox::information(this,ui->listWidget->currentItem()->text(), "The potion heals you for " + QString::number(item.getHeal()));
           removeItem(false);
       } else if((Hero2->getInventory().size()>0) && (item.getName() == ui->listWidget->currentItem()->text()) && (item.isKey())){
           if(Hero2->getCurrentRoom().getChar() == item.getCurrent()){
               switch(item.getDirection()){
                case 'N':
                 Hero2->getCurrentRoom().setNorth(item.getRoom());
                 QMessageBox::information(this,ui->listWidget->currentItem()->text(), "The North Door Opens!");
                 removeItem(false);
                 break;
                case 'E':
                 Hero2->getCurrentRoom().setEast(item.getRoom());
                 QMessageBox::information(this,ui->listWidget->currentItem()->text(), "The East Door Opens!");
                 removeItem(false);
                 break;
                case 'S':
                  Hero2->getCurrentRoom().setSouth(item.getRoom());
                  QMessageBox::information(this,ui->listWidget->currentItem()->text(), "The South Door Opens!");
                  removeItem(false);
                  break;
                case 'W':
                  Hero2->getCurrentRoom().setWest(item.getRoom());
                  removeItem(false);
                  QMessageBox::information(this,ui->listWidget->currentItem()->text(), "The West Door Opens!");
                  break;
               }
           }
       }
   }
}

void Inventory::on_dropButton_clicked()
{
    if(ui->listWidget->currentItem() == NULL){
       return;   //Stop Crash when no items available :)
    }
    removeItem(true);

}

void Inventory::on_equipButton_clicked()
{
    if(ui->listWidget->currentItem() == NULL){
       return;   //Stop Crash when no items available :)
    }
    for(int j = 0; j < Hero2->getInventory().size(); j++){
        if((Hero2->getInventory().size()>0) && (Hero2->getInventory().at(j).getName() == ui->listWidget->currentItem()->text()) && (Hero2->getInventory().at(j).isWeapon())){
                        //<< ui->listWidget->currentItem()->text();
            for(int i = 0; i < Hero2->getInventory().size(); i++){
                if(Hero2->getInventory().at(i).getName() == ui->listWidget->currentItem()->text()){
                    Hero2->setEquipped(Hero2->getInventory().at(i));
                }
            }

            ui->equippedWeapon->setText(ui->listWidget->currentItem()->text());
        }
    }
}

void Inventory::removeItem(bool drop){
    if((Hero2->getInventory().size()>0) && (Hero2->getCurrentRoom().getItems().size() < 6)){
        for(int i = 0; i < Hero2->getInventory().size(); i++){
            if(Hero2->getInventory().at(i).getName() == ui->listWidget->currentItem()->text()){
                if(drop){
                    Hero2->dropItem(Hero2->getInventory().at(i));
                    delete ui->listWidget->currentItem();
                    return;
                } else {
                    Hero2->destroyItem(Hero2->getInventory().at(i));
                    delete ui->listWidget->currentItem();
                    return;
                }
            }
        }
    }
}


