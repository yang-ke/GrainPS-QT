#ifndef SQLMANAGER_H
#define SQLMANAGER_H

#include <QWidget>

QT_FORWARD_DECLARE_CLASS(QSqlDatabase)
QT_FORWARD_DECLARE_CLASS(QStringList)
QT_FORWARD_DECLARE_CLASS(QString)
QT_FORWARD_DECLARE_CLASS(QSqlDriver)
QT_FORWARD_DECLARE_CLASS(QSqlError)

class SqlManager: public QObject
{
    Q_OBJECT
public:
    explicit SqlManager(QObject *parent = 0);
    virtual ~SqlManager();
    QString errorStrSql;

    QSqlDatabase currentDatabase() const;

    static QStringList getKeyMap(QString keyName);

    bool initDb();
    QString getError();

public slots:

private:
    QString activeDb ;
    static QStringList checkDrivers();
    bool checkConnect();
    QSqlDatabase initDataBase();
    void getActiveDb();

    void setSession(QSqlDatabase dbconn);
};

#endif // SQLMANAGER_H
