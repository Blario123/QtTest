#include "main.h"

void setNoViewScrollbars(QGraphicsView *pView);

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	Main m;
	setNoViewScrollbars(m.view);
	m.setGeometry(0,0, 150, 150);
	m.setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);
	m.show();
	return QApplication::exec();
}

Main::Main(QWidget *parent) : QWidget(parent) {
	auto *scene = new QGraphicsScene();
	auto *p = new Parent();
	view = new QGraphicsView();
	auto *gl = new QGridLayout();
	scene->addItem(p);
	scene->setSceneRect(0, 0, 100, 100);
	scene->setItemIndexMethod(QGraphicsScene::NoIndex);
	view->setScene(scene);
	gl->addWidget(view);
	gl->setContentsMargins(0, 0, 0, 0);
	setLayout(gl);
}

Main::~Main() = default;

void setNoViewScrollbars(QGraphicsView *pView) {
	pView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	pView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}
