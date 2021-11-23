#include <QRectF>
#include <QPainterPath>
#include <QGraphicsItem>

#include "Item.h"

Item::Item(QGraphicsItem *parent) {
    qDebug() << "Item called";
}

Item::~Item() = default;

QRectF Item::boundingRect() const {
    return QRectF();
}

QPainterPath Item::shape() const {
    QPainterPath path;
    path.addRoundedRect(0, 0, 500, 500, 50, 50);
    return path;
}

void Item::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setPen(QPen(Qt::red));
    painter->setBrush(Qt::blue);
    painter->drawPath(shape());
    qDebug() << "Painted";
}
