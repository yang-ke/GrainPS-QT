#include "sqlstr.h"
#include "QString"


QString SqlStr::dsnStr = QString("Driver={%1};server=%2;database=%3;uid=%4;pwd=%5");
QString SqlStr::setSessionStr = QString("INSERT INTO GPS_SESSION (DATETIME,IP_ADDRESS) VALUES (GETDATE(),'%1')");
QString SqlStr::SEQUENCE_NUMBER_queryStr = QString("GENERATE_DATE >= '%1' AND GENERATE_DATE < '%2'");
QString SqlStr::getKeyMapStr = QString("SELECT K FROM dbo.GPS_CONFIG_KEYMAP WHERE (KEY_NAME = '%1')");
QString SqlStr::SEQUENCE_NUMBER_insertStr = QString("INSERT INTO GPS_SEQUENCE_NUMBER (GRAIN_TYPE, UID, SEQUENCE_NUMBER, GENERATE_DATE, GENERATER) VALUES ('%1', '%2', '%3', GETDATE(), '%4')");
