#ifndef CHILD_H
#define CHILD_H

#include <QGraphicsItem>
#include <QRectF>
#include <QPainterPath>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <QObject>

class Child : public QObject, public QGraphicsItem {
Q_OBJECT
Q_INTERFACES(QGraphicsItem)
public:
	explicit Child(QGraphicsItem* parent = nullptr);
	~Child() override;
	
	QRectF boundingRect() const override;
	
	QPainterPath shape() const override;
	
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
};

#endif //CHILD_H
