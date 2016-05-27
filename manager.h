#ifndef MANAGER_H
#define MANAGER_H

#include "QString"
#include <QObject>


class Manager : public QObject
{
    Q_OBJECT
public:
    explicit Manager(QObject *parent = 0);
    virtual ~Manager();

    QString errorStr;

    bool init();
    QString getError();

public slots:


signals:


private:


};

#endif // MANAGER_H
