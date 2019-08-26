#include "lottery.h"
#include "ui_lottery.h"
#include <QDebug>
#include <QRandomGenerator>

Lottery::Lottery(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Lottery)
{
    ui->setupUi(this);
    ItemModel = new QStandardItemModel(this);
    ui->resultListView->setModel(ItemModel);
    start = false;
}

Lottery::~Lottery()
{
    qDebug() << "~Lottery";
    delete ui;
}

void Lottery::on_lotteryBtn_clicked()
{
    if(!start)
    {
        start = true;
        //ui->lotteryBtn->setText("stop");
        time_id = startTimer(150);
        ui->lotteryBtn->setIcon(QIcon(":/pic/stop.jpg"));
    }
    else
    {
        start = false;
        //ui->lotteryBtn->setText("start");
         ui->lotteryBtn->setIcon(QIcon(":/pic/start.jpg"));
        killTimer(time_id);
        QStandardItem *item = new QStandardItem(ui->randomLabel->text());
        ItemModel->appendRow(item);
    }

}

void Lottery::setNumList(QStringList &list)
{
    this->mlist = list;
}

void Lottery::timerEvent(QTimerEvent *event)
{
    int index = QRandomGenerator::global()->bounded(mlist.length());
    if(mlist.length() > 0)
        ui->randomLabel->setText(mlist.at(index));
}
