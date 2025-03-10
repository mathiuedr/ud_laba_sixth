/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QLineEdit *login_input;
    QLineEdit *password_input;
    QLabel *label;
    QLabel *label_2;
    QPushButton *loginButton;
    QPushButton *backButton;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName("LoginDialog");
        LoginDialog->resize(400, 300);
        login_input = new QLineEdit(LoginDialog);
        login_input->setObjectName("login_input");
        login_input->setGeometry(QRect(10, 50, 113, 26));
        password_input = new QLineEdit(LoginDialog);
        password_input->setObjectName("password_input");
        password_input->setGeometry(QRect(220, 50, 113, 26));
        label = new QLabel(LoginDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 10, 66, 18));
        label_2 = new QLabel(LoginDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(240, 10, 66, 18));
        loginButton = new QPushButton(LoginDialog);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(230, 240, 88, 26));
        backButton = new QPushButton(LoginDialog);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(70, 240, 88, 26));

        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("LoginDialog", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        label_2->setText(QCoreApplication::translate("LoginDialog", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        loginButton->setText(QCoreApplication::translate("LoginDialog", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        backButton->setText(QCoreApplication::translate("LoginDialog", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
