#ifndef ANOTHER_WINDOW_H
#define ANOTHER_WINDOW_H

#include <QWidget>

namespace Ui {
class another_window;
}

class another_window : public QWidget
{
    Q_OBJECT

public:
    explicit another_window(QWidget *parent = nullptr);
    ~another_window();
    void move_pic();
    void mousePressEvent(QMouseEvent* click) override;
    int time;
    int get_time();

signals:
    void firstWindow();

private slots:
    void on_return_to_menu_clicked();
    void result_slot();

private:
    Ui::another_window *ui;
    int number_of_clicks;
    QTimer *timer;
    int x;
    int y;
    int sdvig_x;
    int sdvig_y;
    QTimer *result;
    QCursor cursor;
};

#endif // ANOTHER_WINDOW_H

