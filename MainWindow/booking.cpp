#include "booking.hpp"
#include "ui_booking.h"

Booking::Booking(window_base *parent) : window_base(parent), ui(new Ui::Booking) {
    ui->setupUi(this);
}

Booking::~Booking() {
    delete ui;
}

void Booking::createUi() {
    ui->tableView->setModel(getModel());

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    ui->tableView->resizeColumnsToContents();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
}