#include "booking_dialog_add.hpp"
#include "ui_booking_dialog_add.h"


booking_dialog_add::booking_dialog_add(QWidget *parent) :QDialog(parent), ui(new Ui::booking_dialog_add) {
    ui->setupUi(this);
}

booking_dialog_add::~booking_dialog_add() {
    delete ui;
}

