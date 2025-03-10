#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr, std::string login="guest", std::string password="guest");
    ~MainWindow();

private slots:
    void on_createUserButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
