#include "startdialog.h"
#include "./ui_startdialog.h"
#include "mainwindow.h"

StartDialog::StartDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StartDialog)
{
    ui->setupUi(this);
}

StartDialog::~StartDialog()
{
    delete ui;
}

void StartDialog::on_guestButton_clicked()
{
    MainWindow* mw = new MainWindow();
    mw->show();
    this->close();
}


void StartDialog::on_loginButton_clicked()
{
    LoginDialog* lg = new LoginDialog();
    lg->show();
    this->close();
}

