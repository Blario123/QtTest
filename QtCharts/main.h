#ifndef MAIN_H
#define MAIN_H

#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QChart>
#include <QMenu>
#include <QMenuBar>
#include <QChartView>
#include <QValueAxis>
#include <QLineSeries>
#include <QRadioButton>
#include <QButtonGroup>
#include <QTabWidget>

#include "Chart.h"

#if QT_VERSION_MAJOR == 5
using namespace QtCharts;
#endif

class Main;

class Main : public QWidget {
Q_OBJECT
public:
	explicit Main(QWidget *parent = nullptr);
	~Main() override;
private:
	Chart *chart1;
	Chart *chart2;
	QAction *a_AboutQt;
	QAction *a_Exit;
	QAction *a_SelectCAN;
	QAction *a_StartStop;
	QGridLayout *gl;
	QHBoxLayout *dataControlLayout;
	QLineSeries *ls;
	QMenu *fileMenu;
	QMenu *aboutMenu;
	QMenuBar *menuBar;
	QPushButton *startRec;
	QPushButton *stopRec;
	QTabWidget *chartView;
	QPushButton *test;
private slots:
	void on_StartStop();
	void on_startRec();
	void on_stopRec();
	void on_test();
	static void on_Exit();
	static void on_AboutQt();
};
#endif //MAIN_H
