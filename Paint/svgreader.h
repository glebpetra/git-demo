#ifndef SVGREADER_H
#define SVGREADER_H

#include <QList>
#include <QGraphicsRectItem>

class SvgReader
{
public:
    SvgReader();
    static QList<QGraphicsRectItem*> getElements(const QString filename);
    static QRectF getSize(const QString filename);
    static QList<QGraphicsPathItem*> getLines(const QString filename);
};

#endif // SVGREADER_H
