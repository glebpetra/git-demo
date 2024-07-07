#ifndef SAVE_RES_WINDOW_H
#define SAVE_RES_WINDOW_H

#include <QWidget>

namespace Ui {
class save_res_window;
}

class save_res_window : public QWidget
{
    Q_OBJECT

public:
    explicit save_res_window(QWidget *parent = nullptr);
    ~save_res_window();
    Ui::save_res_window *ui;

private slots:
    void on_save_but_clicked();

private:
         // Ui::save_res_window *ui;
};

#endif // SAVE_RES_WINDOW_H
