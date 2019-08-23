#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fbc = new FastbootCmd(this);
    Option::getInstance()->setWorkspace(ui->lineEdit->text());
    connect(fbc,SIGNAL(showInfo(QString)),this,SLOT(showCmdInfo(QString)));
    connect(this,SIGNAL(doCmd(QString)),fbc,SLOT(execCmd(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    Option::getInstance()->setWorkspace(arg1);
}

void MainWindow::showCmdInfo(QString info)
{
    ui->textEdit->append(info);
}

void MainWindow::on_userDataBtn_clicked()
{
    emit doCmd("flash userdata");
}

void MainWindow::on_systemBtn_clicked()
{
    emit doCmd("flash system");
}

void MainWindow::on_bootBtn_clicked()
{
    emit doCmd("flash boot");
}

void MainWindow::on_lkBtn_clicked()
{
    emit doCmd("flash bootloader");
}


void MainWindow::on_vendorBtn_clicked()
{
    emit doCmd("flash vendor");
}

void MainWindow::on_autoReboot_checkBox_stateChanged(int value)
{
   Option::getInstance()->set_autoReboot(value==0 ? false:true);
}

