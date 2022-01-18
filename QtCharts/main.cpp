#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <sys/stat.h>
#include <random>

#include <QApplication>

#include "main.h"

inline bool csvExist(const std::string& name);
void createData();

#if QT_VERSION_MAJOR == 5
using namespace QtCharts;
#endif

int main(int argc, char *argv[]) {
	createData();
	QApplication a(argc, argv);
	Main m;
	m.setGeometry(0,0,900,400);
	m.show();
	return QApplication::exec();
}

Main::Main(QWidget *parent) : QWidget(parent),
							  test(new QPushButton),
							  chart1(new Chart),
							  chart2(new Chart),
							  a_SelectCAN(new QAction("Select CAN Device", this)),
							  a_StartStop(new QAction("Start", this)),
							  a_Exit(new QAction("Exit", this)),
							  a_AboutQt(new QAction("About Qt", this)),
							  gl(new QGridLayout),
							  dataControlLayout(new QHBoxLayout),
							  ls(new QLineSeries),
							  aboutMenu(new QMenu("About")),
							  fileMenu(new QMenu("File")),
							  menuBar(new QMenuBar),
							  startRec(new QPushButton("Start", this)),
							  stopRec(new QPushButton("Stop", this)),
							  chartView(new QTabWidget) {
	
	chartView->addTab(chart1, "Chart 1");
	chartView->addTab(chart2, "Chart 2");
	
	stopRec->setDisabled(true);
	
	dataControlLayout->addWidget(startRec);
	dataControlLayout->addWidget(stopRec);
	dataControlLayout->addWidget(test);
	dataControlLayout->addStretch();

	fileMenu->addAction(a_StartStop);
	fileMenu->addAction(a_Exit);
	
	aboutMenu->addAction(a_AboutQt);
	
	menuBar->addMenu(fileMenu);
	menuBar->addMenu(aboutMenu);

	connect(a_StartStop, SIGNAL(triggered()), this, SLOT(on_StartStop()));
	connect(a_Exit, SIGNAL(triggered()), this, SLOT(on_Exit()));
	connect(a_AboutQt, SIGNAL(triggered()), this, SLOT(on_AboutQt()));
	connect(startRec, SIGNAL(clicked()), this, SLOT(on_startRec()));
	connect(stopRec, SIGNAL(clicked()), this, SLOT(on_stopRec()));
	connect(test, SIGNAL(clicked()), this, SLOT(on_test()));

    std::ifstream file("data.csv");
    std::string line;

    while(getline(file, line)) {
        std::vector<int> data;
        std::stringstream ss(line);
        for(int i; ss >> i;) {
            data.push_back(i);
            if(ss.peek() == ',') {
                ss.ignore();
            }
        }
        ls->append(data[0], data[1]);
        data.clear();
    }
	

	gl->setMenuBar(menuBar);
	gl->addLayout(dataControlLayout, 0, 0);
	gl->addWidget(chartView, 1, 0, 1, 2);
	setLayout(gl);
}

void Main::on_StartStop() {
	if(a_StartStop->text() == "Start") {
		a_StartStop->setText("Stop");
	} else {
		a_StartStop->setText("Start");
	}
}

void Main::on_startRec() {
	qDebug() << "Start";
	startRec->setDisabled(true);
	if(!stopRec->isEnabled()) {
		stopRec->setDisabled(false);
	}
}

void Main::on_stopRec() {
	qDebug() << "Stop";
	stopRec->setDisabled(true);
	if(!startRec->isEnabled()) {
		startRec->setDisabled(false);
	}
}

void Main::on_Exit() {
	QApplication::quit();
}

void Main::on_AboutQt() {
	QApplication::aboutQt();
}

void Main::on_test() {
//	tChart->setSeries(ls);
	qDebug() << chart1->lSliderCurSel;
}

Main::~Main() = default;

bool csvExist(const std::string &name) {
	struct stat buffer{};
	return(stat(name.c_str(), &buffer) == 0);
}

void createData() {
	if(!csvExist("data.csv")) {
		std::ofstream sampleData;
		sampleData.open("data.csv");
		std::default_random_engine rEngine;
		std::uniform_int_distribution<int> iDistro(-180,180);
		for (int i = 1; i != 10000; i++) {
			sampleData << i << "," << iDistro(rEngine) << "\n";
//			sampleData << i << "," << (((i/27.778))-180) << "\n";
		}
		sampleData.close();
	}
}
