#ifndef BOOKING_HPP_
#define BOOKING_HPP_

#include "window_base.hpp"

namespace Ui { class Booking; }

class Booking : public window_base {
Q_OBJECT

public:
    explicit Booking(window_base *parent = nullptr);

    ~Booking() noexcept;

    void createUi();

private:
    Ui::Booking *ui;
};


#endif // BOOKING_HPP_
