#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() noexcept {
    delete ui;
}

void MainWindow::OnRegularCustomersClicked() {
    RegularCustomers *regularCustomers = new RegularCustomers;
    regularCustomers->setWindowTitle("Regular Customers");
    regularCustomers->setAttribute(Qt::WA_DeleteOnClose);
    regularCustomers->show();
}

void MainWindow::OnBookingClicked() {
    Booking *booking = new Booking;
    booking->setWindowTitle("Booking");
    booking->setAttribute(Qt::WA_DeleteOnClose);
    booking->show();
}
