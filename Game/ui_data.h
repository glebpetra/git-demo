/********************************************************************************
** Form generated from reading UI file 'data.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATA_H
#define UI_DATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dat
{
public:
    QTableView *tableView;

    void setupUi(QWidget *dat)
    {
        if (dat->objectName().isEmpty())
            dat->setObjectName("dat");
        dat->resize(400, 300);
        tableView = new QTableView(dat);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(50, 30, 291, 221));

        retranslateUi(dat);

        QMetaObject::connectSlotsByName(dat);
    } // setupUi

    void retranslateUi(QWidget *dat)
    {
        dat->setWindowTitle(QCoreApplication::translate("dat", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dat: public Ui_dat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATA_H
