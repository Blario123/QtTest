#include "Child.h"

Child::Child(QGraphicsItem *parent) : QGraphicsItem(parent), QObject() {

}

Child::~Child() = default;

QRectF Child::boundingRect() const {
	return QRectF();
}

QPainterPath Child::shape() const {
	QPainterPath path;
	path.addEllipse(0, 0, 100, 100);
	return path;
}

void Child::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

}
