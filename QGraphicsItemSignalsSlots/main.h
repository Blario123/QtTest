//
// Created by blario123 on 06/11/2021.
//

#ifndef MAIN_H
#define MAIN_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QRectF>
#include <QGridLayout>
#include <QTimer>

class Main : public QWidget {
    Q_OBJECT
public:
    explicit Main(QWidget *parent = nullptr);
    ~Main();

private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    CarPanel *cp;
    QGridLayout *gl;

    int m_counter{};
    void radiusLoop();
    void mousePressEvent(QMouseEvent *event);

public slots:

signals:
    void setTargetRadius(int radius);
    void mouseClicked();

};

#endif //MAIN_H
