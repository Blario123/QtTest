#include "Indicator.h"

Indicator::Indicator(QGraphicsItem *parent) : QObject(), QGraphicsItem(parent) {
	indState = true;
	color = 0x666666;
	mOrientation = 0;
}

QRectF Indicator::boundingRect() const {
	return QRectF();
}

QPainterPath Indicator::shape() const {
	QPainterPath path;
	QPolygonF poly;
	poly    << QPointF(origin.x(), origin.y() + mSize / 2)
			<< QPointF(origin.x() + 30, origin.y())
			<< QPointF(origin.x() + 30, origin.y() + 12)
			<< QPointF(origin.x() + mSize, origin.y() + 12)
			<< QPointF(origin.x() + mSize, origin.y() + 52)
			<< QPointF(origin.x() + 30, origin.y() + 52)
			<< QPointF(origin.x() + 30, origin.y() + mSize)
			<< QPointF(origin.x(), origin.y() + (mSize / 2));
	poly = QTransform().translate(origin.x(), origin.y()).rotate(mOrientation).translate(-origin.x(), -origin.y()).map(poly);
	path.addPolygon(poly);
	return path;
}

void Indicator::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	painter->fillPath(shape(), QBrush(color));
}

void Indicator::slotToggleColour() {
	qDebug() << color;
	if(indState) {
		color = Qt::green;
		indState = !indState;
	} else {
		color = 0x666666;
		indState = !indState;
	}
	update();
}

void Indicator::setPosition(QPointF pos) {
	origin = pos;
}

void Indicator::setPosition(qreal x, qreal y) {
	origin.setX(x);
	origin.setY(y);
}

void Indicator::setOrientation(qreal orientation) {
	mOrientation = orientation;
}

