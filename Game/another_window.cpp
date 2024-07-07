#include "another_window.h"
#include "ui_another_window.h"
#include <QCursor>
#include <QPixmap>
#include <QTimer>
#include <QMouseEvent>
#include <QLabel>
#include <QPoint>
#include <QPropertyAnimation>
#include <QObject>
#include "save_res_window.h"
#include "ui_save_res_window.h"
#include <QtMultimedia/QMediaPlayer>
#include <QUrl>
#include <QMediaPlayer>
#include <QRandomGenerator>
#include <QGraphicsScene>


another_window::another_window(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::another_window)
{
    ui->setupUi(this);
    cursor = QCursor(QPixmap("./image/bita_red.png"));
    this->setCursor(cursor);
    QPixmap pixmap = QPixmap("./image/Zubovich_red.png");
    ui->label->setPixmap(pixmap);
    ui->label->setMouseTracking(true);
    x = rand()%(this->width() - ui->label->width());
    y = rand()%(this->height() - ui->label->height());
    ui->label->move(x, y);

    number_of_clicks = 0;
    timer = new QTimer(this);
    timer->setInterval(500);
    connect (timer, &QTimer::timeout, this, &another_window::move_pic);
    timer->start();
    // sdvig_x = 1;
    // sdvig_y = 1;

    time = 0;
    result = new QTimer(this);
    connect(result, SIGNAL(timeout()), this, SLOT(result_slot()));
    result->start(1000);

    QMediaPlayer *player = new QMediaPlayer;
    player->setSource(QUrl("qrc:/music/Game.mp3"));
    player->play();

}

another_window::~another_window()
{
    delete ui;
}


void another_window::on_return_to_menu_clicked()
{
    this->close();
    emit firstWindow();
}


void another_window::result_slot()
{
    time++;
}


void another_window::move_pic()
{
    if (number_of_clicks <= 2)
    {
        // QPoint point = ui->label->QLabel::mapFromGlobal(QCursor::pos());
        // QPoint point = cursor.QCursor::pos();
        x = rand()%(this->width() - ui->label->width());
        y = rand()%(this->height() - ui->label->height());
        ui->label->move(x, y);

        // x = point.x();
        // y = point.y();
        // ui->label->move(x, y);
        // x = ui->label->x() + sdvig_x;
        // y = ui->label->y() + sdvig_y;
        // if (x > this->width() - ui->label->width())
        // {
        //     sdvig_x = -sdvig_x;
        //     x = ui->label->x() + 2 * sdvig_x;
        // }
        // else if (x < 0)
        // {
        //     sdvig_x = -sdvig_x;
        //     x = ui->label->x() + 2 * sdvig_x;
        // }

        // if (y > this->height() - ui->label->height())
        // {
        //     sdvig_y = -sdvig_y;
        //     y = ui->label->y() + 2 * sdvig_y;
        // }
        // else if (y < 0)
        // {
        //     sdvig_y = -sdvig_y;
        //     y = ui->label->y() + 2 * sdvig_y;
        // }

        // ui->label->move(x, y);
    }

    else
        return;
}


void another_window::mousePressEvent(QMouseEvent *click)
{
    if (click->button() == Qt::LeftButton)
    {
        if ((ui->label->x() <= click->x()) && (click->x() <= ui->label->x() + ui->label->width())
            && (ui->label->y() <= click->y()) && (click->y() <= ui->label->y() + ui->label->height()))
        {
            number_of_clicks++;
        }
    }

    if (number_of_clicks == 3)
    {
        result->stop();
        QLabel *kataf = new QLabel(this);
        QPixmap pixmap_2 = QPixmap("./image/kat_red.png");
        kataf->setPixmap(pixmap_2);
        kataf->setFixedHeight(75);
        kataf->setFixedWidth(250);
        kataf->setGeometry(this->width() - kataf->width(), ui->label->y() - kataf->height(), this->width(), ui->label->y());
        kataf->show();

        QPropertyAnimation *avto = new QPropertyAnimation(kataf, "pos");
        avto->setDuration(5000);
        avto->setStartValue(QPoint(this->width(), ui->label->y()));
        avto->setEndValue(QPoint(-kataf->width(), ui->label->y()));

        avto->start();
        if (kataf->x() <= ui->label->x())
            ui->label->hide();
        number_of_clicks++;

        save_res_window *res_window;
        res_window = new save_res_window;
        connect(avto, &QPropertyAnimation::finished, this, [this]() {
            close();});
        res_window->ui->res->setText(QString::number(time));
        res_window->show();
    }
}

int another_window::get_time()
{
    return time;
}
