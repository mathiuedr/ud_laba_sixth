#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include "createuserdialog.h"

#include "DatabaseManage.h"

MainWindow::MainWindow(QWidget *parent, std::string login, std::string password)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    if(connect_to_db("guest","guest")==0){
    }
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_createUserButton_clicked()
{
    CreateUserDialog* cd = new CreateUserDialog();
    cd->show();
}

