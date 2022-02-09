
#ifndef AUTHWINDOW_HPP_
#define AUTHWINDOW_HPP_

#include <QWidget>
#include <QMessageBox>


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

signals:

    void SignInClicked();

private slots:

    void OnSignInClicked();

private:

    Ui::AuthWindow *ui;
};


#endif // AUTHWINDOW_HPP_
