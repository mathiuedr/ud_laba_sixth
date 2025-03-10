#include "logindialog.h"
#include "ui_logindialog.h"
#include "mainwindow.h"
#include "startdialog.h"

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_loginButton_clicked()
{
    MainWindow* mw = new MainWindow(nullptr, this->ui->login_input->text().toStdString(),this->ui->password_input->text().toStdString());
    mw->show();
    this->close();
}


void LoginDialog::on_backButton_clicked()
{
    StartDialog* sd = new StartDialog();
    sd->show();
    this->close();
}

