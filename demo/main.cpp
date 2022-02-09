#include <QApplication>
#include "MainWindow/mainwindow.hpp"

int main(int argc, char **argv) {
    QApplication a(argc, argv);
    MainWindow w;
    w.AuthShow();
    return a.exec();
}
