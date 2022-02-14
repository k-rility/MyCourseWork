#ifndef BOOKING_DIALOG_ADD_HPP_
#define BOOKING_DIALOG_ADD_HPP_

#include <QDialog>
#include <QDataWidgetMapper>
#include <QSqlTableModel>

namespace Ui { class booking_dialog_add; }

class booking_dialog_add : public QDialog {
Q_OBJECT

public:
    explicit booking_dialog_add(QWidget *parent = nullptr);

    ~booking_dialog_add() noexcept;

    void setupModel();

signals:
void AcceptClicked();
private slots:

    void OnAcceptClicked();

private:
    Ui::booking_dialog_add *ui;
    QDataWidgetMapper *mapper;
    QSqlTableModel *model;
};

#endif // BOOKING_DIALOG_ADD_HPP_
