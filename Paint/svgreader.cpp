#include "svgreader.h"
#include <QFile>
#include <QPen>
#include <QStringList>
#include <QDomDocument>

SvgReader::SvgReader() {}

QList<QGraphicsRectItem *> SvgReader::getElements(const QString filename)
{
    QList<QGraphicsRectItem *> rectList;
    QDomDocument doc;
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly) || !doc.setContent(&file))
        return rectList;

    QDomNodeList docList = doc.elementsByTagName("g");
    for (int i = 0; i < docList.size(); i++)
    {
        QDomNode node = docList.item(i);
        QDomElement elem = node.firstChildElement("rect");
        if (elem.isNull())
            continue;
        else
        {
            QGraphicsRectItem* rect = new QGraphicsRectItem();
            rect->setFlag(QGraphicsItem::ItemIsMovable);
            QDomElement rectangle = node.toElement();
            rect->setRect(elem.attribute("x").toInt(),
                          elem.attribute("y").toInt(),
                          elem.attribute("width").toInt(),
                          elem.attribute("height").toInt());

            QColor fillColor(rectangle.attribute("fill", "#ffffff"));
            fillColor.setAlphaF(rectangle.attribute("fill-opacity", "0").toFloat());
            rect->setBrush(QBrush(fillColor));

            QColor strokeColor(rectangle.attribute("stroke", "#000000"));
            strokeColor.setAlphaF(rectangle.attribute("stroke-opacity", "0").toFloat());
            rect->setPen(QPen(strokeColor, rectangle.attribute("stroke-width", "0").toInt()/*,*/
                              /*rectangle.attribute("stroke-linecap", "square"), rectangle.attribute("stroke-linejoin", "bevel")*/));

            rectList.append(rect);
        }
    }

    file.close();
    return rectList;
}


QRectF SvgReader::getSize(const QString filename)
{
    QDomDocument doc;
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly) || !doc.setContent(&file))
    {
        file.close();
        return QRectF(0, 0, 200, 200);
    }

    QDomNodeList list = doc.elementsByTagName("svg");
    if (list.length() > 0)
    {
        QDomElement svgElement = list.item(0).toElement();
        QStringList parameters = svgElement.attribute("viewBox").split(" ");
        file.close();
        return QRectF(parameters.at(0).toInt(),
                      parameters.at(1).toInt(),
                      parameters.at(2).toInt(),
                      parameters.at(3).toInt());
    }
    file.close();
    return QRectF(0, 0, 200, 200);
}

QList<QGraphicsPathItem *> SvgReader::getLines(const QString filename)
{
    QList<QGraphicsPathItem *> polylineList;

    QDomDocument doc;
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly) || !doc.setContent(&file))
        return polylineList;

    QDomNodeList pList = doc.elementsByTagName("g");
    for (int i = 0; i < pList.size(); i++) {
        QDomNode pNode = pList.item(i);
        QDomElement pathElement = pNode.firstChildElement("path");
        if (pathElement.isNull()){
            continue;
        } else {
            QGraphicsPathItem *polyline = new QGraphicsPathItem();
            auto pElement = pNode.toElement();

            polyline->setBrush(QBrush(Qt::transparent));

            QColor strokeColor(pElement.attribute("stroke", "#000000"));
            strokeColor.setAlphaF(pElement.attribute("stroke-opacity").toFloat());
            polyline->setPen(QPen(strokeColor, pElement.attribute("stroke-width", "0").toInt()));

            QPainterPath path;
            QStringList listDotes = pathElement.attribute("d").split(" ");
            QString first = listDotes.at(0);
            QStringList firstElement = first.replace(QString("M"),QString("")).split(",");
            path.moveTo(firstElement.at(0).toInt(),firstElement.at(1).toInt());
            for(int i = 1; i < listDotes.length(); i++){
                QString other = listDotes.at(i);
                QStringList dot = other.replace(QString("L"),QString("")).split(",");
                path.lineTo(dot.at(0).toInt(),dot.at(1).toInt());
            }
            polyline->setPath(path);
            polylineList.append(polyline);
        }
    }
    file.close();
    return polylineList;
}

// QList<QGraphicsLineItem *> SvgReader::getElements(const QString filename)
// {
//     QList<QGraphicsLineItem *> graphicsList;

//     QDomDocument doc;
//     QFile file(filename);
//     if (!file.open(QIODevice::ReadOnly) || !doc.setContent(&file))
//         return graphicsList;

