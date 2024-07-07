#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAxObject>
#include <QtGui>
#include <QDebug>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect (ui->pushButton, &QPushButton::clicked, this, &MainWindow::readExcel);
    connect (ui->row, &QLineEdit::textEdited, this, &MainWindow::setRow);
    connect (ui->column, &QLineEdit::textEdited, this, &MainWindow::setCol);
    connect (ui->text, &QLineEdit::textEdited, this, &MainWindow::set_text);
    connect (ui->add, &QPushButton::clicked, this, &MainWindow::writeExcel);
}


void MainWindow::readExcel()
{
    filename = QFileDialog::getOpenFileName(this, "Open File", "", tr("Table Files (*.xlsx);;All Files (*)"));
    QAxObject* excel = new QAxObject("Excel.Application", this);
    QAxObject* workbooks = excel->querySubObject("Workbooks");
    QAxObject* workbook = workbooks->querySubObject("Open(const QString&)", filename);
    excel->dynamicCall("setVisible(bool)", false);

    QAxObject* sheet = workbook->querySubObject("Worksheets(int)", 1);
    int countSheets = sheet->property("Count").toInt();
    qDebug() << countSheets << Qt::endl;

    QAxObject* usedRange = sheet->querySubObject("UsedRange");
    QAxObject* rows = usedRange->querySubObject("Rows");
    int countRows = rows->property("Count").toInt();
    QAxObject* columns = usedRange->querySubObject("Columns");
    int countCols = columns->property("Count").toInt();
    int columnStart = usedRange->property("Count").toInt();
    int rowStart = usedRange->property("Count").toInt();
    qDebug() << countCols << Qt::endl;
    qDebug() << countRows << Qt::endl;

    ui->tableWidget->setRowCount(rowStart + countRows);
    ui->tableWidget->setColumnCount(columnStart + countCols);
    for ( int row = 0; row < countRows; row++ )
    {
        for ( int column = 0; column < countCols; column++ )
        {
            QAxObject* cell = sheet->querySubObject("Cells(int,int)", column+1, row+1);
            QVariant value = cell->dynamicCall("Value()");
            QTableWidgetItem* item = new QTableWidgetItem(value.toString());
            ui->tableWidget->setItem(column, row, item);
        }
    }

    delete columns;
    delete rows;
    delete usedRange;
    delete sheet;
    workbook->dynamicCall("Save()");
    workbook->dynamicCall("Close");
    delete workbook;
    delete workbooks;
    excel->dynamicCall("Quit()");
    delete excel;
}


void MainWindow::setCol()
{
    num_col = ui->column->text().toInt();
}


void MainWindow::setRow()
{
    num_row = ui->row->text().toInt();
}


void MainWindow::set_text()
{
    text = ui->text->text();
}


void MainWindow::writeExcel()
{
    QAxObject* excel = new QAxObject("Excel.Application", this);
    QAxObject* workbooks = excel->querySubObject("Workbooks");
    QAxObject* workbook = workbooks->querySubObject("Open(const QString&)", filename);
    excel->dynamicCall("setVisible(bool)", false);
    QAxObject* sheets = workbook->querySubObject("Worksheets");
    QAxObject* sheet = sheets->querySubObject("Item(int)", 1);

    QAxObject* cell = sheet->querySubObject("Cells(int, int)", num_row, num_col);
    cell->dynamicCall("SetValue(const QVariant&)", QVariant(text));

    delete sheet;
    delete sheets;
    workbook->dynamicCall("Save()");
    workbook->dynamicCall("Close");
    delete workbook;
    delete workbooks;
    excel->dynamicCall("Quit()");
    delete excel;

    QTableWidgetItem* item = new QTableWidgetItem;
    item->setText(text);
    ui->tableWidget->setItem(num_row-1, num_col-1, item);
}






// void MainWindow::createTableModel(int rows, int columns, QStringList rowHeaders, QStringList columnHeaders)
// {
//     model = new QStandardItemModel(rows, columns, this);

//     for (int i = 0; i < rows; ++i)
//     {
//         model->setVerticalHeaderItem(i, new QStandardItem(rowHeaders.at(i)));
//     }

//     for (int j = 0; j < columns; ++j)
//     {
//         model->setHorizontalHeaderItem(j, new QStandardItem(columnHeaders.at(j)));
//     }
// }


MainWindow::~MainWindow()
{
    delete ui;
}

