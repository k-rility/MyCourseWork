#ifndef BOOKING_HPP_
#define BOOKING_HPP_

#include <QWidget>
#include <QString>
#include <QStringList>
#include <QSqlTableModel>
#include <QTableView>
#include <QObject>
#include <QDataWidgetMapper>
#include <QDebug>
#include <QDateTime>
#include <QSqlRecord>

#include "ComboBoxItemDelegate.hpp"
#include "DataEditDelegate.hpp"


namespace Ui {
    class Booking;
}

class Booking : public QWidget {
Q_OBJECT
public:

    explicit Booking(QWidget *parent = nullptr);

    ~Booking() noexcept;

    void createUi();

    void setupMapper();

    void setupModel(const QStringList &);

    void defaultRow(int, QSqlRecord &);

private slots:

    void OnAddClicked();

    void OnDeleteClicked();

private:
    Ui::Booking *ui;
    QSqlTableModel *model;
    QDataWidgetMapper *mapper;
};


#endif // BOOKING_HPP_
