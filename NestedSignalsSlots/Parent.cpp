#include "Parent.h"

Parent::Parent(QString a, QGraphicsItem *parent) : QGraphicsItem(parent), QObject() {
	name = std::move(a);
	c = new Child("Child", this);
}

Parent::~Parent() = default;

QRectF Parent::boundingRect() const {
	return {};
}

QPainterPath Parent::shape() const {
	QPainterPath path;
	path.addRoundedRect(0, 0, 300, 300, 10, 150);
	return path;
}

void Parent::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	qDebug() << name << "- print";
	painter->setBrush(Qt::blue);
	painter->drawPath(shape());
}

