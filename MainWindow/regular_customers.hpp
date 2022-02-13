#ifndef REGULAR_CUSTOMERS_HPP_
#define REGULAR_CUSTOMERS_HPP_

#include <QWidget>
#include <QSqlQueryModel>
#include <QTableView>

#include "DataBase/db_interface.hpp"

namespace Ui { class RegularCustomers; }

class RegularCustomers : public QWidget {
Q_OBJECT

public:
    explicit RegularCustomers(QWidget *parent = nullptr);

    ~RegularCustomers() noexcept;

    void createUi();

private:
    Ui::RegularCustomers *ui;
    db_interface query;
};


#endif // REGULAR_CUSTOMERS_HPP_
