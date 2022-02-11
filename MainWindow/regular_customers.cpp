#include "regular_customers.hpp"
#include "ui_regular_customers.h"


RegularCustomers::RegularCustomers(QWidget *parent) : QWidget(parent), ui(new Ui::RegularCustomers) {
    ui->setupUi(this);
}

RegularCustomers::~RegularCustomers() {
    delete ui;
}
