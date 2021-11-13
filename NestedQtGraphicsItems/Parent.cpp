#include "Parent.h"

Parent::Parent(QGraphicsItem *parent) : QGraphicsItem(parent), QObject() {
	c = new Child();
	qDebug() << "new Parent constructor called";
}

Parent::~Parent() = default;

QRectF Parent::boundingRect() const {
	return QRectF();
}

QPainterPath Parent::shape() const {
	QPainterPath path;
	path.addRoundedRect(0, 0, 100, 100, 5, 5);
	return path;
}

void Parent::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	qDebug() << "Painter Called";
	painter->setPen(Qt::red);
	painter->drawPath(shape());
	painter->setPen(Qt::blue);
	painter->drawPath(c->shape());
}
