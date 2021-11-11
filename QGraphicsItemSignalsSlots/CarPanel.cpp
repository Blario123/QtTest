//
// Created by blario123 on 06/11/2021.
//

#include "CarPanel.h"

int m_state;

CarPanel::CarPanel(QGraphicsItem *item) : QGraphicsItem(item), QObject() {
	color = Qt::red;
	m_state = 0;
	qDebug() << "[INFO] " << "CarPanel Constructor called. Radius is set to" << m_radius << ".";
}

void CarPanel::setRadius(int radius) {
    m_radius = radius;
    qDebug() << "[INFO] " << "Radius set to" << m_radius << ".";
	if(m_state) {
		color = Qt::red;
		m_state = 0;
	} else if (!m_state) {
		color = Qt::blue;
		m_state = 1;
	}
    update();
}

int CarPanel::radius() {
    return m_radius;
}

void CarPanel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	path.clear();
	path.addEllipse(0, 0, m_radius, m_radius);
    painter->setBrush(color);
    painter->drawPath(path);
    qDebug() << "Painter Called";
}

CarPanel::~CarPanel() = default;

QRectF CarPanel::boundingRect() const {
    return QRectF(-10, -10, 10, 10);
}

