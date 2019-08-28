#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QDialogButtonBox>

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
    void on_actionOpen_triggered();

    void on_actionClose_triggered();

    void on_actionSave_triggered();

    void on_actionAbout_triggered();

    void textChanged();

private:
    Ui::MainWindow *ui;
    bool m_textChanged = false;
};

#endif // MAINWINDOW_H
