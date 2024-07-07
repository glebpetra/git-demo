#include "choose.h"

Choose::Choose(QWidget *par): QDialog(par, Qt::WindowTitleHint)
{
    black = new QPushButton("&Черный");
    green = new QPushButton("&Зеленый");
    red = new QPushButton("&Красный");
    QGridLayout* my_grid = new QGridLayout;
    my_grid->addWidget(black, 0, 0);
    my_grid->addWidget(green, 1, 0);
    my_grid->addWidget(red, 2, 0);
    setLayout(my_grid);
    connect(black, SIGNAL(clicked()), this, SLOT(slotBlack()));
    connect(green, SIGNAL(clicked()), this, SLOT(slotGreen()));
    connect(red, SIGNAL(clicked()), this, SLOT(slotRed()));
}

void Choose::slotBlack()
{

}

void Choose::slotGreen()
{

}

void Choose::slotRed()
{


}

Choose::~Choose()
{
    // delete red;
    // delete black;
    // delete green;
}

