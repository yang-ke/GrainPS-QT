#include "mainwindow.h"
#include "manager.h"
#include <QApplication>
#include <QtWidgets>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Manager manager;

    if(!manager.init()){
        QString errorMsg = manager.getError();
        qDebug() << "error:" << errorMsg;
    }
    MainWindow w;

    w.show();

    return a.exec();
}
