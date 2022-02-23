#include "booking.hpp"
#include "ui_booking.h"


Booking::Booking(QWidget *parent) : QWidget(parent), ui(new Ui::Booking) {
    setupModel(QStringList()
                       << trUtf8("id")
                       << trUtf8("user")
                       << trUtf8("date from")
                       << trUtf8("date until")
                       << trUtf8("status"));
    ui->setupUi(this);
    setupMapper();
    createUi();

    auto *dateFrom = new DataEditDelegate(ui->tableView);
    ui->tableView->setItemDelegateForColumn(2, dateFrom);
    auto *dateUntil = new DataEditDelegate(ui->tableView);
    ui->tableView->setItemDelegateForColumn(3, dateUntil);
    auto *comboBox = new ComboBoxItemDelegate(ui->tableView);
    ui->tableView->setItemDelegateForColumn(4, comboBox);
}

Booking::~Booking() {
    mapper->submit();
    model->submitAll();
    delete mapper;
    delete model;
    delete ui;
}

void Booking::createUi() {
    ui->tableView->setModel(model);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    ui->tableView->resizeColumnsToContents();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    ui->tableView->setSortingEnabled(true);
}

void Booking::setupMapper() {
    mapper = new QDataWidgetMapper();
    mapper->setModel(model);

    mapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);
}

void Booking::setupModel(const QStringList &Headers) {
    model = new QSqlTableModel(this);
    model->setTable("Booking");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    for (int i = 0, j = 0; i < model->columnCount(); i++, j++) {
        model->setHeaderData(i, Qt::Horizontal, Headers[j]);
    }

}

void Booking::OnAddClicked() {
    mapper->submit();
    model->submitAll();
    model->select();
    model->insertRow(model->rowCount(QModelIndex()));
    mapper->toLast();
}

