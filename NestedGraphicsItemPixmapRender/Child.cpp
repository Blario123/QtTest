#include "Child.h"

Child::Child(QGraphicsItem *parent) : QGraphicsItem(parent), QObject() {

}

Child::~Child() = default;

QRectF Child::boundingRect() const {
	return {};
}

QPainterPath Child::shape() const {
	return {};
}

void Child::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	QPixmap img;
//	painter->setBackgroundMode(Qt::OpaqueMode);
	img.load(":/resources/Image.png");
	painter->drawPixmap(0, 0, img);
}
