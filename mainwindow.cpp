#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <QDebug>
#include "DatabaseManage.h"
#include <QMessageBox>
#include "startdialog.h"
#include <vector>

MainWindow::MainWindow(QWidget *parent, std::string login, std::string password)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    if(connect_to_db(login.c_str(),password.c_str())==0){
        qDebug() << "connected to db";
    }else{
        qDebug()<< "err";
        this->close();
    }
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    disconnect_from_db();
    delete ui;
}



void MainWindow::showSuccess(){
    QMessageBox::information(this,"Успех!", "");
}

void MainWindow::showIncorrectInput(){
    QMessageBox::information(this,"Ошибка ввода", "Ввод не соответствует формату");
}

void MainWindow::showDatabaseRestriction()
{
    QMessageBox::information(this,"Ошибка доступа", "Действие запрещено для данного пользователя");
}



void MainWindow::on_searchButton_clicked()
{
    char* res = search_books_by_author_name(this->ui->search_input->text().toStdString().c_str());
    if(res){
        this->ui->search_textBrowser->setText(QString::fromUtf8(res));
    }
}


void MainWindow::on_backButton_clicked()
{
    StartDialog* sd = new StartDialog();
    sd->show();
    this->close();
}

std::vector<std::string> split(std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

std::vector<const char*> cast_std_str_to_c_str(const std::vector<std::string>& initial_vector){
    std::vector<const char*> res;
    for(const std::string& str:initial_vector){
        res.push_back(str.c_str());
    }
    return res;
}

void MainWindow::on_insertButton_clicked()
{
    std::vector<const char*> splitted = cast_std_str_to_c_str(split(this->ui->insert_input->text().toStdString(), ", "));
    if(splitted.size()!=5){
        this->showIncorrectInput();
        return;
    }
    this->check_return_value(insert_book,splitted[0],splitted[1],splitted[2],splitted[3],splitted[4]);
}


void MainWindow::on_updateButton_clicked()
{
    std::vector<const char*> splitted = cast_std_str_to_c_str(split(this->ui->update_input->text().toStdString(), ", "));
    if(splitted.size()!=5){
        this->showIncorrectInput();
        return;
    }
    this->check_return_value(update_book_by_id,this->ui->update_id_input->text().toInt(), splitted[0],splitted[1],splitted[2],splitted[3],splitted[4]);
}


void MainWindow::on_deleteButton_clicked()
{
    this->check_return_value(delete_book_by_name, this->ui->delete_input->text().toStdString().c_str());
}


void MainWindow::on_createDbButton_clicked()
{
    this->check_return_value(create_db);
}


void MainWindow::on_deleteDbButton_clicked()
{
    this->check_return_value(drop_db);
}


void MainWindow::on_clearDbButton_clicked()
{
    this->check_return_value(clear_db);
}


void MainWindow::on_createButton_clicked()
{
    this->check_return_value(create_user,this->ui->login_input->text().toStdString().c_str(), this->ui->password_input->text().toStdString().c_str(),
                                         this->ui->create_bd_cb->isChecked(),this->ui->delete_bd_cb->isChecked(),this->ui->clear_bd_cb->isChecked(),
                                         this->ui->insert_cb->isChecked(),this->ui->search_cb->isChecked(),this->ui->update_cb->isChecked(),
                             this->ui->delete_cb->isChecked(),this->ui->create_user_cb->isChecked());
}

