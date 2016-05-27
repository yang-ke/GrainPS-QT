#ifndef INIMANAGER_H
#define INIMANAGER_H

#include "QString"
#include <QObject>

class IniManager : public QObject
{
    Q_OBJECT
public:
    explicit IniManager(QObject *parent = 0);
    virtual ~IniManager();
    QString errorStrIni;

    bool initIni();
    QString getError();
private:
    bool setDefIni();
};

#endif // INIMANAGER_H
