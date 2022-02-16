#ifndef MAINWINDOW_HPP_
#define MAINWINDOW_HPP_

#include <QMainWindow>
#include <QWidget>
#include <QMessageBox>
#include <QTableView>

#include "DataBase/db_interface.hpp"

#include "AuthWindow/authwindow.hpp"
#include "MainWindow/regular_customers.hpp"
#include "MainWindow/booking.hpp"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() noexcept;

private slots:

    void OnRegularCustomersClicked();

    void OnBookingClicked();

private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_HPP_
