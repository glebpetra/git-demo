#include "data.h"
#include "ui_data.h"
#include <QDebug>

dat::dat(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::dat)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./results.db");
    if (db.open())
        qDebug("open");
    else
        qDebug("not open");
    query = new QSqlQuery(db);
    query->exec("CREATE TABLE Результаты(Имя TEXT, Время INT);");
    model = new QSqlTableModel(this, db);
    model->setTable("Результаты");
    model->select();
    model->insertRow(model->rowCount());
    ui->tableView->setModel(model);
}

dat::~dat()
{
    delete ui;
}
