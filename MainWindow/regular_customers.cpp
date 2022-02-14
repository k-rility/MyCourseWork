#include "regular_customers.hpp"
#include "ui_regular_customers.h"


RegularCustomers::RegularCustomers(QWidget *parent) : QWidget(parent), ui(new Ui::RegularCustomers) {
//    db.ConnectToDataBase("/home/kirill/Рабочий стол/CourseDB");
//    setupModel("SELECT * FROM Clients WHERE count > 5",
//               QStringList()
//                       << trUtf8("id")
//                       << trUtf8("name")
//                       << trUtf8("count"));
    ui->setupUi(this);
//    createUi();
}

RegularCustomers::~RegularCustomers() {
    delete ui;
}

void RegularCustomers::setupModel(const QString &Query, const QStringList &Headers) {
    model = new QSqlQueryModel;
    model->setQuery(Query);
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

void RegularCustomers::OnBackClicked() {
    this->close();
}


