#include "codesigninconfigdlg.h"
#include "ui_codesigninconfigdlg.h"

codeSignInConfigDlg::codeSignInConfigDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::codeSignInConfigDlg)
{
    ui->setupUi(this);
}

codeSignInConfigDlg::~codeSignInConfigDlg()
{
    delete ui;
}
