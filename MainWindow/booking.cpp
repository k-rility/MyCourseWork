#include "booking.hpp"
#include "ui_booking.h"

Booking::Booking(QWidget *parent) : QWidget(parent), ui(new Ui::Booking) {
    setupModel(QStringList()
                       << trUtf8("id")
                       << trUtf8("user")
                       << trUtf8("user_count")
                       << trUtf8("date")
                       << trUtf8("status"));
    ui->setupUi(this);
    setupMapper();
    createUi();
}

Booking::~Booking() {
    delete ui;
}

void Booking::createUi() {
    ui->tableView->setModel(model);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    ui->tableView->resizeColumnsToContents();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    ui->tableView->setSortingEnabled(true);

    ui->comboBox_Status->addItems(QStringList() << "booked" << "not booked");
}

void Booking::setupMapper() {
    mapper = new QDataWidgetMapper();
    mapper->setModel(model);
    mapper->addMapping(ui->lineEdit_User, 1);
    mapper->addMapping(ui->dateTimeEdit_from, 2);
    mapper->addMapping(ui->dateTimeEdit_until, 3);
    mapper->addMapping(ui->comboBox_Status, 4);

    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
}

void Booking::setupModel(const QStringList &Headers) {
    model = new QSqlQueryModel(this);
    for (int i = 0, j = 0; i < model->columnCount(); i++, j++) {
        model->setHeaderData(i, Qt::Horizontal, Headers[j]);
    }
}

void Booking::OnSubmitClicked() {
    mapper->submit();
    model->insertRow(model->rowCount(QModelIndex()));
    mapper->toLast();
}
