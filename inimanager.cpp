#include "inimanager.h"
#include "globalconfig.h"
#include "QFile"
#include "QSettings"
#include "QString"

#include "QDebug"

QString globalConfigFileName = "config.ini";

QString version = "1.0.0.0,0001";

QString dbDriver = "sql server";
QString dbServer = "10.2.0.18";
int dbPort = 1433;
QString dbDataBase = "MERPII";
QString dbUserName = "sa";
QString dbPassword = "liteon";
bool supportTransactions = false;

IniManager::IniManager(QObject *parent) : QObject(parent)
{
    errorStrIni = "no ini error";
}

IniManager::~IniManager(){

}

bool IniManager::initIni(){
    QFile configIni(globalConfigFileName);
    if(configIni.exists()){
        QSettings *setting = new QSettings(globalConfigFileName,QSettings::IniFormat);

        version = setting->value("/common/version").toString();

        dbDriver = setting->value("/database/driver").toString();
        dbServer = setting->value("/database/server").toString();
        dbPort = setting->value("/database/port").toInt();
        dbDataBase = setting->value("/database/database").toString();
        dbUserName = setting->value("/database/username").toString();
        dbPassword = setting->value("/database/password").toString();

        supportTransactions = setting->value("/datavase/supportTransactions").toBool();
        delete setting;
        return true;
    }else{
        qDebug()<< "config.ini not found,trying to regenerate file.";
        bool flag = setDefIni();
        return flag;
    }

}

bool IniManager::setDefIni(){
    QSettings *setting = new QSettings(globalConfigFileName,QSettings::IniFormat);

    setting->setValue("/common/version",version);

    setting->setValue("/database/driver",dbDriver);
    setting->setValue("/database/server",dbServer);
    setting->setValue("/database/port",dbPort);
    setting->setValue("/database/database",dbDataBase);
    setting->setValue("/database/username",dbUserName);
    setting->setValue("/database/password",dbPassword);
    setting->setValue("/database/supportTransactions",supportTransactions);

    delete setting;
    qDebug()<< "regenerate successful!";
    return true;
}

QString IniManager::getError(){
    return errorStrIni;
}

