#include "regular_customers.hpp"
#include "ui_regular_customers.h"


RegularCustomers::RegularCustomers(QWidget *parent) : QWidget(parent), ui(new Ui::RegularCustomers) {
    ui->setupUi(this);
}

RegularCustomers::~RegularCustomers() {
    delete ui;
}

void RegularCustomers::setupModel(const QString &TableName, const QStringList &Headers) {
    model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM Clients WHERE count > 5");
    for (int i = 0, j = 0; i < model->columnCount(); i++, j++) {
        model->setHeaderData(i, Qt::Horizontal, Headers[j]);
    }
}

void RegularCustomers::createUi() {
    ui->tableView->setModel(model);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    ui->tableView->resizeColumnsToContents();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
}


