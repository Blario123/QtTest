#ifndef MAIN_H
#define MAIN_H

#include <QWidget>
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGridLayout>


#include "Parent.h"
#include "Child.h"

class Main : public QWidget {
Q_OBJECT
public:
	explicit Main(QWidget *parent = nullptr);
	~Main();
	QGraphicsView *view;

private:
};

#endif //MAIN_H
