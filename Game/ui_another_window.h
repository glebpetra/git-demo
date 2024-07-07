/********************************************************************************
** Form generated from reading UI file 'another_window.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANOTHER_WINDOW_H
#define UI_ANOTHER_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_another_window
{
public:
    QPushButton *return_to_menu;
    QLabel *label;

    void setupUi(QWidget *another_window)
    {
        if (another_window->objectName().isEmpty())
            another_window->setObjectName("another_window");
        another_window->resize(1282, 743);
        return_to_menu = new QPushButton(another_window);
        return_to_menu->setObjectName("return_to_menu");
        return_to_menu->setGeometry(QRect(1072, 30, 141, 29));
        label = new QLabel(another_window);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 50, 72));

        retranslateUi(another_window);

        QMetaObject::connectSlotsByName(another_window);
    } // setupUi

    void retranslateUi(QWidget *another_window)
    {
        another_window->setWindowTitle(QCoreApplication::translate("another_window", "Form", nullptr));
        return_to_menu->setText(QCoreApplication::translate("another_window", "\320\222 \320\263\320\273\320\260\320\262\320\275\320\276\320\265 \320\274\320\265\320\275\321\216", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class another_window: public Ui_another_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANOTHER_WINDOW_H
