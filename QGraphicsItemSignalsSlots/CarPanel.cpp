//
// Created by blario123 on 06/11/2021.
//

#include "CarPanel.h"

CarPanel::CarPanel(QGraphicsItem *item) : QGraphicsItem(item), QObject() {
    path = new QPainterPath();
    color = Qt::red;
    qDebug() << "[INFO] " << "CarPanel Constructor called. Radius is set to " << m_radius << ".";
    path->addEllipse(0, 0, this->m_radius, this->m_radius);
    update();
}

void CarPanel::setRadius(int radius) {
    this->m_radius = radius;
    qDebug() << "[INFO] " << "Radius set to " << m_radius << ".";
    color = Qt::blue;
    update();
}

int CarPanel::radius() {
    return m_radius;
}

void CarPanel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(color);
    painter->drawPath(*path);
    qDebug() << "Painter Called";
}

CarPanel::~CarPanel() {
    delete path;
}

QRectF CarPanel::boundingRect() const {
    return QRectF(-10, -10, 10, 10);
}

