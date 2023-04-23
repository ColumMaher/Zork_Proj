#include "rangarok.h"
#include "ui_rangarok.h"

Rangarok::Rangarok(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rangarok)
{
    ui->setupUi(this);
}

Rangarok::~Rangarok()
{
    delete ui;
}
