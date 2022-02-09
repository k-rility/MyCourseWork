#include "db_interface.hpp"

db_interface::db_interface(QObject *parent) : QObject(parent),
                                              database(QSqlDatabase::addDatabase("QSQLITE")) {
    if (!ConnectToDB("/home/kirill/Рабочий стол/CourseDB")) {
        qDebug() << "Could not connecting to DataBase";
    }
}

db_interface::~db_interface() {}

inline bool db_interface::ConnectToDB(const QString &PathToDB) {

    if (!QFile(PathToDB).exists()) {
        qDebug() << "Invalid database path" << database.lastError();
        return false;
    }

    database.setDatabaseName(PathToDB);

    if (!database.open()) {
        qDebug() << "Database not open" << database.lastError();
        return false;
    }
    return true;
}

bool db_interface::SignInQuery(const QString &password, const QString &login) {
    QString QueryStr = "SELECT * FROM AdminPass WHERE login='%1'";
    if (!query.exec(QueryStr.arg(login))) {
        qDebug() << "Unable to execute query - exiting" << query.lastError() << " : " << query.lastQuery();
        return false;
    }
    QSqlRecord Rec = query.record();
    query.next();
    if (login != query.value(Rec.indexOf("login")).toString() ||
        password != query.value(Rec.indexOf("password")).toString()) {
        return false;
    } else if (query.value(Rec.indexOf("login")).isNull() ||
               query.value(Rec.indexOf("password")).isNull()) {
        return false;
    }
    return true;
}
