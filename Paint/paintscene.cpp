#include "paintscene.h"

paintScene::paintScene(QObject *parent) : QGraphicsScene(parent)
{}

paintScene::~paintScene()
{}

// int paintScene::typeFigure()
// { return m_typeFigure; }

// void paintScene::setTypeFigure(const int type)
// { m_typeFigure = type; }

void paintScene::setBrush(int index)
{
    if (index == 0)
        brush = Qt::red;
    if (index == 1)
        brush = Qt::green;
    if (index == 2)
        brush = Qt::blue;
}

void paintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (obj_status == 0)
    {
        addEllipse(event->scenePos().x() - 2, event->scenePos().y() - 2, 4, 4, QPen(Qt::NoPen), brush);
    }
    else if (obj_status == 1)
    {
        ma[0] = QPoint(event->scenePos().x(), event->scenePos().y());
        ma[1] = QPoint(previousPoint.x(), previousPoint.y());
        qreal width = abs(ma[1].x() - ma[0].x());
        qreal height = abs(ma[1].y() - ma[0].y());
        QGraphicsRectItem* item = new QGraphicsRectItem();
        QRect rect(ma[0].x(), ma[0].y(), width, height);
        item->setRect(rect);
        item->setBrush(brush);
        item->setPen(QPen(Qt::black));
        this->addItem(item);
        rectList.append(item);
        // addRect(ma[0].x(), ma[0].y(), width, height, QPen(Qt::black), brush);
    }
    else if (obj_status == 2)
    {
        ma[0] = QPoint(event->scenePos().x(), event->scenePos().y());
        ma[1] = QPoint(event->scenePos().x()+20, event->scenePos().y());
        ma[2] = QPoint(event->scenePos().x(), event->scenePos().y()+20);
        QPolygon pol;
        pol << ma[0] << ma[1] << ma[2];
        addPolygon(pol, QPen(Qt::black), brush);
    }
    else if (obj_status == 3)
    {
        ma[0] = QPoint(event->scenePos().x(), event->scenePos().y());
        ma[1] = QPoint(event->scenePos().x()+20, event->scenePos().y()+20);
        qreal width = ma[1].x() - ma[0].x();
        qreal height = ma[1].y() - ma[0].y();
        addEllipse(ma[0].x(), ma[0].y(), width, height, QPen(Qt::black), brush);
    }
    else if (obj_status == 4)
    {
        ma[0] = QPoint(event->scenePos().x(), event->scenePos().y());
        addLine(ma[0].x(), ma[0].y(), previousPoint.x(), previousPoint.y(), QPen(brush.color()));
    }
    // else if (obj_status == 1)
    // {
    //     // QPointF ma[2];
    //     // ma[0] = QPointF(event->scenePos().x(), event->scenePos().y());
    //     ma[0] = QPointF(event->scenePos().x(), event->scenePos().y());
    //     ma[1] = QPointF(event->scenePos().x()+20, event->scenePos().y()+20);
    //     qreal width = ma[1].x() - ma[0].x();
    //     qreal height = ma[1].y() - ma[0].y();
    //     addRect(ma[0].x(), ma[0].y(), width, height, QPen(Qt::black), brush);
    // }
    // else if (obj_status == 1)
    // {
    //     // QPointF ma[2];
    //     // ma[0] = QPointF(event->scenePos().x(), event->scenePos().y());
    //     ma[0] = QPointF(event->scenePos().x(), event->scenePos().y());
    //     ma[1] = QPointF(event->scenePos().x()+20, event->scenePos().y()+20);
    //     qreal width = ma[1].x() - ma[0].x();
    //     qreal height = ma[1].y() - ma[0].y();
    //     addRect(ma[0].x(), ma[0].y(), width, height, QPen(Qt::black), brush);
    // }

    // tempFigure->setEndPoint(event->scenePos());
    // this->update(QRectF(0, 0, this->width(), this->height()));
    // switch (m_typeFigure)
    // {
    // case RombType:
    // {
    //     Romb* item = new Romb(event->scenePos());
    //     item->setPos(event->pos());
    //     tempFigure = item;
    //     this->addItem(item);
    //     break;
    // }
    // // case CustomType:
    // // {
    // //     addEllipse(event->scenePos().x() - 2, event->scenePos().y() - 2, 4, 4, QPen(Qt::NoPen), brush);
    // //     break;
    // // }

    previousPoint = event->scenePos();
}

void paintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (obj_status == 0)
    {
        addLine(previousPoint.x(), previousPoint.y(), event->scenePos().x(), event->scenePos().y(), QPen(brush, 3, Qt::SolidLine, Qt::RoundCap));
    }
    if (obj_status == 5)
    {
        foreach (QGraphicsItem* item, rectList)
        {
            item->setFlag(QGraphicsRectItem::ItemIsMovable);
        }
    }
    previousPoint = event->scenePos();
}

void paintScene::slotChooseColor()
{
    Choose* choose = new Choose;
    choose->setMinimumWidth(30);
    choose->setMinimumHeight(30);
    choose->show();
}

void paintScene::chooseObj(int index)
{
    obj_status = index;
}


