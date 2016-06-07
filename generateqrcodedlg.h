#ifndef GENERATEQRCODEDLG_H
#define GENERATEQRCODEDLG_H

#include <QDialog>
#include <QtPrintSupport/QPrinter>
#include <QProcess>

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

    void on_selectAllPushButton_clicked();

    void on_printPushButton_clicked();

    void plotPic(QPrinter *printer);

    void on_generateQrCodeTableView_clicked(const QModelIndex &index);

private:
    Ui::GenerateQrCodeDlg *ui;
    enum ColumnIndex;
    enum DaySelect;
    QString uid;
    QString sequenceNumber;
    void generateQrCodeGenerateInf(QString UID , QString SEQUENCE_NUMBER);
    QProcess process;
};

#endif // GENERATEQRCODEDLG_H
