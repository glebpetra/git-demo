/********************************************************************************
** Form generated from reading UI file 'save_res_window.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVE_RES_WINDOW_H
#define UI_SAVE_RES_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_save_res_window
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *your_res;
    QLabel *res;
    QLabel *enter_name;
    QLineEdit *name;
    QPushButton *save_but;
    QPushButton *no_but;

    void setupUi(QWidget *save_res_window)
    {
        if (save_res_window->objectName().isEmpty())
            save_res_window->setObjectName("save_res_window");
        save_res_window->resize(400, 300);
        verticalLayout = new QVBoxLayout(save_res_window);
        verticalLayout->setObjectName("verticalLayout");
        your_res = new QLabel(save_res_window);
        your_res->setObjectName("your_res");

        verticalLayout->addWidget(your_res);

        res = new QLabel(save_res_window);
        res->setObjectName("res");

        verticalLayout->addWidget(res);

        enter_name = new QLabel(save_res_window);
        enter_name->setObjectName("enter_name");

        verticalLayout->addWidget(enter_name);

        name = new QLineEdit(save_res_window);
        name->setObjectName("name");

        verticalLayout->addWidget(name);

        save_but = new QPushButton(save_res_window);
        save_but->setObjectName("save_but");

        verticalLayout->addWidget(save_but);

        no_but = new QPushButton(save_res_window);
        no_but->setObjectName("no_but");

        verticalLayout->addWidget(no_but);


        retranslateUi(save_res_window);

        QMetaObject::connectSlotsByName(save_res_window);
    } // setupUi

    void retranslateUi(QWidget *save_res_window)
    {
        save_res_window->setWindowTitle(QCoreApplication::translate("save_res_window", "Form", nullptr));
        your_res->setText(QCoreApplication::translate("save_res_window", "\320\222\320\260\321\210 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202:", nullptr));
        res->setText(QCoreApplication::translate("save_res_window", "0", nullptr));
        enter_name->setText(QCoreApplication::translate("save_res_window", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\262\320\260\321\210\320\265 \320\270\320\274\321\217:", nullptr));
        save_but->setText(QCoreApplication::translate("save_res_window", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        no_but->setText(QCoreApplication::translate("save_res_window", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class save_res_window: public Ui_save_res_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVE_RES_WINDOW_H
