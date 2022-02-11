#ifndef MAINWINDOW_HPP_
#define MAINWINDOW_HPP_

#include <QMainWindow>
#include <QWidget>
#include <QMessageBox>
#include <QTableView>

#include "DataBase/db_interface.hpp"

#include "AuthWindow/authwindow.hpp"
#include "MainWindow/regular_customers.hpp"


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() noexcept;

    void AuthShow();

    void ConnectButton();

    void SignIn();

//    void RegCustShow();

//signals:
//
//    void RegularCustomersClicked();

private slots:

    void OnRegularCustomersClicked();

private:
    Ui::MainWindow *ui;
    AuthWindow w_Auth;
    RegularCustomers ui_RegularCustomers;
    db_interface query;
};


#endif // MAINWINDOW_HPP_
