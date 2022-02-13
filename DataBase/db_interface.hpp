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
#include <QSqlTableModel>


class db_interface : public QObject {
Q_OBJECT
public:

    explicit db_interface(QObject *parent = nullptr,
                          const QString &DataBasePath = "/home/kirill/Рабочий стол/CourseDB");

    ~db_interface() noexcept;

    inline bool ConnectToDB(const QString &);

    bool SignInQuery(const QString &, const QString &);

    void QuerySetupModel(const QString &, const QString &, const QStringList &);

    QSqlTableModel *getModel() const;

    void selectModel() const;

    bool CloseDataBase();


private:

    QSqlDatabase database;
    QSqlQuery query;
    QSqlTableModel *model;
};


#endif // DB_INTERFACE_HPP_
