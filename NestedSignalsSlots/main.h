#ifndef MAIN_H
#define MAIN_H

#include <QWidget>
#include <QGridLayout>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QApplication>
#include <QSlider>
#include <QLabel>

class Main : public QWidget {
Q_OBJECT
public:
	explicit Main(QWidget *parent = nullptr);
	~Main();
private:

};

#endif //MAIN_H
