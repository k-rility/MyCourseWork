#include "regular_customers.hpp"
#include "ui_regular_customers.h"


RegularCustomers::RegularCustomers(window_base *parent) : window_base(parent), ui(new Ui::RegularCustomers) {
    ui->setupUi(this);
}

RegularCustomers::~RegularCustomers() {
    delete ui;
}

void RegularCustomers::createUi() {
    ui->tableView->setModel(getModel());

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    ui->tableView->resizeColumnsToContents();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
}


