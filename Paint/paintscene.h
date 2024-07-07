#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QDebug>
#include <QFileDialog>
#include "choose.h"
#include "figure.h"
#include "romb.h"
#include <QGraphicsRectItem>
#include <QList>

class paintScene : public QGraphicsScene
{
    Q_OBJECT
    // Q_PROPERTY(int typeFigure
    //                READ typeFigure WRITE setTypeFigure
    //                    NOTIFY typeFigureChanged)


public:
    explicit paintScene(QObject *parent = 0);
    ~paintScene();
    // int typeFigure();
    // void setTypeFigure(const int type);

    // enum FigureTypes {SquareType,RombType,TriangleType, CustomType};

private:
    QPointF previousPoint;
    QBrush brush = Qt::red;
    int obj_status = 0;
    QPoint ma[4];
    QList<QGraphicsRectItem*> rectList;
    // Figure *tempFigure;
    // int m_typeFigure = 0;

private:
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);

public slots:
    void slotChooseColor();
    void setBrush(int index);
    void chooseObj(int index);

signals:
    // void typeFigureChanged();
};
#endif // PAINTSCENE\_H
