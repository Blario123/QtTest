#ifndef INDICATOR_H
#define INDICATOR_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPointF>

class Indicator : public QObject, public QGraphicsItem {
Q_OBJECT
Q_INTERFACES(QGraphicsItem)
public:
	explicit Indicator(QGraphicsItem *parent = nullptr);
	QRectF boundingRect() const override;
	QPainterPath shape() const override;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
	void setPosition(QPointF pos);
	void setPosition(qreal x, qreal y);
	void setOrientation(qreal orientation);

private:
	bool indState;
	QColor color;
	QPointF origin;
	qreal mOrientation = 0;
	qreal mSize = 64;

public slots:
	void slotToggleColour();
};

#endif //INDICATOR_H
