#ifndef REGULAR_CUSTOMERS_HPP_
#define REGULAR_CUSTOMERS_HPP_

#include <QWidget>
#include <QString>
#include <QStringList>
#include <QTableView>
#include <QSqlQueryModel>

namespace Ui { class RegularCustomers; }

class RegularCustomers : public QWidget {
Q_OBJECT

public:
    explicit RegularCustomers(QWidget *parent = nullptr);

    ~RegularCustomers() noexcept;

public:
    void createUi();

    void setupModel(const QStringList &);

private:
    Ui::RegularCustomers *ui;
    QSqlQueryModel *model;
};


#endif // REGULAR_CUSTOMERS_HPP_
