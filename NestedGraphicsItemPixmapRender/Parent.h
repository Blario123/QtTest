#ifndef PARENT_H
#define PARENT_H

#include <QGraphicsItem>
#include <QRectF>
#include <QPainterPath>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <QObject>
#include "Child.h"

class Parent : public QObject, public QGraphicsItem {
Q_OBJECT
Q_INTERFACES(QGraphicsItem)
public:
	explicit Parent(QGraphicsItem* parent = nullptr);
	~Parent() override;
	
	QRectF boundingRect() const override;
	
	QPainterPath shape() const override;
	
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
	
private:
	Child *c;
};

#endif //PARENT_H
