
#include "OpenGLView.h"

OpenGLView::OpenGLView(QOpenGLWidget *parent) : QOpenGLWidget(parent), shader(nullptr), frameCount(5000) {
    vertexColours = {
            QColor(0xf6, 0xa5, 0x09),
            QColor(0xcb, 0x2d, 0xde),
            QColor(0x0e, 0xee, 0xd1),
            QColor(0x06, 0x89, 0x18)
    };
    timer.start();
    QTimer::singleShot(1000, this, &OpenGLView::updateColor);
}

QSize OpenGLView::sizeHint() const {
    return {640, 480};
}

OpenGLView::~OpenGLView() {
    makeCurrent();

    doneCurrent();
}

void OpenGLView::initializeGL() {
    initializeOpenGLFunctions();

    glEnable(GL_DEPTH_TEST);

    shader = new QOpenGLShaderProgram;

    if(!shader->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shader.vs")) {
        qDebug() << "Vertex shader failed to load\n" << shader->log();
    }
    if(!shader->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shader.fs")) {
        qDebug() << "Fragment shader failed to load\n" << shader->log();
    }
    if(!shader->link()) {
        qDebug() << "Shader failed to link\n" << shader->log();
    }

    float vertices[] = {
            -0.5, 0.5, 0.0, // 0
            0.5, 0.5, 0.0, // 1
            0.5, -0.5, 0.0, // 2
            -0.5, -0.5, 0.0, // 3
            0.0, 0.0, 1.0, // 4

    };

    vertexBufferData.resize(2 * 4 * 3);

    float * buf = vertexBufferData.data();
    for(int i = 0; i < 4; ++i, buf += 6) {
        buf[0] = vertices[3*i];
        buf[1] = vertices[3*i+1];
        buf[2] = vertices[3*i+2];
        buf[3] = vertexColours[i].redF();
        buf[4] = vertexColours[i].greenF();
        buf[5] = vertexColours[i].blueF();
    }

    vertexBufferObject =  QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    vertexBufferObject.create();
    vertexBufferObject.setUsagePattern(QOpenGLBuffer::StaticDraw);
    vertexBufferObject.bind();
    vertexBufferObject.allocate(vertexBufferData.data(), vertexBufferData.size()*sizeof(float));

    vao.create();
    vao.bind();

    uint indices[] = {
        0, 1, 3,
        1, 2, 3,
        0, 4, 1,
        1,  4, 2,
        2, 4, 3,
        3, 4, 0
    };

    indexBuffer = QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);
    indexBuffer.create();
    indexBuffer.setUsagePattern(QOpenGLBuffer::StaticDraw);
    indexBuffer.bind();
    indexBuffer.allocate(indices, sizeof(indices));

    int stride = 6 * sizeof(float);

    shader->enableAttributeArray(0);
    shader->setAttributeBuffer(0, GL_FLOAT, 0, 3, stride);
    shader->enableAttributeArray(1);
    int colorOffset = 3 * sizeof(float);
    shader->setAttributeBuffer(1, GL_FLOAT, colorOffset, 3, stride);
}

void OpenGLView::resizeGL(int w, int h) {
    if(h == 0) {
        h = 1;
    }

    glViewport(0, 0, w, h);
}

void OpenGLView::paintGL() {
    glClearColor(0.1, 0.1, 0.2, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::mat4 projection = glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f);

    shader->setUniformValue(shader->uniformLocation("projection"), QMatrix4x4(glm::value_ptr(projection)).transposed());

    glm::mat4 view = glm::mat4(1.0f);

    float radius = 5.0f;
    auto camX = static_cast<float>(sin(timer.elapsed()) * radius);
    auto camZ = static_cast<float>(cos(timer.elapsed()) * radius);

    view = glm::lookAt(glm::vec3(camX, 0.0f, camZ), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

    shader->setUniformValue(shader->uniformLocation("view"), QMatrix4x4(glm::value_ptr(view)).transposed());

    glm::mat4 model = glm::mat4(1.0f);
    float angle = 20.0f;
    model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));

    shader->setUniformValue(shader->uniformLocation("model"), QMatrix4x4(glm::value_ptr(model)).transposed());
    shader->bind();
    vao.bind();


    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
    vao.release();

    animate();
}

void OpenGLView::animate() {
    const unsigned int FRAMECOUNT = 120;
    if(++frameCount > FRAMECOUNT) {
        return;
    }

    double alpha = double(frameCount)/FRAMECOUNT;

    for(unsigned int i = 0; i < vertexColours.size(); ++i) {
        float fromH, fromS, fromV;
        fromColors[i].getHsvF(&fromH, &fromS, &fromV);
        float toH, toS, toV;
        toColors[i].getHsvF(&toH, &toS, &toV);
        vertexColours[i] = QColor::fromHsvF(toH*alpha + fromH*(1-alpha), toS*alpha + fromS*(1-alpha), toV*alpha + fromV*(1-alpha));
    }
    updateScene();
}

void OpenGLView::animateColorsTo(const std::vector<QColor> &toColor) {
    fromColors = vertexColours;
    toColors = toColor;
    frameCount = 0;

    animate();
}

void OpenGLView::updateColor() {
    std::vector<QColor> to;
    to.emplace_back(0x01, 0x04, 0xf6);
    to.emplace_back(0xf6, 0x04, 0xf6);
    to.emplace_back(0xf6, 0x04, 0x01);
    to.emplace_back(0x01, 0xf6, 0xf6);
    this->animateColorsTo(to);
}

void OpenGLView::updateScene() {
    float * buf = vertexBufferData.data();
    for(int i = 0; i < 4; ++i, buf+=6) {
        buf[3] = vertexColours[i].redF();
        buf[4] = vertexColours[i].greenF();
        buf[5] = vertexColours[i].blueF();
    }

    makeCurrent();

    vertexBufferObject.bind();
    vertexBufferObject.allocate(vertexBufferData.data(), vertexBufferData.size()*sizeof(float));

    update();
}
