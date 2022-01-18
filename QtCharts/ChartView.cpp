#include "ChartView.h"

#include <QtDebug>

ChartView::ChartView(QChart *chart, QWidget *parent) : QChartView(chart, parent) {

}

void ChartView::mouseMoveEvent(QMouseEvent *event) {
    #if QT_VERSION_MAJOR == 5
    auto const eventPos = event->localPos();
    #else
    auto const eventPos = event->position();
    #endif

	auto const scenePos = mapToScene(QPoint(static_cast<int>(eventPos.x()), static_cast<int>(eventPos.y())));
	auto const chartPos = chart()->mapFromScene(scenePos);
	auto const value = chart()->mapToValue(chartPos);
//	qDebug() << value;
}
