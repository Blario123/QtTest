#include "main.h"
#include "Parent.h"
#include "Control.h"

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	Main m;
	m.setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);
	m.show();
	return QApplication::exec();
}

Main::Main(QWidget *parent) : QWidget(parent) {
	auto *layout = new QGridLayout;
	auto *scene = new QGraphicsScene;
	auto *view = new QGraphicsView;
	auto *p = new Parent("Parent");
	auto *c = new Control;
	c->show();
	scene->addItem(p);
	scene->setSceneRect(QRectF(0, 0, 400, 400));
	scene->setItemIndexMethod(QGraphicsScene::NoIndex);
	view->setRenderHint(QPainter::Antialiasing);
	view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
	view->setScene(scene);
	layout->addWidget(view);
	setLayout(layout);
	connect(c->slider, SIGNAL(valueChanged(int)), c->label, SLOT(setNum(int)));
	connect(c->slider, SIGNAL(valueChanged(int)), p->c, SLOT(changeColor(int)));
	connect(c, SIGNAL(closeSignal()), this, SLOT(deleteLater()));
}

Main::~Main() = default;
