#include <QRectF>
#include <QPainterPath>
#include <QGraphicsItem>

#include "Item.h"

Item::Item(QGraphicsItem *parent) {
	l = 500;
}

Item::~Item() = default;

QRectF Item::boundingRect() const {
    return QRectF();
}

QPainterPath Item::shape() const {
    QPainterPath path;
    path.addRoundedRect(0, 0, l, l, 50, 50);
	path.translate(-boundingRect().width()/2, -boundingRect().height()/2);
    return path;
}

void Item::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setPen(QPen(Qt::red));
    painter->setBrush(Qt::blue);
    painter->drawPath(shape());
    qDebug() << "Painted";
}
