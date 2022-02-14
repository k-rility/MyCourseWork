#ifndef BOOKING_HPP_
#define BOOKING_HPP_

#include <QWidget>
#include <QString>
#include <QStringList>
#include <QSqlQueryModel>
#include <QTableView>

#include "booking_dialog_add.hpp"

namespace Ui {
    class Booking;
}

class Booking : public QWidget {
Q_OBJECT
public:

    explicit Booking(QWidget *parent = nullptr);

    ~Booking() noexcept;

    void createUi();

    void setupModel(const QString &, const QStringList &);

private slots:

    void OnBackClicked();

    void OnAddClicked();

private:
    Ui::Booking *ui;
    QSqlQueryModel *model;
};


#endif // BOOKING_HPP_
