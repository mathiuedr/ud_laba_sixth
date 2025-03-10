#include "createuserdialog.h"
#include "ui_createuserdialog.h"

CreateUserDialog::CreateUserDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreateUserDialog)
{
    ui->setupUi(this);
}

CreateUserDialog::~CreateUserDialog()
{
    delete ui;
}

void CreateUserDialog::on_backButton_clicked()
{
    this->close();
}

