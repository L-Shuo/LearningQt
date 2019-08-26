#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include "lottery.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_startLottery_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *ItemModel;
    Lottery *lottery_widget;
};

#endif // MAINWINDOW_H
