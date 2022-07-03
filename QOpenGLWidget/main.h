#include <QApplication>
#include <QWidget>
#include <QGridLayout>

#include "OpenGLView.h"

#ifndef MAIN_H
#define MAIN_H

class Main : public QWidget {
Q_OBJECT
public:
    explicit Main(QWidget *parent = nullptr);
    ~Main() override = default;
private:
    QGridLayout *gridLayout;
    OpenGLView *glWidget;
};

#endif // MAIN_H
