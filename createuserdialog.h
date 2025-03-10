#ifndef CREATEUSERDIALOG_H
#define CREATEUSERDIALOG_H

#include <QDialog>

namespace Ui {
class CreateUserDialog;
}

class CreateUserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateUserDialog(QWidget *parent = nullptr);
    ~CreateUserDialog();

private slots:
    void on_backButton_clicked();

private:
    Ui::CreateUserDialog *ui;
};

#endif // CREATEUSERDIALOG_H
