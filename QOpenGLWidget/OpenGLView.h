#ifndef OPENGLVIEW_H
#define OPENGLVIEW_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <QKeyEvent>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLFunctions_4_5_Core>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>

class QKeyEvent;

class OpenGLView : public QOpenGLWidget, protected QOpenGLFunctions_4_5_Core {
Q_OBJECT
public:
    explicit OpenGLView(QWidget *parent = nullptr);
    ~OpenGLView() override = default;
protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;
    void keyPressEvent(QKeyEvent *event) override;
private:
    QOpenGLShaderProgram *prog;
    GLuint vao;
    GLuint vbo;
    GLuint ebo;
    std::vector<float> vectorVertex;
    std::vector<unsigned int> vectorIndex;
    GLint modePolygon;
};

#endif // OPENGLVIEW_H
