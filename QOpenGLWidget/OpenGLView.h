#ifndef OPENGLVIEW_H
#define OPENGLVIEW_H

#include <QOpenGLWidget>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QOpenGLFunctions>

class OpenGLView : public QOpenGLWidget, protected QOpenGLFunctions {
Q_OBJECT
public:
    explicit OpenGLView(QOpenGLWidget *parent = nullptr);
    ~OpenGLView() override;
    QSize sizeHint() const;
private:
    QOpenGLShaderProgram *shader;
    std::vector<QColor> vertexColours;
    std::vector<float> vertexBufferData;
    QOpenGLBuffer vertexBufferObject;
    QOpenGLBuffer indexBuffer;
    QOpenGLVertexArrayObject vao;
protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
};

#endif // OPENGLVIEW_H
