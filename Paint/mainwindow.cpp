#include "mainwindow.h"
#include "qforeach.h"
#include "qobjectdefs.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new paintScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &MainWindow::slotTimer);
    timer->start(100);

    QMenu* file = new QMenu("&Файл");
    QMenu* info = new QMenu("&Инфо");
    // file->addAction("&Выбор цвета", scene, SLOT(slotChooseColor()));
    file->addAction("&Открыть", this, SLOT(slotLoad()));
    // info->addAction("&Помощь", this, SLOT(slotInfo()));
    file->addAction("&Сохранить", this, SLOT(slotSave()));
    file->addAction("&Сохранить как", this, SLOT(slotSaveAs()));
    file->addSeparator();
    file->addAction("&Выход", qApp, SLOT(quit()));
    menuBar()->addMenu(file);
    menuBar()->addMenu(info);

    connect(this, SIGNAL(redClicked(int)), scene, SLOT(setBrush(int)));
    connect(this, SIGNAL(greenClicked(int)), scene, SLOT(setBrush(int)));
    connect(this, SIGNAL(blueClicked(int)), scene, SLOT(setBrush(int)));
    ui->red->setChecked(true);

    connect(this, SIGNAL(defClicked(int)), scene, SLOT(chooseObj(int)));
    connect(this, SIGNAL(rectClicked(int)), scene, SLOT(chooseObj(int)));
    connect(this, SIGNAL(polClicked(int)), scene, SLOT(chooseObj(int)));
    connect(this, SIGNAL(ellClicked(int)), scene, SLOT(chooseObj(int)));
    connect(this, SIGNAL(lineClicked(int)), scene, SLOT(chooseObj(int)));
    connect(this, SIGNAL(nothClicked(int)), scene, SLOT(chooseObj(int)));

    }

    void MainWindow::slotTimer()
    {
        timer->stop();
        scene->setSceneRect(0, 0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
    }

    void MainWindow::resizeEvent(QResizeEvent *event)
    {
        timer->start(100);
        QWidget::resizeEvent(event);
    }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_red_clicked(bool checked)
{
    if (checked)
        emit redClicked(0);
}


void MainWindow::on_green_clicked(bool checked)
{
    if (checked)
        emit greenClicked(1);
}


void MainWindow::on_blue_clicked(bool checked)
{
    if (checked)
        emit blueClicked(2);
}


void MainWindow::on_rect_clicked()
{
    // scene->setTypeFigure(paintScene::RombType);
    emit rectClicked(1);
}


void MainWindow::on_def_clicked()
{
    // scene->setTypeFigure(paintScene::CustomType);
    emit defClicked(0);
}


void MainWindow::on_polygon_clicked()
{
    emit polClicked(2);
}


void MainWindow::on_ellipse_clicked()
{
    emit ellClicked(3);
}


void MainWindow::on_line_clicked()
{
    emit lineClicked(4);
}

void MainWindow::on_nothing_clicked()
{
    emit nothClicked(5);
}

void MainWindow::slotSave()
{
    QString newPath = QFileDialog::getSaveFileName(this, "Save", path, "SVG file (*.svg)");
    if (newPath.isEmpty())
        return;
    path = newPath;

    QSvgGenerator generator;
    generator.setFileName(path);
    generator.setTitle(tr("SVG file"));
    generator.setDescription(tr("Svg example"));
    generator.setSize(QSize(scene->width(), scene->height()));
    generator.setViewBox(QRect(0, 0, scene->width(), scene->height()));

    QPainter painter;
    painter.begin(&generator);
    scene->render(&painter);
    painter.end();
}

void MainWindow::slotSaveAs()
{

}

void MainWindow::slotLoad()
{
    QString newPath = QFileDialog::getOpenFileName(this, "Open", path, "SVG file (*.svg)");
    if (newPath.isEmpty())
        return;
    path = newPath;
    scene->clear();
    scene->setSceneRect(SvgReader::getSize(path));
    foreach (QGraphicsItem* item, SvgReader::getElements(path))
    {
        QGraphicsItem* rect = item;
        scene->addItem(rect);
    }
}


