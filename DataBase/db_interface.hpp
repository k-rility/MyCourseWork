#ifndef DB_INTERFACE_HPP_
#define DB_INTERFACE_HPP_

#include <QObject>
#include <QSql>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QString>
#include <QFile>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariantList>
#include <QDateTime>
#include <QSqlQueryModel>


class DataBaseInterface : public QObject {
Q_OBJECT
public:

    explicit DataBaseInterface(QObject *parent = nullptr);

    ~DataBaseInterface() noexcept;

    bool ConnectToDataBase(const QString &);

    bool SignInQuery(const QString &, const QString &);

    bool CloseDataBase();

    bool OpenDataBase();


private:

    QSqlDatabase database;
};


#endif // DB_INTERFACE_HPP_
