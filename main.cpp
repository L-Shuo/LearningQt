#include "mainwindow.h"
#include <QApplication>
#include "painterwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    PainterWidget w;
    w.show();
    return a.exec();
}
