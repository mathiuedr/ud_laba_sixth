/********************************************************************************
** Form generated from reading UI file 'startdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTDIALOG_H
#define UI_STARTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_StartDialog
{
public:
    QPushButton *guestButton;
    QPushButton *loginButton;

    void setupUi(QDialog *StartDialog)
    {
        if (StartDialog->objectName().isEmpty())
            StartDialog->setObjectName("StartDialog");
        StartDialog->resize(800, 600);
        guestButton = new QPushButton(StartDialog);
        guestButton->setObjectName("guestButton");
        guestButton->setGeometry(QRect(110, 300, 141, 61));
        loginButton = new QPushButton(StartDialog);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(340, 300, 141, 51));

        retranslateUi(StartDialog);

        QMetaObject::connectSlotsByName(StartDialog);
    } // setupUi

    void retranslateUi(QDialog *StartDialog)
    {
        StartDialog->setWindowTitle(QCoreApplication::translate("StartDialog", "StartDialog", nullptr));
        guestButton->setText(QCoreApplication::translate("StartDialog", "\320\222\320\276\320\271\321\202\320\270 \320\272\320\260\320\272 \320\263\320\276\321\201\321\202\321\214", nullptr));
        loginButton->setText(QCoreApplication::translate("StartDialog", "\320\222\320\276\320\271\321\202\320\270 \320\262 \320\260\320\272\320\272\320\260\321\203\320\275\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartDialog: public Ui_StartDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTDIALOG_H
