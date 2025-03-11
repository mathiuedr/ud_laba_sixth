/********************************************************************************
** Form generated from reading UI file 'createuserdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEUSERDIALOG_H
#define UI_CREATEUSERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CreateUserDialog
{
public:
    QLineEdit *login_input;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *password_input;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QPushButton *createButton;
    QPushButton *backButton;
    QCheckBox *search_cb;
    QCheckBox *clear_bd_cb;
    QCheckBox *delete_bd_cb;
    QCheckBox *create_bd_cb;
    QCheckBox *delete_cb;
    QCheckBox *update_cb;
    QCheckBox *insert_cb;
    QCheckBox *create_user_cb;

    void setupUi(QDialog *CreateUserDialog)
    {
        if (CreateUserDialog->objectName().isEmpty())
            CreateUserDialog->setObjectName("CreateUserDialog");
        CreateUserDialog->resize(400, 456);
        login_input = new QLineEdit(CreateUserDialog);
        login_input->setObjectName("login_input");
        login_input->setGeometry(QRect(10, 40, 113, 26));
        label = new QLabel(CreateUserDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 10, 66, 18));
        label_2 = new QLabel(CreateUserDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(170, 10, 66, 18));
        password_input = new QLineEdit(CreateUserDialog);
        password_input->setObjectName("password_input");
        password_input->setGeometry(QRect(160, 40, 113, 26));
        label_3 = new QLabel(CreateUserDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 90, 161, 18));
        label_4 = new QLabel(CreateUserDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 120, 66, 18));
        label_5 = new QLabel(CreateUserDialog);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 150, 66, 18));
        label_6 = new QLabel(CreateUserDialog);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 210, 81, 18));
        label_7 = new QLabel(CreateUserDialog);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 180, 91, 18));
        label_8 = new QLabel(CreateUserDialog);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 240, 101, 18));
        label_9 = new QLabel(CreateUserDialog);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 270, 91, 18));
        label_10 = new QLabel(CreateUserDialog);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(10, 310, 91, 18));
        label_11 = new QLabel(CreateUserDialog);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 350, 171, 18));
        createButton = new QPushButton(CreateUserDialog);
        createButton->setObjectName("createButton");
        createButton->setGeometry(QRect(280, 410, 88, 26));
        backButton = new QPushButton(CreateUserDialog);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(120, 410, 88, 26));
        search_cb = new QCheckBox(CreateUserDialog);
        search_cb->setObjectName("search_cb");
        search_cb->setGeometry(QRect(100, 120, 92, 24));
        clear_bd_cb = new QCheckBox(CreateUserDialog);
        clear_bd_cb->setObjectName("clear_bd_cb");
        clear_bd_cb->setGeometry(QRect(120, 310, 92, 24));
        delete_bd_cb = new QCheckBox(CreateUserDialog);
        delete_bd_cb->setObjectName("delete_bd_cb");
        delete_bd_cb->setGeometry(QRect(120, 270, 92, 24));
        create_bd_cb = new QCheckBox(CreateUserDialog);
        create_bd_cb->setObjectName("create_bd_cb");
        create_bd_cb->setGeometry(QRect(110, 240, 92, 24));
        delete_cb = new QCheckBox(CreateUserDialog);
        delete_cb->setObjectName("delete_cb");
        delete_cb->setGeometry(QRect(100, 210, 92, 24));
        update_cb = new QCheckBox(CreateUserDialog);
        update_cb->setObjectName("update_cb");
        update_cb->setGeometry(QRect(130, 180, 92, 24));
        insert_cb = new QCheckBox(CreateUserDialog);
        insert_cb->setObjectName("insert_cb");
        insert_cb->setGeometry(QRect(100, 150, 92, 24));
        create_user_cb = new QCheckBox(CreateUserDialog);
        create_user_cb->setObjectName("create_user_cb");
        create_user_cb->setGeometry(QRect(210, 350, 92, 24));

        retranslateUi(CreateUserDialog);

        QMetaObject::connectSlotsByName(CreateUserDialog);
    } // setupUi

    void retranslateUi(QDialog *CreateUserDialog)
    {
        CreateUserDialog->setWindowTitle(QCoreApplication::translate("CreateUserDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("CreateUserDialog", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        label_2->setText(QCoreApplication::translate("CreateUserDialog", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        label_3->setText(QCoreApplication::translate("CreateUserDialog", "\320\237\321\200\320\260\320\262\320\260 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217:", nullptr));
        label_4->setText(QCoreApplication::translate("CreateUserDialog", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        label_5->setText(QCoreApplication::translate("CreateUserDialog", "\320\222\321\201\321\202\320\260\320\262\320\272\320\260", nullptr));
        label_6->setText(QCoreApplication::translate("CreateUserDialog", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265", nullptr));
        label_7->setText(QCoreApplication::translate("CreateUserDialog", "\320\236\320\261\320\275\320\276\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
        label_8->setText(QCoreApplication::translate("CreateUserDialog", "\320\241\320\276\320\267\320\264\320\260\320\275\320\270\320\265 \320\261\320\264", nullptr));
        label_9->setText(QCoreApplication::translate("CreateUserDialog", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265 \320\261\320\264", nullptr));
        label_10->setText(QCoreApplication::translate("CreateUserDialog", "\320\236\321\207\320\270\321\201\321\202\320\272\320\260 \320\261\320\264", nullptr));
        label_11->setText(QCoreApplication::translate("CreateUserDialog", "\320\241\320\276\320\267\320\264\320\260\320\275\320\270\320\265 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        createButton->setText(QCoreApplication::translate("CreateUserDialog", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
        backButton->setText(QCoreApplication::translate("CreateUserDialog", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        search_cb->setText(QString());
        clear_bd_cb->setText(QString());
        delete_bd_cb->setText(QString());
        create_bd_cb->setText(QString());
        delete_cb->setText(QString());
        update_cb->setText(QString());
        insert_cb->setText(QString());
        create_user_cb->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CreateUserDialog: public Ui_CreateUserDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEUSERDIALOG_H
