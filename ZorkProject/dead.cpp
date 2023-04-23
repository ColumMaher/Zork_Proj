#include "dead.h"
#include "ui_dead.h"

Dead::Dead(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dead)
{
    ui->setupUi(this);
}

Dead::~Dead()
{
    delete ui;
}
