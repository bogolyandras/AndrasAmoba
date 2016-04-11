#include "mainwindow.h"
#include "controller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Controller q;
    MainWindow w;

    w.setController(&q);
    w.show();

    return a.exec();
}
