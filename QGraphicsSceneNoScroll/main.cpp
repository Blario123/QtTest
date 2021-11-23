#include <QApplication>
#include "main.h"
#include "Item.h"

void setNoViewScrollbars(QGraphicsView *view);

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Main m;
//    setNoViewScrollbars(m.view);
    m.setGeometry(0, 0, 500, 500);
    m.setWindowTitle("QGraphicsSceneNoScroll");
    m.setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);
    m.show();
    return QApplication::exec();
}

Main::Main(QWidget *parent) : QWidget(parent)    {
    auto *scene = new QGraphicsScene();
    auto *item = new Item();
    view = new QGraphicsView();
    auto *layout = new QGridLayout();

    scene->addItem(item);
//    scene->setSceneRect(0, 0, 1200, 600);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    view->setScene(scene);
    view->setCacheMode(QGraphicsView::CacheNone);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
	view->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(view, 0, 0);
    setLayout(layout);
}

Main::~Main() = default;

void setNoViewScrollbars(QGraphicsView *view) {
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

