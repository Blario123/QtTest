#ifndef OPENGLVIEW_H
#define OPENGLVIEW_H

#include <QTimer>
#include <QElapsedTimer>
#include <QOpenGLWidget>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QOpenGLFunctions>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

class OpenGLView : public QOpenGLWidget, protected QOpenGLFunctions {
Q_OBJECT
public:
    explicit OpenGLView(QOpenGLWidget *parent = nullptr);
    ~OpenGLView() override;
    QSize sizeHint() const;
    void animateColorsTo(const std::vector<QColor> &);\
private:
    QElapsedTimer timer;
    void updateScene();
    void animate();
    QOpenGLShaderProgram *shader;
    std::vector<QColor> vertexColours;
    std::vector<float> vertexBufferData;
    std::vector<QColor> toColors;
    std::vector<QColor> fromColors;
    uint frameCount;
    QOpenGLBuffer vertexBufferObject;
    QOpenGLBuffer indexBuffer;
    QOpenGLVertexArrayObject vao;
private slots:
    void updateColor();
protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
};

#endif // OPENGLVIEW_H
