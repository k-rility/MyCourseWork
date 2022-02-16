
#ifndef AUTHWINDOW_HPP_
#define AUTHWINDOW_HPP_

#include <QWidget>
#include <QMessageBox>

#include "DataBase/db_interface.hpp"
#include "MainWindow/mainwindow.hpp"


namespace Ui {
    class AuthWindow;
}

class AuthWindow : public QWidget {
Q_OBJECT

public:
    explicit AuthWindow(QWidget *parent = nullptr);

    ~AuthWindow();

    QString OnLoginLineEdit();

    QString OnPasswordLineEdit();

private slots:

    void OnSignInClicked();

private:

    Ui::AuthWindow *ui;
};


#endif // AUTHWINDOW_HPP_
