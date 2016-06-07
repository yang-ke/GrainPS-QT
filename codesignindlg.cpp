#include "codesignindlg.h"
#include "ui_codesignindlg.h"

#include "QWidget"
#include "QDebug"
#include "QIODevice"
#include "QJsonObject"
#include "QJsonParseError"
#include "QJsonArray"
#include "QString"
#include "QByteArray"

CodeSignInDlg::CodeSignInDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CodeSignInDlg)
{
    ui->setupUi(this);
	process = new QProcess(this);
    QObject::connect(process,SIGNAL(readyRead()),this,SLOT(readOutput()));
	QObject::connect(process, static_cast<void(QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished),
        [=](int exitCode, QProcess::ExitStatus exitStatus)
    {
        ui->getQrCodePushButton->setDisabled(false);
        qDebug() << "exitCode:" << exitCode;
        qDebug() << "exitStatus:" << exitStatus;
    });
}

CodeSignInDlg::~CodeSignInDlg()
{
    QObject::disconnect(process,0,0,0);
    process->kill();
    delete ui;
}

void CodeSignInDlg::on_getQrCodePushButton_clicked()
{
    QString program = ".\\zbar\\bin\\zbarcam.exe";
    QStringList arguments ;
    arguments << "--nodisplay";
    process->start(program,arguments);
	qDebug() << "process start";
	ui->getQrCodePushButton->setDisabled(true);
}

void CodeSignInDlg::readOutput()
{
	out = process->readAllStandardOutput();
	ui->QrCodeLineEdit->setText(out.section('{', 2, 2).split('}').at(0));
  
}
