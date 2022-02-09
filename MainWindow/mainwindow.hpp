#ifndef MAINWINDOW_HPP_
#define MAINWINDOW_HPP_

#include <QMainWindow>
#include <QWidget>
#include "DataBase/db_interface.hpp"
#include "AuthWindow/authwindow.hpp"
#include <QMessageBox>


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

private:
    Ui::MainWindow *ui;
    AuthWindow w_Auth;
    db_interface query;
};


#endif // MAINWINDOW_HPP_