#include "manager.h"
#include "inimanager.h"
#include "sqlmanager.h"

#include <QtWidgets>

Manager::Manager(QObject *parent) : QObject(parent)
{
    errorStr = "no error";
}

Manager::~Manager(){

}

bool Manager::init(){
    IniManager iniManager;
    if(iniManager.initIni()){
        SqlManager sqlManager;
        if(sqlManager.initDb()){
            //todo
            return true;
        }else{
            errorStr = sqlManager.getError();
            return false;
        }
    }else{
        errorStr = iniManager.getError();
        return false;
    }
}

QString Manager::getError(){
    return errorStr;
}
