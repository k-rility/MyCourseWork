
#include "mainwindow_interface.hpp"
#include "ui_mainwindow_interface.h"


mainwindow_interface::mainwindow_interface(QWidget *parent) : QWidget(parent), ui(new Ui::mainwindow_interface) {
    ui->setupUi(this);
}

mainwindow_interface::~mainwindow_interface() {
    delete ui;
}

void mainwindow_interface::OnButtonClicked() {
    emit ButtonClicked();
}

