#include "main.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    QSurfaceFormat format;
    format.setRenderableType(QSurfaceFormat::OpenGL);
    format.setProfile(QSurfaceFormat::CoreProfile);
    format.setVersion(3, 3);
    format.setAlphaBufferSize(8);
    Main m;
    m.show();
    return QApplication::exec();
}

Main::Main(QWidget *parent) : QWidget(parent), gridLayout(new QGridLayout), glWidget(new OpenGLView) {
    gridLayout->addWidget(glWidget);
    setLayout(gridLayout);
    setGeometry(0, 0, 800, 800);
}
