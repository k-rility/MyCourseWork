#ifndef REGULAR_CUSTOMERS_HPP_
#define REGULAR_CUSTOMERS_HPP_

#include <QWidget>
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlQueryModel>
#include <QStringList>
#include <QString>

#include "DataBase/db_interface.hpp"

namespace Ui { class RegularCustomers; }

class RegularCustomers : public QWidget {
Q_OBJECT

public:
    explicit RegularCustomers(QWidget *parent = nullptr);

    ~RegularCustomers() noexcept;

    void createUi();

    void setupModel(const QString&, const QStringList&);

private:
    Ui::RegularCustomers *ui;
    QSqlQueryModel *model;
};


#endif // REGULAR_CUSTOMERS_HPP_
