#include "Child.h"

Child::Child(QString a, QGraphicsItem *parent) : QGraphicsItem(parent), QObject() {
	name = std::move(a);
	color = Qt::red;
}

Child::~Child() = default;

QRectF Child::boundingRect() const {
	return {};
}

QPainterPath Child::shape() const {
	QPainterPath path;
	path.addRoundedRect(0, 0, 200, 200, 10, 100);
	return path;
}

void Child::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	qDebug() << name << "- print";
	painter->setBrush(color);
	painter->drawPath(shape());
}

void Child::changeColor(int c) {
	color = QColor(255, c, 255);
	update();
}
