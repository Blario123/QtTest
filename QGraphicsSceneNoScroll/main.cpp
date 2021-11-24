#include <QApplication>
#include "main.h"
#include "Item.h"
#include "Indicator.h"

void setNoViewScrollbars(QGraphicsView *view);

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	Main m;
    setNoViewScrollbars(m.view);
	m.setGeometry(0, 0, 500, 500);
	m.setWindowTitle("QGraphicsSceneNoScroll");
	m.setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);
	m.show();
	return QApplication::exec();
}

Main::Main(QWidget *parent) : QWidget(parent)    {
	scene = new QGraphicsScene();
	
	auto *item = new Item();
	auto *lInd = new Indicator();
	auto *rInd = new Indicator();
	
	view = new QGraphicsView();
	QGridLayout *layout;
	layout = new QGridLayout;
	
	connect(this, SIGNAL(signalToggleColour()), lInd, SLOT(slotToggleColour()));
	connect(this, SIGNAL(signalToggleColour()), rInd, SLOT(slotToggleColour()));
	
	lInd->setPosition(10, 10);
	rInd->setPosition(114, 114);
	rInd->setOrientation(180);
	
	scene->addItem(item);
	scene->addItem(lInd);
	scene->addItem(rInd);
	
	scene->setItemIndexMethod(QGraphicsScene::NoIndex);
	view->setScene(scene);
	view->setRenderHint(QPainter::Antialiasing);
	view->setCacheMode(QGraphicsView::CacheNone);
	view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
	view->setAlignment(Qt::AlignTop | Qt::AlignLeft);

	layout->setContentsMargins(0, 0, 0, 0);
	layout->addWidget(view, 0, 0);
	setLayout(layout);
}

void Main::mousePressEvent(QMouseEvent *event) {
	emit signalToggleColour();
}

Main::~Main() = default;

void setNoViewScrollbars(QGraphicsView *view) {
	view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

