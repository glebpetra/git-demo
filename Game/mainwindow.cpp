#include "mainwindow.h"
#include "ui_mainwindow.h"
// #include <QMediaPlayer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    secWindow = new another_window;
    connect(secWindow, &another_window::firstWindow, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_new_game_clicked()
{
    secWindow->show();
    this->close();
}