//     QDomNodeList gList = doc.elementsByTagName("g");
//     for (int i = 0; i < gList.size(); i++) {
//         QDomNode gNode = gList.item(i);
//         QDomElement pathElement = gNode.firstChildElement("path");
//         if (!pathElement.isNull()){
//             QGraphicsLineItem *polyline = new QGraphicsLineItem();
//             auto pElement = gNode.toElement();

//             QColor strokeColor(pElement.attribute("stroke", "#000000"));
//             strokeColor.setAlphaF(pElement.attribute("stroke-opacity").toFloat());
//             polyline->setPen(QPen(strokeColor, pElement.attribute("stroke-width", "0").toInt()));

//             QLine line;
//             QPainterPath path;
//             QStringList listDotes = pathElement.attribute("d").split(" ");
//             QString first = listDotes.at(0);
//             QStringList firstElement = first.replace(QString("M"),QString("")).split(",");
//             path.moveTo(firstElement.at(0).toInt(),firstElement.at(1).toInt());
//             for(int i = 1; i < listDotes.length(); i++){
//                 QString other = listDotes.at(i);
//                 QStringList dot = other.replace(QString("L"),QString("")).split(",");
//                 path.lineTo(dot.at(0).toInt(),dot.at(1).toInt());
//             }
//             line.setLine(path);
//             graphicsList.append(polyline);
//             continue;
//         }

//         QDomElement rectangle = gNode.firstChildElement("rect");
//         if (!rectangle.isNull()){
//             VERectangle *rect = new VERectangle();
//             auto gElement = gNode.toElement();
//             rect->setRect(rectangle.attribute("x").toInt(),
//                           rectangle.attribute("y").toInt(),
//                           rectangle.attribute("width").toInt(),
//                           rectangle.attribute("height").toInt());

//             QString fill = gElement.attribute("fill", "#ffffff");
//             if(fill.contains("url(#gradient")){
//                 fill.replace(QString("url(#gradient"), QString(""));
//                 fill.replace(QString(")"), QString(""));
//                 QLinearGradient g = gradientList.at(fill.toInt() - 1);
//                 auto tmpRect = rect->rect();
//                 g.setStart(tmpRect.left() + tmpRect.width()/2,tmpRect.top());
//                 g.setFinalStop(tmpRect.left() + tmpRect.width()/2,tmpRect.bottom());
//                 rect->setBrush(QBrush(g));
//             } else {
//                 QColor fillColor(gElement.attribute("fill", "#ffffff"));
//                 fillColor.setAlphaF(gElement.attribute("fill-opacity","0").toFloat());
//                 rect->setBrush(QBrush(fillColor));
//             }

//             QColor strokeColor(gElement.attribute("stroke", "#000000"));
//             strokeColor.setAlphaF(gElement.attribute("stroke-opacity").toFloat());

//             QString transString = gElement.attribute("transform");
//             transString.replace(QString("matrix("),QString(""));
//             transString.replace(QString(")"),QString(""));
//             QStringList transList = transString.split(",");

//             QTransform trans(rect->transform());

//             qreal m11 = trans.m11();    // Horizontal scaling
//             qreal m12 = trans.m12();    // Vertical shearing
//             qreal m13 = trans.m13();    // Horizontal Projection
//             qreal m21 = trans.m21();    // Horizontal shearing
//             qreal m22 = trans.m22();    // vertical scaling
//             qreal m23 = trans.m23();    // Vertical Projection
//             qreal m31 = trans.m31();    // Horizontal Position (DX)
//             qreal m32 = trans.m32();    // Vertical Position (DY)
//             qreal m33 = trans.m33();    // Addtional Projection Factor

//             m11 = transList.at(0).toFloat();
//             m12 = transList.at(1).toFloat();
//             m21 = transList.at(2).toFloat();
//             m22 = transList.at(3).toFloat();
//             m31 = transList.at(4).toFloat();
//             m32 = transList.at(5).toFloat();

//             trans.setMatrix(m11,m12,m13,m21,m22,m23,m31,m32,m33);
//             rect->setTransform(trans);
//             rect->setPen(QPen(strokeColor,gElement.attribute("stroke-width", "0").toInt()));

//             graphicsList.append(rect);
//             continue;
//         }
//     }
//     file.close();

//     return graphicsList;
// }

