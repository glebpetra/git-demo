/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionLoad;
    QAction *actionSave;
    QWidget *centralwidget;
    QLabel *days;
    QDateEdit *birthday_date;
    QDateEdit *current_date;
    QLabel *result_label;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menubar;
    QMenu *menuInfo;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        actionAbout->setCheckable(true);
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName("actionLoad");
        actionLoad->setCheckable(true);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        actionSave->setCheckable(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        days = new QLabel(centralwidget);
        days->setObjectName("days");
        days->setGeometry(QRect(20, 150, 431, 20));
        birthday_date = new QDateEdit(centralwidget);
        birthday_date->setObjectName("birthday_date");
        birthday_date->setGeometry(QRect(160, 50, 110, 29));
        current_date = new QDateEdit(centralwidget);
        current_date->setObjectName("current_date");
        current_date->setGeometry(QRect(160, 90, 111, 29));
        result_label = new QLabel(centralwidget);
        result_label->setObjectName("result_label");
        result_label->setGeometry(QRect(320, 50, 311, 91));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 50, 131, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 90, 131, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuInfo = new QMenu(menubar);
        menuInfo->setObjectName("menuInfo");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuInfo->menuAction());
        menuInfo->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionLoad->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        days->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        result_label->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\203\321\211\320\260\321\217 \320\264\320\260\321\202\320\260", nullptr));
        menuInfo->setTitle(QCoreApplication::translate("MainWindow", "Info", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
