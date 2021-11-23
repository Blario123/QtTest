#ifndef MAIN_H
#define MAIN_H

#include <QWidget>
#include <QGridLayout>
#include <QGraphicsView>
#include <QGraphicsScene>

class Main : public QWidget {
    Q_OBJECT

public:
    explicit Main(QWidget *parent = nullptr);
    ~Main() override;
    QGraphicsView *view;
};

#endif //MAIN_H