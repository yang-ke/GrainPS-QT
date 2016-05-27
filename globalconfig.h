#ifndef GLOBALCONFIG_H
#define GLOBALCONFIG_H

#include "QString"

//------------------------------------------------------------
extern QString globalConfigFileName;
extern QString userName;


//------------------config.ini--------------------------------

//common
extern QString version;

//database
extern QString dbDriver;
extern QString dbServer;
extern int dbPort;
extern QString dbDataBase;
extern QString dbUserName;
extern QString dbPassword;
extern bool supportTransactions;


#endif // GLOBALCONFIG_H
