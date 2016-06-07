#ifndef CODESIGNINCONFIGDLG_H
#define CODESIGNINCONFIGDLG_H

#include <QDialog>

namespace Ui {
class codeSignInConfigDlg;
}

class codeSignInConfigDlg : public QDialog
{
    Q_OBJECT

public:
    explicit codeSignInConfigDlg(QWidget *parent = 0);
    ~codeSignInConfigDlg();

private:
    Ui::codeSignInConfigDlg *ui;
};

#endif // CODESIGNINCONFIGDLG_H
