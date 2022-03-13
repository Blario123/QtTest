#include "Parent.h"

Parent::Parent(QGraphicsItem *parent) : QGraphicsItem(parent), QObject() {
	c = new Child(this);
}

Parent::~Parent() = default;

QRectF Parent::boundingRect() const {
	return QRectF();
}

QPainterPath Parent::shape() const {
	QPainterPath path;
	path.addRoundedRect(0, 0, 600, 600, 10, 10);
	return path;
}

void Parent::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	painter->setPen(QPen(Qt::red, 4));
	painter->drawPath(shape());
}
