#ifndef LOTTERY_H
#define LOTTERY_H

#include <QWidget>
#include <QStandardItemModel>

namespace Ui {
class Lottery;
}

class Lottery : public QWidget
{
    Q_OBJECT

public:
    explicit Lottery(QWidget *parent = nullptr);
    ~Lottery();
    void setNumList(QStringList &list);
    virtual void timerEvent(QTimerEvent *event);
private slots:
    void on_lotteryBtn_clicked();

private:
    Ui::Lottery *ui;
    QStringList mlist;
    bool start = false;
    int time_id;
    QStandardItemModel *ItemModel;
};

#endif // LOTTERY_H
