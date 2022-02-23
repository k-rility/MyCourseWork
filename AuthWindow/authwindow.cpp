
#include "authwindow.hpp"
#include "ui_authwindow.h"


AuthWindow::AuthWindow(QWidget *parent) : QWidget(parent), ui(new Ui::AuthWindow) {
    ui->setupUi(this);
}

AuthWindow::~AuthWindow() {
    delete ui;
}

QString AuthWindow::OnLoginLineEdit() {
    return ui->LoginLineEdit->text();
}

QString AuthWindow::OnPasswordLineEdit() {
    return ui->PasswordLineEdit->text();
}

void AuthWindow::OnSignInClicked() {
    DataBaseInterface *db = new DataBaseInterface(this);
    if (!db->ConnectToDataBase("/home/kirill/Рабочий стол/CourseDB")) {
        qDebug() << "Could not connecting to DataBase";
    }
    if (!db->SignInQuery(OnPasswordLineEdit(), OnLoginLineEdit())) {
        QMessageBox::warning(this, "Authorize", "Wrong login or password");
    } else {
        MainWindow *mainWindow = new MainWindow;
        mainWindow->setWindowTitle("Main Window");
        mainWindow->setAttribute(Qt::WA_DeleteOnClose);
        mainWindow->show();
        this->close();
    }
}
