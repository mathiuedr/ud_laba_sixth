#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <functional>

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
    void on_searchButton_clicked();

    void on_backButton_clicked();

    void on_insertButton_clicked();

    void on_updateButton_clicked();

    void on_deleteButton_clicked();

    void on_createDbButton_clicked();

    void on_deleteDbButton_clicked();

    void on_clearDbButton_clicked();

    void on_createButton_clicked();

private:
    void showIncorrectInput();
    void showDatabaseRestriction();
    void showSuccess();
    template <typename Func, typename... Args>
    void check_return_value(Func func, Args&&... args) {
        int result = func(std::forward<Args>(args)...);
        if (result == -1) {
            this->showDatabaseRestriction();
        }else if(result == 1){
            this->showIncorrectInput();
        }else if(result ==0){
            this->showSuccess();
        }

    }
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
