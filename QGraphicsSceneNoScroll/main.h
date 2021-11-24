#ifndef MAIN_H
#define MAIN_H

#include <QWidget>
#include <QGridLayout>
#include <QGraphicsView>
#include <QGraphicsScene>

class Main : public QWidget {
    Q_OBJECT
protected:
	void mousePressEvent(QMouseEvent *event) override;

public:
    explicit Main(QWidget *parent = nullptr);
    ~Main() override;
    QGraphicsView *view;
	QGraphicsScene *scene;
signals:
	void signalToggleColour();
};

#endif //MAIN_H
