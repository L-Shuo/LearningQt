#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "option.h"
#include "fastbootcmd.h"

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
    void on_userDataBtn_clicked();
    void on_systemBtn_clicked();
    void showCmdInfo(QString info);
    void on_lineEdit_textChanged(const QString &arg1);
    void on_bootBtn_clicked();

private:
    Ui::MainWindow *ui;
    Option *option;
    FastbootCmd *fbc;
};

#endif // MAINWINDOW_H
