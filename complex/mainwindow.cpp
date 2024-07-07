#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "complexnumber.h"
#include <QDebug>
#include <QFile>
#include <QPainter>
#include <QString>
#include <QChar>
#include <QFileDialog>
#include <QPainterPath>

static ComplexNumber root_1;
static ComplexNumber root_2;

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

void MainWindow::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open File", "", tr("Text Files (*.txt);;All Files (*)"));
    QFile file(filename);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!file.isOpen())
    {
        qDebug("Error: file is not open");
    }
    QTextStream in(&file);
    QString line = in.readAll();
    file.close();

    int a(0), b(0), c(0);
    char sign1, sign2;
    sscanf(line.toStdString().c_str(), "%dx^2 %c %dx %c %d", &a, &sign1, &b, &sign2, &c);

    if (sign1 == '-')
    {
        b = -b;
    }
    if (sign2 == '-')
    {
        c = -c;
    }

    if (a == 0)
        a = 1;
    if (b == 0)
        b = 1;

    qDebug() << "Coefficients: a = " << a << ", b = " << b << ", c = " << c;

    double D = b*b - 4*a*c;
    if (D > 0)
    {
        root_1.setReal((-b + sqrt(D)) / (2 * a));
        root_2.setReal((-b - sqrt(D)) / (2 * a));
    }
    else if (D == 0)
    {
        root_1.setReal(-b / (2 * a));
    }
    else if (D < 0)
    {
        double dAbs = abs(D);
        double denominator = 2 * a;

        root_1.setImaginary(-sqrt(dAbs) / denominator);
        root_1.setReal( -b / denominator);
        root_2.setImaginary(sqrt(dAbs) / denominator);
        root_2.setReal( -b / denominator);
    }

    qDebug() << root_1.toString() << "  " << root_2.toString();

}





void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.translate(width()/2, height()/2);
    painter.drawLine(-width()/2, 0, width()/2, 0);
    painter.drawLine(0, -height()/2, 0, height());
    painter.drawText(width()/2 - 30, -10, "Re z");
    painter.drawText(-width()/2 + 30, -10, "Re z");
    painter.drawText(-30, -height()/2 + 30, "Im z");
    painter.drawText(-30, height()/2 - 30, "Im z");

    QPainterPath path;
    path.moveTo(0, -height()/2);
    path.lineTo(-4, -height()/2 + 15);
    path.lineTo(4, -height()/2 + 15);
    path.lineTo(0, -height()/2);
    painter.fillPath(path, QBrush(QColor("black")));

    path.moveTo(width()/2, 0);
    path.lineTo(width()/2 - 15, -4);
    path.lineTo(width()/2 - 15, 4);
    path.lineTo(width()/2, 0);
    painter.fillPath(path, QBrush(QColor("black")));

    painter.save();
    double im = height()/20;
    double re = width()/20;
    QPen pen(Qt::black);
    pen.setWidth(2);
    painter.setPen(pen);

    double oy = 10;
    if (root_2.getImaginary() != 0)
    {
        while (!((oy / root_2.getImaginary() <= 10.0) && (oy / root_2.getImaginary() >= 1.0)))
        {
            if (oy > root_2.getImaginary())
                oy /= 10;
            else
                oy *= 10;
        }
    }

    double ox = oy;
    // if (root_2.getReal() != 0)
    // {
    //     while (!((ox / abs(root_2.getReal()) <= 10.0) && (ox / abs(root_2.getReal()) >= 1.0)))
    //     {
    //         if (ox > root_2.getReal())
    //             ox /= 10;
    //         else
    //             ox *= 10;
    //     }
    // }

    double yvv;
    double yvn;
    double xvp;
    double xvl;
    for (int i = 1; i < 10; i++)
    {
        yvv = i*(oy/10);
        yvn = -i*(oy/10);
        painter.drawLine(-5, -im*i, 5, -im*i);
        painter.drawText(10, -im*i+5, QString::number(yvv)+"i");
        painter.drawLine(-5, im*i, 5, im*i);
        painter.drawText(10, im*i+5, QString::number(yvn)+"i");

        xvp = i*(ox/10);
        xvl = -i*(ox/10);
        painter.drawLine(re*i, 5, re*i, -5);
        painter.drawText(re*i-3, 18, QString::number(xvp));
        painter.drawLine(-re*i, 5, -re*i,-5);
        painter.drawText(-re*i-7, 18, QString::number(xvl));
    }
    painter.restore();

    painter.save();
    QPoint point_1;
    QPoint point_2;
    point_1.setX(static_cast<int>(width()/2 / ox * root_1.getReal()));
    point_1.setY(static_cast<int>(-height()/2 / oy * root_1.getImaginary()));
    pen.setColor(Qt::blue);
    pen.setWidth(5);
    painter.setPen(pen);
    painter.drawPoint(point_1);
    point_2.setX(static_cast<int>(width()/2 / ox * root_2.getReal()));
    point_2.setY(static_cast<int>(-height()/2 / oy * root_2.getImaginary()));
    painter.drawPoint(point_2);
    painter.restore();

    painter.save();
    painter.drawLine(0, 0, point_1.x(), point_1.y());
    painter.drawLine(0, 0, point_2.x(), point_2.y());
    ui->label->setText("z_1:"+root_1.toString());
    ui->label_2->setText("z_2:"+root_2.toString());

    double argum_1(0);
    if (root_1.getImaginary() != 0 && root_1.getReal() != 0)
    {
        if (root_1.getReal() == 0 && root_1.getImaginary() > 0)
        {
            argum_1 = 90;
        }
        else if (root_1.getReal() == 0 && root_1.getImaginary() < 0)
        {
            argum_1 = 270;
        }
        else if (root_1.getReal() > 0)
        {
            argum_1 = atan(root_1.getImaginary() / root_1.getReal())*180/3.14;
        }
        else if (root_1.getReal() < 0 && root_1.getImaginary() > 0)
        {
            argum_1 = 180 + atan(root_1.getImaginary() / root_1.getReal())*180/3.14;
        }
        else if (root_1.getReal() < 0 && root_1.getImaginary() < 0)
        {
            argum_1 = -180 + atan(root_1.getImaginary() / root_1.getReal())*180/3.14;
        }
        painter.drawArc(-50, -50, 100, 100, 0, (360 + argum_1)*16);
        painter.drawText(45, -45, QString::number(static_cast<int>(360 + argum_1))+"°");
    }

    double argum_2(0);
    if (root_2.getImaginary() != 0 && root_2.getReal() != 0)
    {
        if (root_2.getReal() == 0 && root_2.getImaginary() > 0)
        {
            argum_2 = 90;
        }
        else if (root_2.getReal() == 0 && root_2.getImaginary() < 0)
        {
            argum_2 = 270;
        }
        else if (root_2.getReal() > 0)
        {
            argum_2 = atan(root_2.getImaginary() / root_2.getReal())*180/3.14;
        }
        else if (root_2.getReal() < 0 && root_2.getImaginary() > 0)
        {
            argum_2 = 180 + atan(root_2.getImaginary() / root_2.getReal())*180/3.14;
        }
        else if (root_2.getReal() < 0 && root_2.getImaginary() < 0)
        {
            argum_2 = -180 + atan(root_2.getImaginary() / root_2.getReal())*180/3.14;
        }
        painter.drawArc(-25, -25, 50, 50, 0, argum_2*16);
        painter.drawText(20, -20, QString::number(static_cast<int>(argum_2))+"°");
    }
    painter.restore();

    painter.end();
    update();
}

