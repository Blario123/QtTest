#ifndef CHARTVIEW_H
#define CHARTVIEW_H

#include <QWidget>
#include <QChartView>

#if QT_VERSION_MAJOR == 5
using namespace QtCharts;
#endif

class ChartView : public QChartView {
	Q_OBJECT
public:
	explicit ChartView(QChart *chart = nullptr, QWidget *parent = nullptr);

protected:
	void mouseMoveEvent(QMouseEvent *event) override;
};
#endif
