#ifndef ITEM_H
#define ITEM_H

#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QPainterPath>
#include <QStyleOptionGraphicsItem>
#include <QPen>
#include <QRectF>

class Item : public QObject, public QGraphicsItem {
Q_OBJECT
Q_INTERFACES(QGraphicsItem)

public:
    explicit Item(QGraphicsItem *parent = nullptr);
    ~Item() override;
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
	int l;
};


#endif  //ITEM_H
