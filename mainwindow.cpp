#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setText("start");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushBtn()
{
    this->close();
}

void MainWindow::timerEvent(QTimerEvent *event) {
    quint32 v = QRandomGenerator::global()->bounded(10);
    QString str;
    str.setNum(v);
    int timeid = event->timerId();
    if(timeid == timelist[0]) {
        ui->label1->setText(str);
    }
    if(timeid == timelist[1]) {
        ui->label2->setText(str);
    }
    if(timeid == timelist[2]) {
        ui->label3->setText(str);
    }
    if(timeid == timelist[3]) {
        ui->label4->setText(str);
    }
}

void MainWindow::on_pushButton_clicked()
{
    if(!start) {
        timelist[0] = startTimer(timeInterval);
        timelist[1] = startTimer(timeInterval);
        timelist[2] = startTimer(timeInterval);
        timelist[3] = startTimer(timeInterval);
        start = true;
        ui->pushButton->setText("stop");
    } else {
        killTimer(timelist[0]);
        killTimer(timelist[1]);
        killTimer(timelist[2]);
        killTimer(timelist[3]);
        start = false;
        ui->pushButton->setText("start");
    }
}
