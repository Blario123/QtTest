#include <QTimer>
#include "OpenGLView.h"

const std::chrono::time_point<std::chrono::system_clock> startTime = std::chrono::system_clock::now();

OpenGLView::OpenGLView(QWidget *parent) : QOpenGLWidget(parent), vao(0), vbo(0), ebo(0) {
    vectorVertex = {
        -0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f,
        0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f,
        0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f
    };
    vectorIndex = {
        0, 1, 2,
        0, 2, 3,
        0, 1, 4,
        1, 2, 4,
        2, 3, 4,
        3, 0, 4
    };

    setFocusPolicy(Qt::StrongFocus);

    prog = nullptr;
    modePolygon = GL_FILL;
}

void OpenGLView::initializeGL() {
    initializeOpenGLFunctions();

    glEnable(GL_DEPTH_TEST);

    glViewport(0, 0, 800, 800);

    prog = new QOpenGLShaderProgram(this);
    prog->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shader.vs");
    prog->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shader.fs");

    prog->link();

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, static_cast<long>(vectorVertex.size() * sizeof(float)), &vectorVertex.front(), GL_STATIC_DRAW);

    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, static_cast<long>(vectorIndex.size() * sizeof(float)), &vectorIndex.front(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

void OpenGLView::paintGL() {
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPolygonMode(GL_FRONT_AND_BACK, modePolygon);

    prog->bind();

    glm::mat4 projection = glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f);
    glm::mat4 view = glm::mat4(1.0f);

    const auto currTime = std::chrono::system_clock::now();
    double time = (double) std::chrono::duration_cast<std::chrono::milliseconds>(currTime-startTime).count() / 1000;

    float radius = 5.0f;
    auto camX = static_cast<float>(sin(time) * radius);
    auto camZ = static_cast<float>(cos(time) * radius);

    view = glm::lookAt(glm::vec3(camX, 0.0f, camZ), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

    glm::mat4 model = glm::mat4(1.0f);

    float angle = 0.0f;
//    float angle = 20.0f;
    model = glm::rotate(model , glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));

    glUniformMatrix4fv(glGetUniformLocation(prog->programId(), "projection"), 1, GL_FALSE, glm::value_ptr(projection[0]));
    glUniformMatrix4fv(glGetUniformLocation(prog->programId(), "model"), 1, GL_FALSE, glm::value_ptr(model[0]));
    glUniformMatrix4fv(glGetUniformLocation(prog->programId(), "view"), 1, GL_FALSE, glm::value_ptr(view[0]));

    update();

    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, nullptr);
}

void OpenGLView::resizeGL(int width, int height) {
    glViewport(0, 0, width, height);
}

void OpenGLView::keyPressEvent(QKeyEvent *event) {

}
