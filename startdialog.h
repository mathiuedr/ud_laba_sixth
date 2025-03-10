#ifndef STARTDIALOG_H
#define STARTDIALOG_H

#include <QDialog>
#include "logindialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class StartDialog;
}
QT_END_NAMESPACE

class StartDialog : public QDialog
{
    Q_OBJECT

public:
    StartDialog(QWidget *parent = nullptr);
    ~StartDialog();

private slots:
    void on_guestButton_clicked();

    void on_loginButton_clicked();

private:
    Ui::StartDialog *ui;
};
#endif // STARTDIALOG_H
