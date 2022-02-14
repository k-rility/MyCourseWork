#include "booking_dialog_add.hpp"
#include "ui_booking_dialog_add.h"


booking_dialog_add::booking_dialog_add(QWidget *parent) : QDialog(parent), ui(new Ui::booking_dialog_add) {
    ui->setupUi(this);
    setupModel();
    model->insertRow(model->rowCount(QModelIndex()));
    mapper->toLast();
}

booking_dialog_add::~booking_dialog_add() {
    delete ui;
}

void booking_dialog_add::setupModel() {
    model = new QSqlTableModel(this);
    model->setTable("Booking");
    model->select();

    mapper = new QDataWidgetMapper();
    mapper->setModel(model);
    mapper->addMapping(ui->UserLineEdit, 1);
    mapper->addMapping(ui->UserCountLineEdit, 2);
    mapper->addMapping(ui->DateLineEdit, 3);
}

void booking_dialog_add::OnAcceptClicked() {
    mapper->submit();
    model->submitAll();
    emit AcceptClicked();
    this->close();
}

