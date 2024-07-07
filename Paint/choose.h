#ifndef CHOOSE_H
#define CHOOSE_H

#include <QDialog>
#include <QPushButton>
#include <QGridLayout>

class Choose : public QDialog
{
    Q_OBJECT
public:
    Choose(QWidget* par = 0);
    ~Choose();
private:
    QPushButton* red;
    QPushButton* black;
    QPushButton* green;

public slots:
    void slotBlack();
    void slotRed();
    void slotGreen();
};

#endif // CHOOSE_H
