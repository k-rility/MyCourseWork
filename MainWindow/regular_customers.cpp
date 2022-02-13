#include "regular_customers.hpp"
#include "ui_regular_customers.h"


RegularCustomers::RegularCustomers(QWidget *parent) : QWidget(parent), ui(new Ui::RegularCustomers) {
    ui->setupUi(this);
    query.QuerySetupModel("SELECT user FROM RegularCustomers WHERE count > 5", "RegularCustomers",
                          QStringList() << trUtf8("id") << trUtf8("user") << trUtf8("count"));
    createUi();
}

RegularCustomers::~RegularCustomers() {
    delete ui;
}

void RegularCustomers::createUi() {
    ui->tableView->setModel(query.getModel());

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    ui->tableView->resizeColumnsToContents();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    query.selectModel();
}


