#include "main.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    Main m;
    m.show();
    return QApplication::exec();
}

Main::Main(QWidget *parent) : QWidget(parent), gridLayout(new QGridLayout), glWidget(new OpenGLView) {
    gridLayout->addWidget(glWidget);
    setLayout(gridLayout);
}
