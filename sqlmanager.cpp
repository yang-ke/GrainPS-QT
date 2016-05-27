#include "sqlmanager.h"
#include "inimanager.h"
#include "globalconfig.h"
#include "sqlstr.h"

#include "QString"
#include "QStringList"

#include "QSqlDatabase"
#include "QSqlQuery"
#include "QSqlDriver"

#include "QHostInfo"

#include "QDebug"
#include "QSqlError"

#include "QDateTime"


SqlManager::SqlManager(QObject *parent) : QObject(parent)
{
    errorStrSql = "no sql error";
}

SqlManager::~SqlManager(){

}
bool SqlManager::initDb(){
    //todo
    return SqlManager::checkConnect();
}

QStringList SqlManager::checkDrivers(){
    //qDebug() << "drivers:";
    QStringList drivers = QSqlDatabase::drivers();
    return drivers;
}



QString SqlManager::getError(){
    return errorStrSql;
}

bool SqlManager::checkConnect(){

    QSqlDatabase dbconn = SqlManager::initDataBase();
    bool connFlag = dbconn.open();
    if(connFlag){
        //qDebug() << "connect successful!";
        SqlManager::setSession(dbconn);

        QSqlDriver *driver = dbconn.driver();
        if(driver->hasFeature(QSqlDriver::Transactions)){
            supportTransactions = true;
        }

        //todo


        return true;
    }else{
        errorStrSql = dbconn.lastError().text();
        //qDebug() << dbconn.lastError().text();
        return false;
    }
    return false;
}

QSqlDatabase SqlManager::initDataBase(){
    QSqlDatabase dbconn = QSqlDatabase::addDatabase("QODBC");
    QString dsn = SqlStr::dsnStr
            .arg(dbDriver).arg(dbServer).arg(dbDataBase).arg(dbUserName).arg(dbPassword);
    dbconn.setDatabaseName(dsn);
    dbconn.setHostName(dbServer);
    dbconn.setPort(dbPort);
    dbconn.setUserName(dbUserName);
    dbconn.setPassword(dbPassword);

    SqlManager::getActiveDb();

    return dbconn;
}

void SqlManager::setSession(QSqlDatabase dbconn){

    QString localHostName = QHostInfo::localHostName();
    QStringList addresslist;
    QHostInfo info = QHostInfo::fromName(localHostName);
    foreach(QHostAddress address,info.addresses()){
        if(address.protocol() == QAbstractSocket::IPv4Protocol)
            addresslist << address.toString();
            //qDebug() <<"IPV4 Address: "<< address.toString();
    }

    QSqlQuery query = QSqlQuery(dbconn);

    foreach(QString add,addresslist){
        QString setSessionStr = SqlStr::setSessionStr.arg(add);
        //qDebug() << setSessionStr;
        query.exec(setSessionStr);
        errorStrSql = query.lastError().text();
        //qDebug() << query.lastError().text();
        //qDebug() << dbconn.lastError().text();
    }
}


QSqlDatabase SqlManager::currentDatabase() const
{
    return QSqlDatabase::database(activeDb);
}

void SqlManager::getActiveDb(){
    QStringList connectionNames = QSqlDatabase::connectionNames();
    bool gotActiveDb = false;
    for (int i = 0; i < connectionNames.count(); ++i) {
        if (connectionNames.at(i) == activeDb) {
            gotActiveDb = true;
        }
    }
    if (!gotActiveDb) {
        activeDb = connectionNames.value(0);
    }
}

QStringList SqlManager::getKeyMap(QString keyName)
{
    QStringList keyMapList;
    QSqlQuery query(SqlStr::getKeyMapStr.arg(keyName));

    while (query.next()) {
        keyMapList << query.value(0).toString();
    }
    return keyMapList;
}


