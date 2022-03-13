#ifndef CHILD_H
#define CHILD_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPainterPath>

class Child : public QObject, public QGraphicsItem {
Q_OBJECT
Q_INTERFACES(QGraphicsItem)
public:
	explicit Child(QString, QGraphicsItem *parent = nullptr);
	~Child() override;
	QRectF boundingRect() const override;
	QPainterPath shape() const override;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
	QString name;
	QColor color;
public slots:
	void changeColor(int);
};

#endif //CHILD_H
