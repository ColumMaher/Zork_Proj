#ifndef DEAD_H
#define DEAD_H

#include <QDialog>

namespace Ui {
class Dead;
}

class Dead : public QDialog
{
    Q_OBJECT

public:
    explicit Dead(QWidget *parent = nullptr);
    ~Dead();

private:
    Ui::Dead *ui;
};

#endif // DEAD_H
