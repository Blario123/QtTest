#include "Chart.h"

void noMargins(QWidget *widget) {
	widget->setContentsMargins(0, 0, 0, 0);
}

void noMargins (QLayout *layout) {
	layout->setContentsMargins(0, 0, 0, 0);
}

Chart::Chart(QWidget *parent) : QWidget(parent),
								p_view(new ChartView),
								p_chart(new QChart),
								p_layout(new QVBoxLayout),
								p_series(new QLineSeries),
								p_hAxis(new QValueAxis),
								p_vAxis(new QValueAxis),
								lSliderCurSel(false),
								rSliderCurSel(false),
								buttonLayout(new QHBoxLayout),
								leftSliderButton(new QPushButton("Slider 1", this)),
								rightSliderButton(new QPushButton("Slider 2", this)) {
	noMargins(this);
	noMargins(p_view);
	noMargins(p_layout);
	
	buttonLayout->addWidget(leftSliderButton);
	buttonLayout->addWidget(rightSliderButton);
	
	connect(leftSliderButton, SIGNAL(clicked()), this, SLOT(lSliderSel()));
	connect(rightSliderButton, SIGNAL(clicked()), this, SLOT(rSliderSel()));
	
	p_chart->addSeries(p_series);
	p_chart->legend()->hide();
	p_view->setChart(p_chart);
	p_vAxis->setRange(-180, 180);
	p_vAxis->setTitleText("Position (deg)");
	p_hAxis->setTitleText("Time (ms)");
	p_chart->addAxis(p_hAxis, Qt::AlignBottom);
	p_chart->addAxis(p_vAxis, Qt::AlignLeft);
	p_series->attachAxis(p_hAxis);
	p_series->attachAxis(p_vAxis);
	
	p_layout->addLayout(buttonLayout);
	p_layout->addWidget(p_view);
	setLayout(p_layout);
}

Chart::~Chart() = default;

void Chart::setSeries(QLineSeries *series) {
	QFuture<void> future = QtConcurrent::run([=]() {
		p_series->clear();
		p_series->append(series->points());
		p_hAxis->setRange(0, series->count());
	});
}

void Chart::lSliderSel() {
	if(rSliderCurSel) {
		rSliderCurSel = !rSliderCurSel;
	}
	lSliderCurSel = true;
}

void Chart::rSliderSel() {
	if(lSliderCurSel) {
		lSliderCurSel = !lSliderCurSel;
	}
	rSliderCurSel = true;
}
