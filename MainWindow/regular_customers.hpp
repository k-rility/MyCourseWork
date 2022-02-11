#ifndef REGULAR_CUSTOMERS_HPP_
#define REGULAR_CUSTOMERS_HPP_

#include <QWidget>


namespace Ui { class RegularCustomers; }

class RegularCustomers : public QWidget {
Q_OBJECT

public:
    explicit RegularCustomers(QWidget *parent = nullptr);

    ~RegularCustomers() noexcept;

private:
    Ui::RegularCustomers *ui;
};


#endif // REGULAR_CUSTOMERS_HPP_
