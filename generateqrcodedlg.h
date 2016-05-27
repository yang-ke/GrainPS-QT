#ifndef GENERATEQRCODEDLG_H
#define GENERATEQRCODEDLG_H

#include <QDialog>

namespace Ui {
class GenerateQrCodeDlg;
}

class GenerateQrCodeDlg : public QDialog
{
    Q_OBJECT

public:
    explicit GenerateQrCodeDlg(QWidget *parent = 0);
    ~GenerateQrCodeDlg();
signals:

private slots:
    void on_queryPushButton_clicked();

    void on_generatePushButton_clicked();

private:
    Ui::GenerateQrCodeDlg *ui;
    enum ColumnIndex;
};

#endif // GENERATEQRCODEDLG_H
