/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLineEdit *search_input;
    QLabel *label;
    QPushButton *searchButton;
    QTextBrowser *search_textBrowser;
    QWidget *tab_2;
    QLabel *label_2;
    QLineEdit *insert_input;
    QPushButton *insertButton;
    QWidget *tab_3;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *updateButton;
    QWidget *tab_4;
    QLabel *label_6;
    QLineEdit *delete_input;
    QPushButton *deleteButton;
    QWidget *tab_5;
    QPushButton *createDbButton;
    QPushButton *deleteDbButton;
    QPushButton *clearDbButton;
    QPushButton *createUserButton;
    QPushButton *backButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(-4, -1, 811, 491));
        tab = new QWidget();
        tab->setObjectName("tab");
        search_input = new QLineEdit(tab);
        search_input->setObjectName("search_input");
        search_input->setGeometry(QRect(10, 50, 231, 26));
        label = new QLabel(tab);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 171, 18));
        searchButton = new QPushButton(tab);
        searchButton->setObjectName("searchButton");
        searchButton->setGeometry(QRect(270, 50, 88, 26));
        search_textBrowser = new QTextBrowser(tab);
        search_textBrowser->setObjectName("search_textBrowser");
        search_textBrowser->setGeometry(QRect(10, 100, 761, 351));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        label_2 = new QLabel(tab_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 10, 571, 18));
        insert_input = new QLineEdit(tab_2);
        insert_input->setObjectName("insert_input");
        insert_input->setGeometry(QRect(20, 40, 621, 26));
        insertButton = new QPushButton(tab_2);
        insertButton->setObjectName("insertButton");
        insertButton->setGeometry(QRect(270, 100, 191, 26));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        label_3 = new QLabel(tab_3);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 10, 161, 18));
        label_4 = new QLabel(tab_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 50, 66, 18));
        label_5 = new QLabel(tab_3);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(240, 50, 511, 18));
        lineEdit = new QLineEdit(tab_3);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(20, 90, 61, 26));
        lineEdit_2 = new QLineEdit(tab_3);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(160, 90, 611, 26));
        updateButton = new QPushButton(tab_3);
        updateButton->setObjectName("updateButton");
        updateButton->setGeometry(QRect(77, 130, 631, 26));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        label_6 = new QLabel(tab_4);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 20, 211, 21));
        delete_input = new QLineEdit(tab_4);
        delete_input->setObjectName("delete_input");
        delete_input->setGeometry(QRect(20, 60, 391, 26));
        deleteButton = new QPushButton(tab_4);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(20, 120, 391, 26));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        createDbButton = new QPushButton(tab_5);
        createDbButton->setObjectName("createDbButton");
        createDbButton->setGeometry(QRect(40, 40, 131, 26));
        deleteDbButton = new QPushButton(tab_5);
        deleteDbButton->setObjectName("deleteDbButton");
        deleteDbButton->setGeometry(QRect(220, 40, 141, 26));
        clearDbButton = new QPushButton(tab_5);
        clearDbButton->setObjectName("clearDbButton");
        clearDbButton->setGeometry(QRect(40, 90, 131, 26));
        createUserButton = new QPushButton(tab_5);
        createUserButton->setObjectName("createUserButton");
        createUserButton->setGeometry(QRect(240, 90, 171, 26));
        tabWidget->addTab(tab_5, QString());
        backButton = new QPushButton(centralwidget);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(37, 495, 701, 51));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272 \320\277\320\276 \320\270\320\274\320\265\320\275\320\270 \320\260\320\262\321\202\320\276\321\200\320\260", nullptr));
        searchButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\222\321\201\321\202\320\260\320\262\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214 (\320\244\320\276\321\200\320\274\320\260\321\202:  isbn, name, description, date(yyyy-mm-dd), author_name)</p></body></html>", nullptr));
        insertButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\201\321\202\320\260\320\262\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\320\222\321\201\321\202\320\260\320\262\320\272\320\260", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214 \320\277\320\276 id", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "id", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\321\214 (\320\244\320\276\321\200\320\274\320\260\321\202: isbn, name, description, date(yyyy-mm-dd), author_name)", nullptr));
        updateButton->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214 \320\277\320\276 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\321\216", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265", nullptr));
        createDbButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \321\202\320\260\320\261\320\273\320\270\321\206\321\203", nullptr));
        deleteDbButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\202\320\260\320\261\320\273\320\270\321\206\321\203", nullptr));
        clearDbButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \321\202\320\260\320\261\320\273\320\270\321\206\321\203", nullptr));
        createUserButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainWindow", "\320\222\320\276\320\267\320\274\320\276\320\266\320\275\320\276\321\201\321\202\320\270 \320\260\320\264\320\274\320\270\320\275\320\270\321\201\321\202\321\200\320\260\321\202\320\276\321\200\320\260", nullptr));
        backButton->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
