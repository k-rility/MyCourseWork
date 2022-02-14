#ifndef BOOKING_DIALOG_ADD_HPP_
#define BOOKING_DIALOG_ADD_HPP_

#include <QDialog>


namespace Ui { class booking_dialog_add; }

class booking_dialog_add : public QDialog {
Q_OBJECT

public:
    explicit booking_dialog_add(QWidget *parent = nullptr);

    ~booking_dialog_add() noexcept;


private:
    Ui::booking_dialog_add *ui;
};

#endif // BOOKING_DIALOG_ADD_HPP_
