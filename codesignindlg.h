#ifndef CODESIGNINDLG_H
#define CODESIGNINDLG_H

#include <QDialog>
#include <QProcess>

namespace Ui {
class CodeSignInDlg;
}

class CodeSignInDlg : public QDialog
{
    Q_OBJECT

public:
    explicit CodeSignInDlg(QWidget *parent = 0);
    ~CodeSignInDlg();

	QProcess *process;

private slots:
    void on_getQrCodePushButton_clicked();
    void readOutput();

private:
    QString out;
    Ui::CodeSignInDlg *ui;
    

};

#endif // CODESIGNINDLG_H
