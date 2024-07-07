#ifndef QWORKFORM_H
#define QWORKFORM_H

#include <QTextEdit>
#include <QWidget>

class QWorkForm : public QTextEdit
{
    Q_OBJECT
public:
    QWorkForm(QWidget* parent = nullptr);
    int getPos() { return f_pos; };
    int getSize() { return f_size; };

private:
    QString filename;
    int f_pos;
    int f_size;

signals:
    void ChangeTitle(const QString&);
    void ChangeSize(int, int);

public slots:
    void slotLoad();
    void slotSave();
    void slotSaveAs();
};

#endif // QWORKFORM_H
