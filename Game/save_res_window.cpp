#include "save_res_window.h"
#include "ui_save_res_window.h"
#include <QString>
#include <QWidget>
#include "data.h"

save_res_window::save_res_window(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::save_res_window)
{
    ui->setupUi(this);
}

save_res_window::~save_res_window()
{
    delete ui;
}

void save_res_window::on_save_but_clicked()
{
    dat *database = new dat;
    database->show();
}
