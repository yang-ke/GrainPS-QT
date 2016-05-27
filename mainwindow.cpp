#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "generateqrcodedlg.h"
#include "QMessageBox"
#include "QCloseEvent"
#include "QDebug"

#include <QWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionGenerateCode_triggered()
{
    GenerateQrCodeDlg generateQCDlg;

    generateQCDlg.exec();
}

void MainWindow::on_actionExit_triggered()
{
    int r = QMessageBox::question(this,tr("Close Hint"),tr("Are you sure you want to quit?"),QMessageBox::Yes|QMessageBox::Default,QMessageBox::No|QMessageBox::Escape);
    if(r == QMessageBox::Yes){
        qApp->quit();
    }else{

    }
}

void MainWindow::closeEvent(QCloseEvent *event){
    int r = QMessageBox::question(this,tr("Close Hint"),tr("Are you sure you want to quit?"),QMessageBox::Yes|QMessageBox::Default,QMessageBox::No|QMessageBox::Escape);
    if(r == QMessageBox::Yes){
        event->accept();
    }else{
        event->ignore();
    }
}

void MainWindow::on_actionOther_triggered()
{

}
