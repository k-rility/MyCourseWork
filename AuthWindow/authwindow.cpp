
#include "authwindow.hpp"
#include "ui_authwindow.h"


AuthWindow::AuthWindow(QWidget *parent) : QWidget(parent), ui(new Ui::AuthWindow) {
    ui->setupUi(this);
}

AuthWindow::~AuthWindow() {
    delete ui;
}

QString AuthWindow::OnLoginLineEdit() {
    return ui->LoginLineEdit->text();
}

QString AuthWindow::OnPasswordLineEdit() {
    return ui->PasswordLineEdit->text();
}

void AuthWindow::OnSignInClicked() {
    emit SignInClicked();
}
