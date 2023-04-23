#ifndef RANGAROK_H
#define RANGAROK_H

#include <QDialog>

namespace Ui {
class Rangarok;
}

class Rangarok : public QDialog
{
    Q_OBJECT

public:
    explicit Rangarok(QWidget *parent = nullptr);
    ~Rangarok();

private:
    Ui::Rangarok *ui;
};

#endif // RANGAROK_H
