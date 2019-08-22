#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    option = new Option(this);
    fbc = new FastbootCmd(this);
    option->setWorkspace(ui->lineEdit->text());
    connect(fbc,SIGNAL(showInfo(QString)),this,SLOT(showCmdInfo(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    qDebug() << arg1;
    option->setWorkspace(arg1);
}

void MainWindow::showCmdInfo(QString info)
{
    ui->textEdit->setText(info);
}

void MainWindow::on_userDataBtn_clicked()
{
    QString image = "\\userdata.img";
    QString partition = "userdata";
    fbc->flash(image,partition);
}

void MainWindow::on_systemBtn_clicked()
{
    QString image = "\\system.img";
    QString partition = "system";
    fbc->flash(image,partition);
}

void MainWindow::on_bootBtn_clicked()
{
    QString image = "\\boot.img";
    QString partition = "boot";
    fbc->flash(image,partition);
}
