#include "main.h"

void setNoViewScrollbars(QGraphicsView * pView);

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	Main m;
	setNoViewScrollbars(m.view);
	m.setGeometry(0, 0, 600, 600);
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
	scene->setItemIndexMethod(QGraphicsScene::NoIndex);
	view->setContentsMargins(0, 0, 0, 0);
	view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
	view->setScene(scene);
	view->setRenderHint(QPainter::Antialiasing);
	view->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
	gl->addWidget(view);
	gl->setContentsMargins(0, 0, 0, 0);
	setLayout(gl);
}

Main::~Main() = default;

void setNoViewScrollbars(QGraphicsView * pView) {
	pView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	pView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}
