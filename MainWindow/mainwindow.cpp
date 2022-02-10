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
    w_Auth.show();
}

void MainWindow::ConnectButton() {
    QObject::connect(&w_Auth, &AuthWindow::SignInClicked, this, &MainWindow::SignIn);
}

void MainWindow::SignIn() {
    if (!query.SignInQuery(w_Auth.OnPasswordLineEdit(), w_Auth.OnLoginLineEdit())) {
        QMessageBox::warning(this, "Authorize", "Wrong login or password");
    } else {
        w_Auth.close();
        this->show();
    }
}

