#include "window_base.hpp"

window_base::window_base(QWidget *parent) : QWidget(parent) {}

window_base::~window_base() noexcept {}

void window_base::setupModel(const QString &Query, const QStringList &Headers) {
    model = new QSqlQueryModel;
    model->setQuery(Query);
    for (int i = 0, j = 0; i < model->columnCount(); i++, j++) {
        model->setHeaderData(i, Qt::Horizontal, Headers[j]);
    }
}

QSqlQueryModel* window_base::getModel()const {
    return model;
}