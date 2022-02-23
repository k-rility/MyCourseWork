#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() noexcept {
    delete ui;
}

void MainWindow::on_RegularCustomers_clicked()
{
    regularCustomers = new RegularCustomers;
    regularCustomers->setWindowTitle("Regular Customers");
    regularCustomers->setAttribute(Qt::WA_DeleteOnClose);
    regularCustomers->show();
}


void MainWindow::on_Booking_clicked()
{
    booking = new Booking;
    booking->setWindowTitle("Booking");
    booking->setAttribute(Qt::WA_DeleteOnClose);
    booking->show();
}

