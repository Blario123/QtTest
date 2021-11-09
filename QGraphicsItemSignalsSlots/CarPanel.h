//
// Created by blario123 on 06/11/2021.
//

#ifndef CARPANEL_H
#define CARPANEL_H

#include <QGraphicsPathItem>
#include <QObject>
#include <QPainter>
#include <QRectF>
#include <QStyleOptionGraphicsItem>

class CarPanel : public QObject, public QGraphicsItem {
    Q_OBJECT
public:
    explicit CarPanel(QGraphicsItem *item = nullptr);
    ~CarPanel() override;
    int radius();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;
private:
    int m_radius = 100;
    QPainterPath *path;
    Qt::GlobalColor color;
public slots:
    void setRadius(int radius);
signals:

protected:

};


#endif //CARPANEL_H
