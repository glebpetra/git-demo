#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "class.cpp"
#include <QFileDialog>
#include <QMessageBox>
#include <string>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::on_pushButton_clicked()
{
    My_set<int> set_1;
    My_set<int> set_2;
    QString filename = QFileDialog::getOpenFileName(this, "Open File", "", tr("Text Files (*.txt);;All Files (*)"));
    QFile file(filename);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!file.isOpen())
    {
        QMessageBox::critical(nullptr, "Error", "Failed to open file for reading!");
    }
    QTextStream in(&file);
    while (!in.atEnd())
    {
        in >> set_1;
    }
    file.close();

    QString str;
    set_1.show_list(str);
    ui->label_2->setText(str);

    filename = QFileDialog::getOpenFileName(this, "Open File", "", tr("Text Files (*.txt);;All Files (*)"));
    QFile file_2(filename);
    file_2.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!file_2.isOpen())
    {
        QMessageBox::critical(nullptr, "Error", "Failed to open file for reading!");
    }
    QTextStream in_2(&file_2);
    while (!in_2.atEnd())
        in_2 >> set_2;
    file_2.close();


    set_2.show_list(str);
    ui->label->setText(str);

    My_set<int> set_4 = set_1 + set_2;
    set_4.show_list(str);
    ui->label_3->setText(str);

    My_set<int> set_3 = set_1 * set_2;
    set_3.show_list(str);
    ui->label_4->setText(str);

    filename = QFileDialog::getSaveFileName(this, "Save File", "", tr("Text Files (*.txt);;All Files (*)"));
    if (!filename.isEmpty())
    {
        QFile file_3(filename);
        if (file_3.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream out(&file_3);
            out << set_4;
            file_3.close();
        }
        else
        {
            QMessageBox::information(this, "Error", "Not save");
        }
    }

    filename = QFileDialog::getSaveFileName(this, "Save File", "", tr("Text Files (*.txt);;All Files (*)"));
    if (!filename.isEmpty())
    {
        QFile file_4(filename);
        if (file_4.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream out_2(&file_4);
            out_2 << set_3;
            file_4.close();
        }
        else
        {
            QMessageBox::information(this, "Error", "Not save");
        }
    }
}

