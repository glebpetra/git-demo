#ifndef DATA_H
#define DATA_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>

namespace Ui {
class dat;
}

class dat : public QWidget
{
    Q_OBJECT

public:
    explicit dat(QWidget *parent = nullptr);
    ~dat();

private:
    Ui::dat *ui;
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;
};

#endif // DATA_H
