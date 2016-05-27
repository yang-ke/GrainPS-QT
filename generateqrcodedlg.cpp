#include "generateqrcodedlg.h"
#include "ui_generateqrcodedlg.h"
#include "sqlstr.h"
#include "sqlmanager.h"
#include "globalconfig.h"

#include "QSqlTableModel"
#include "QTableView"
#include "QMessageBox"
#include "QUuid"
#include "QSqlError"
#include "QSqlQuery"
#include "QSqlRecord"

#include <QtWidgets>

#include "QDebug"

enum ColumnIndex{
    AUTO_ID = 0,
    GRAIN_TYPE = 1,
    UID = 2,
    SEQUENCE_NUMBER = 3,
    GENERATE_DATE =4,
    GENERATER = 5
};

enum DaySelect{
    TODAY = 0,
    YESTERDAY = -1,
    TOMORROW = 1,
    DAY_BEFORE_YESTERDAY = -2,
    DAY_AFTER_TOMORROW = 2
};

GenerateQrCodeDlg::GenerateQrCodeDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GenerateQrCodeDlg)
{
    ui->setupUi(this);

    ui->startDateEdit->setDate(QDate::currentDate());
    ui->endDateEdit->setDate(QDate::currentDate().addDays(TOMORROW));

    ui->grainTypeComboBox->addItems(SqlManager::getKeyMap(QObject::tr("grainType")));


    //
    QSqlTableModel  *SEQUENCE_NUMBER_model = new QSqlTableModel;

    QString generateStartDate = ui->startDateEdit->text();
    QString generateEndDate = ui->endDateEdit->text();

    SEQUENCE_NUMBER_model->setTable("dbo.GPS_SEQUENCE_NUMBER");
    SEQUENCE_NUMBER_model->setFilter(SqlStr::SEQUENCE_NUMBER_queryStr.arg(generateStartDate).arg(generateEndDate));
    SEQUENCE_NUMBER_model->removeColumn(0);
    SEQUENCE_NUMBER_model->select();

    ui->generateQrCodeTableView->setModel(SEQUENCE_NUMBER_model);
    ui->generateQrCodeTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->generateQrCodeTableView->resizeColumnsToContents();
    ui->generateQrCodeTableView->setColumnHidden(UID,true);
    ui->generateQrCodeTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QHeaderView *header = ui->generateQrCodeTableView->horizontalHeader();
    header->setStretchLastSection(true);

    ui->generateQrCodeTableView->show();
}

GenerateQrCodeDlg::~GenerateQrCodeDlg()
{
    delete ui;
}

void GenerateQrCodeDlg::on_queryPushButton_clicked()
{
    QSqlTableModel * tm = qobject_cast<QSqlTableModel *>(ui->generateQrCodeTableView->model());
    if (tm){
        tm->select();
    }
}



void GenerateQrCodeDlg::on_generatePushButton_clicked()
{
    int codeCount = ui->generateCountSpinBox->value();
    QString grainType = ui->grainTypeComboBox->currentText();

    QString userName = "test"; //-----------------------------getUserName();

    int r = QMessageBox::question(NULL,"question",QObject::tr("confirm to generate type:%1's %2 codes?").arg(grainType).arg(codeCount),QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if(r == QMessageBox::Yes){

        QSqlTableModel * tm = qobject_cast<QSqlTableModel *>(ui->generateQrCodeTableView->model());
        if (tm){
            QSqlRecord record = tm->record();

            for(int i = 0 ; i < codeCount ; i++){
                QUuid uid = QUuid::createUuid();
                QString iStr = QString::number(i+1);
                QDateTime dt = QDateTime::currentDateTime();
                record.setValue("GRAIN_TYPE",grainType);
                record.setValue("UID",uid.toString());
                record.setValue("SEQUENCE_NUMBER",iStr);
                record.setValue("GENERATE_DATE",dt);
                record.setValue("GENERATER",userName);
                tm->insertRecord(-1,record);
            }
            if(!tm->submitAll()){
                qDebug() << tm->lastError();
            }
            tm->select();
        }
    }
}
