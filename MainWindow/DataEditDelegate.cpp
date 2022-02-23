#include "DataEditDelegate.hpp"

#include <QDateTimeEdit>
#include <QStyleOptionViewItem>

DataEditDelegate::DataEditDelegate(QObject *parent) : QItemDelegate(parent) {}

QWidget *DataEditDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &, const QModelIndex &) const {
    auto *date = new QDateTimeEdit(parent);

    date->setFrame(false);
    date->setMinimumDateTime(QDateTime(
            QDate(2016, 12, 01),
            QTime(23, 00)));
    date->setMaximumDateTime(QDateTime(
            QDate(2099, 12, 01),
            QTime(9, 00)
    ));
    date->setDateTime(QDateTime::currentDateTime());
    date->setCalendarPopup(true);
    date->setDisplayFormat("yyyy/MM/dd/hh:mm");

    return date;
}

void DataEditDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const {
    QDateTime value = index.model()->data(index, Qt::EditRole).toDateTime();
    auto *date = dynamic_cast<QDateTimeEdit *>(editor);
    date->setDateTime(value);
}

void
DataEditDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &) const {
    editor->setGeometry(option.rect);
}

void DataEditDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const {
    auto *date = dynamic_cast<QDateTimeEdit *>(editor);
    date->interpretText();
    model->setData(index, date->dateTime(), Qt::EditRole);
}

void DataEditDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    QStyleOptionViewItem opt = setOptions(index, option);
    opt.displayAlignment = Qt::AlignLeft | Qt::AlignCenter;
    drawDisplay(painter, opt, opt.rect, index.data(Qt::DisplayRole).toDateTime().toString("yyyy/MM/dd/hh:mm"));
}
