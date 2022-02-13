#ifndef BOOKING_HPP_
#define BOOKING_HPP_

#include <QWidget>


namespace Ui { class Booking; }

class Booking : public QWidget {
Q_OBJECT

public:
    explicit Booking(QWidget *parent = nullptr);

    ~Booking() ;

private:
    Ui::Booking *ui;
};


#endif // BOOKING_HPP_
