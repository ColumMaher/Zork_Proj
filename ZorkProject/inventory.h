#ifndef INVENTORY_H
#define INVENTORY_H

#include <QDialog>
#include "player.h"

namespace Ui {
class Inventory;
}

class Inventory : public QDialog
{
    Q_OBJECT

public:
    explicit Inventory(QWidget *parent = nullptr);
    ~Inventory();
    void showInventory(Player* p);
    void removeItem(bool drop);

private slots:
    void on_useButton_clicked();

    void on_dropButton_clicked();

    void on_equipButton_clicked();

private:
    Ui::Inventory *ui;

};

#endif // INVENTORY_H
