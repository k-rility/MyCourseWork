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
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    mapper = new QDataWidgetMapper();
    mapper->setModel(model);
    mapper->addMapping(ui->UserLineEdit, 1);
    mapper->addMapping(ui->UserCountLineEdit, 2);
    mapper->addMapping(ui->DateLineEdit, 3);

    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
}

void booking_dialog_add::OnAcceptClicked() {
    QSqlQuery query;
    QString QueryString = QString("SELECT EXISTS (SELECT USER FROM Booking WHERE USER = '%1')").arg(
            ui->UserLineEdit->text());
    query.prepare(QueryString);
    query.exec();
    query.next();
    if (query.value(0) != 0) {
        qDebug() << query.value(0).toString();
    } else {
        mapper->submit();
        model->submitAll();
        emit AcceptClicked();
        this->close();
    }
}

