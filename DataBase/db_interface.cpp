#include "db_interface.hpp"

DataBaseInterface::DataBaseInterface(QObject *parent) : QObject(parent) {}

DataBaseInterface::~DataBaseInterface() {}

bool DataBaseInterface::ConnectToDataBase(const QString &PathToDataBase) {
    database = QSqlDatabase::addDatabase("QSQLITE");
    if (!QFile(PathToDataBase).exists()) {
        qDebug() << "Invalid database path" << database.lastError();
        return false;
    }

    database.setDatabaseName(PathToDataBase);

    if (!database.open()) {
        qDebug() << "Database not open" << database.lastError();
        return false;
    }
    return true;
}

bool DataBaseInterface::SignInQuery(const QString &password, const QString &login) {
    QSqlQuery query;
    QString QueryString = "SELECT * FROM AdminPass WHERE login='%1'";
    if (!query.exec(QueryString.arg(login))) {
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

bool DataBaseInterface::CloseDataBase() {
    database.close();
}

bool DataBaseInterface::InsertIntoBookingTable(const QVariantList &data) {
    QSqlQuery query;
//    QString QueryString = "INSERT INTO Booking (STATUS, USER, USER_COUNT, DATE) VALUES (:STATUS,:USER,:USER_COUNT,:DATE)";
    QString QueryString = "INSERT INTO Booking (STATUS, USER, USER_COUNT) VALUES (:STATUS,:USER,:USER_COUNT)";
    query.prepare(QueryString);
    query.bindValue(":STATUS", data[0].toBool());
    query.bindValue(":USER", data[1].toString());
    query.bindValue(":USER_COUNT", data[2].toInt());
//    query.bindValue(":DATE", data[3].toDateTime());
    if (!query.exec()) {
        qDebug() << "Error insert into Booking";
        qDebug() << query.lastError() << " : " << query.lastQuery();
        return false;
    } else {
        return true;
    }
    return false;
}
