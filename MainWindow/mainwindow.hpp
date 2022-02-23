#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "MainWindow/booking.hpp"
#include "MainWindow/regular_customers.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_RegularCustomers_clicked();

    void on_Booking_clicked();

private:
    Ui::MainWindow *ui;
    Booking *booking;
    RegularCustomers *regularCustomers;
};

#endif // MAINWINDOW_H
