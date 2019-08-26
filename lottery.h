#ifndef LOTTERY_H
#define LOTTERY_H

#include <QWidget>

namespace Ui {
class Lottery;
}

class Lottery : public QWidget
{
    Q_OBJECT

public:
    explicit Lottery(QWidget *parent = nullptr);
    ~Lottery();

private:
    Ui::Lottery *ui;
};

#endif // LOTTERY_H
