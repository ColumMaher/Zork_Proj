#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "player.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setOutput(QString text);
    void directionTick();
    void start();
    bool goDirection(char direction);
    void enemiesTick();
    void itemsTick();
private slots:

    void on_north_button_clicked();

    void on_west_button_clicked();

    void on_east_button_clicked();

    void on_south_button_clicked();

    void on_enemyButton_1_clicked();

    void on_attackButton_clicked();

    void on_enemyButton_2_clicked();

    void on_enemyButton_3_clicked();

    void on_enemyButton_4_clicked();

    void on_enemyButton_5_clicked();

    void on_enemyButton_6_clicked();

    void on_inventory_clicked();

    void on_itemButton_1_clicked();

    void on_itemButton_2_clicked();

    void on_itemButton_3_clicked();

    void on_itemButton_4_clicked();

    void on_itemButton_5_clicked();

    void on_itemButton_6_clicked();

    void on_takeButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
