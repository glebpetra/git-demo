#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QTableView>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

private:
    Ui::MainWindow *ui;
    void readExcel();
    void writeExcel();
    void setCol();
    void setRow();
    void set_text();
    int num_row = 1;
    int num_col = 1;
    QString text = "";
    QString filename;
};
#endif // MAINWINDOW_H
