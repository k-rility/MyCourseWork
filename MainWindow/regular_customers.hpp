#ifndef REGULAR_CUSTOMERS_HPP_
#define REGULAR_CUSTOMERS_HPP_

#include "window_base.hpp"
#include "DataBase/db_interface.hpp"

namespace Ui { class RegularCustomers; }

class RegularCustomers : public window_base {
Q_OBJECT

public:
    explicit RegularCustomers(window_base *parent = nullptr);

    ~RegularCustomers() noexcept;

    void createUi();

private:
    Ui::RegularCustomers *ui;
};


#endif // REGULAR_CUSTOMERS_HPP_
