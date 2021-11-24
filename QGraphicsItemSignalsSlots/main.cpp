#include <QApplication>
#include "CarPanel.h"
#include "main.h"

QMargins NoMargin(0, 0, 0, 0);

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Main m;
    m.setWindowTitle("QGraphicsItem & Slots and Signal Example");
    m.setGeometry(0, 0, 415, 200);
    m.setFixedSize(m.size());
    m.setContentsMargins(0, 0, 0, 0);
    m.show();
    return QApplication::exec();
}

Main::Main(QWidget *parent) : QWidget(parent), m_counter(0) {
    scene = new QGraphicsScene();
    cp = new CarPanel();
    view = new QGraphicsView();
    gl = new QGridLayout();

    connect(this, SIGNAL(setTargetRadius(int)), cp, SLOT(setRadius(int)));

    scene->addItem(cp);
    scene->setSceneRect(0, 0, 100, 100);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    view->setScene(scene);
    view->setRenderHint(QPainter::Antialiasing);
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->setDragMode(QGraphicsView::NoDrag);

    gl->setContentsMargins(NoMargin);
    gl->addWidget(view, 0, 0);

    setLayout(gl);
}

void Main::mousePressEvent(QMouseEvent *event) {
    qDebug() << "[INFO] " << "Previous radius is set to" << cp->radius() << ".";
    emit setTargetRadius(10);
    QWidget::mousePressEvent(event);
    qDebug() << "[INFO] " << "New radius is set to" << cp->radius() << ".";
	cp->update();
	gl->update();
	scene->update();
	view->update();
}

Main::~Main() {
    delete scene;
    delete gl;
    delete view;
    delete cp;
}
