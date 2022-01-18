#ifndef CHART_H
#define CHART_H

#include <QWidget>
#include <QObject>
#include <QChartView>
#include <QLineSeries>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QValueAxis>
#include <QFuture>
#include <qtconcurrentrun.h>
#include <QPushButton>
#include "ChartView.h"

#if QT_VERSION_MAJOR == 5
using namespace QtCharts;
#endif

class Chart : public QWidget {
Q_OBJECT
public:
	explicit Chart(QWidget *parent = nullptr);
	~Chart() override;
	bool lSliderCurSel;
	bool rSliderCurSel;
private:
	ChartView *p_view;
	QChart *p_chart;
	QVBoxLayout *p_layout;
	QLineSeries *p_series;
	QHBoxLayout *buttonLayout;
	QPushButton *leftSliderButton;
	QPushButton *rightSliderButton;
	QValueAxis *p_hAxis;
	QValueAxis *p_vAxis;

public slots:
	void setSeries(QLineSeries *series);
	void lSliderSel();
	void rSliderSel();
signals:

};

#endif
