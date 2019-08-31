#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    virtual void timerEvent(QTimerEvent *event);
private slots:
    void on_pushBtn();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    int timelist[4];
    bool start = false;
    int timeInterval = 150;
};

#endif // MAINWINDOW_H
