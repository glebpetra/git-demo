#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QTimer>
#include <QResizeEvent>
#include "paintscene.h"
#include <QSvgGenerator>
#include "svgreader.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow* ui;
    QTimer* timer;
    paintScene* scene;
    void resizeEvent(QResizeEvent* event);
    QString path;

private slots:
    void slotTimer();
    void on_red_clicked(bool checked);
    void on_green_clicked(bool checked);
    void on_blue_clicked(bool checked);

    void on_rect_clicked();
    void on_def_clicked();
    void on_polygon_clicked();
    void on_ellipse_clicked();
    void on_line_clicked();
    void on_nothing_clicked();

public slots:
    void slotSave();
    void slotSaveAs();
    void slotLoad();

signals:
    void redClicked(int index);
    void greenClicked(int index);
    void blueClicked(int index);

    void rectClicked(int index);
    void defClicked(int index);
    void polClicked(int index);
    void ellClicked(int index);
    void lineClicked(int index);
    void nothClicked(int index);
};
#endif // MAINWINDOW_H
