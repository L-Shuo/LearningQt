#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDomDocument>
#include <QDebug>
#include <QXmlParseException>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    lottery_widget = new Lottery();
    QDomDocument doc("mydocument");
    QFile file("C:\\Users\\liushuo\\Documents\\choujiang\\nums.xml");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Open error";
        return;
    }
    if (!doc.setContent(&file)) {
        qDebug() << "doc Open error";
        file.close();
        return;
    }
    file.close();

    // print out the element names of all elements that are direct children
    // of the outermost element.
    QDomElement docElem = doc.documentElement();
    QDomNodeList numlist = docElem.elementsByTagName("Number");
    ItemModel = new QStandardItemModel(this);
    for(int i=0;i<numlist.length();i++) {
        //qDebug() << numlist.at(i).toElement().text();
        QStandardItem *item = new QStandardItem(numlist.at(i).toElement().text());
        ItemModel->appendRow(item);
    }
    ui->displayAllList->setModel(ItemModel);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete lottery_widget;
}

void MainWindow::on_startLottery_clicked()
{
    lottery_widget->show();
}
