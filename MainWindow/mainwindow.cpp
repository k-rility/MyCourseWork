#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ConnectButton();
    ui->setupUi(this);
}

MainWindow::~MainWindow() noexcept {
    delete ui;
}

void MainWindow::AuthShow() {
    ui_Auth.show();
}

void MainWindow::ConnectButton() {
    QObject::connect(&ui_Auth, &AuthWindow::SignInClicked, this, &MainWindow::SignIn);
}

void MainWindow::OnRegularCustomersClicked() {
    this->hide();
    ui_RegularCustomers.show();
}

void MainWindow::OnBookingClicked() {
    this->hide();
    ui_Booking.show();
}

void MainWindow::SignIn() {
    if (!query.SignInQuery(ui_Auth.OnPasswordLineEdit(), ui_Auth.OnLoginLineEdit())) {
        QMessageBox::warning(this, "Authorize", "Wrong login or password");
    } else {
        ui_Auth.close();
        this->show();
    }
}

