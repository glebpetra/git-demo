#ifndef QMYFORM_H
#define QMYFORM_H

#include <QMainWindow>
#include <QMenu>
#include <QtWidgets>

class QMyForm : public QMainWindow
{
    Q_OBJECT

public:
    QMyForm(QWidget *parent = nullptr);
    ~QMyForm();

public slots:
    void slotInfo();
    void slotChangeTitle(const QString& str);
    void slotChangeSize(int size, int pos);
};
#endif // QMYFORM_H
