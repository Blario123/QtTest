#ifndef PARENT_H
#define PARENT_H

#include <QGraphicsItem>
#include <QPainter>
#include <utility>
#include "Child.h"
#include <QPainterPath>

class Parent : public QObject, public QGraphicsItem {
Q_OBJECT
Q_INTERFACES(QGraphicsItem)
public:
	explicit Parent(QString, QGraphicsItem *parent = nullptr);
	~Parent() override;
	QRectF boundingRect() const override;
	QPainterPath shape() const override;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
	Child *c;
private:
	QString name;
};

#endif
