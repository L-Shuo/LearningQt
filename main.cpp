#include "mainwindow.h"
#include <QApplication>
#include "utils/testsmart.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    test_func();
    return a.exec();
}
