#ifndef MAINWINDOW_INTERFACE_HPP_
#define MAINWINDOW_INTERFACE_HPP_

#include <QWidget>


namespace Ui {
    class mainwindow_interface;
}

class mainwindow_interface : public QWidget {
Q_OBJECT

public:
    explicit mainwindow_interface(QWidget *parent = nullptr);

    virtual ~mainwindow_interface();

signals:

    void ButtonClicked();

private slots:

    void OnButtonClicked();

private:
    Ui::mainwindow_interface *ui;
};


#endif // MAINWINDOW_INTERFACE_HPP_
