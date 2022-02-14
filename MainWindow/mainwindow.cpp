#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ConnectButton();
    ui_RegularCustomers.setupModel("SELECT * FROM Clients WHERE count > 5",
                                   QStringList()
                                           << trUtf8("id")
                                           << trUtf8("name")
                                           << trUtf8("count"));
    ui_RegularCustomers.createUi();

    ui_Booking.setupModel("SELECT * FROM Booking", QStringList()
            << trUtf8("id")
            << trUtf8("status")
            << trUtf8("date")
            << trUtf8("user")
            << trUtf8("user count"));
    ui_Booking.createUi();
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
//    this->hide();
    ui_RegularCustomers.show();
}

void MainWindow::OnBookingClicked() {
//    this->hide();
    ui_Booking.show();
}

void MainWindow::SignIn() {
    if (!db.SignInQuery(ui_Auth.OnPasswordLineEdit(), ui_Auth.OnLoginLineEdit())) {
        QMessageBox::warning(this, "Authorize", "Wrong login or password");
    } else {
        ui_Auth.close();
        this->show();
    }
}

