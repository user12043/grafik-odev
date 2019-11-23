//
// Created by user12043 on 23.11.2019.
//

#include <iostream>
#include <cstdlib>
#include <glad/glad.h>
#include "drawing.h"
#include "shader_program.h"

using std::cout;

GLFWwindow *DEFAULT_WINDOW;
static vec4 DEFAULT_COLOR;
static vec4 DRAW_COLOR;
static GLuint vertexBufferObject;
static GLuint vertexArrayObject;
static GLuint indexBufferObject;
static ShaderProgram *program;

void clearBuffer() {
    glClearColor(1.0f - DEFAULT_COLOR.r,
                 1.0f - DEFAULT_COLOR.g,
                 1.0f - DEFAULT_COLOR.b,
                 1.0f - DEFAULT_COLOR.a
    );
    glClear(GL_COLOR_BUFFER_BIT);
}

void drawEnd() {
    glfwSwapBuffers(DEFAULT_WINDOW);
    glfwPollEvents();
}

void initializeWindow() {
    if (!glfwInit()) {
        exit(-1);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    DEFAULT_WINDOW = glfwCreateWindow(800, 800, "glAssigment", nullptr, nullptr);

    if (DEFAULT_WINDOW == nullptr) {
        std::cerr << "Can not initialize window object!\n";
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(DEFAULT_WINDOW);
}

void initializeGl() {
    // Glad
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cerr << "Can not initialize glad!\n";
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // shader program
    ShaderProgram pr;
    program = &pr;
    program->createAndAttachShader("./shaders/vertex.glsl", GL_VERTEX_SHADER);
    program->createAndAttachShader("./shaders/fragment.glsl", GL_FRAGMENT_SHADER);
    program->link();
    program->use();

    program->addVariable(DRAW_COLOR_VAR);

    // set default color
    DEFAULT_COLOR = vec4(0.1f, 0.5f, 0.7f, 1.0f);
    program->setVec4Val(DRAW_COLOR_VAR, vec4(
            DEFAULT_COLOR.r,
            DEFAULT_COLOR.g,
            DEFAULT_COLOR.b,
            DEFAULT_COLOR.a)
    );

    // array, buffer
    glGenVertexArrays(1, &vertexArrayObject);
    glGenBuffers(1, &vertexBufferObject);
    glGenBuffers(1, &indexBufferObject);

    glBindVertexArray(vertexArrayObject);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, nullptr);
//    glEnableVertexAttribArray(0);
}

void initializeDrawing() {
    initializeWindow();
    initializeGl();
}

void drawTriangle(GLfloat *vertices, int count) {
    clearBuffer();
    glBufferData(GL_ARRAY_BUFFER, count * 36, vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, nullptr);
    glEnableVertexAttribArray(0);
    glDrawArrays(GL_TRIANGLES, 0, count * 3);
    drawEnd();
}

/*void drawCircle(GLfloat centerX, GLfloat centerY, int r) {

}*/

void setForegroundColor(vec4 rgba) {
    program->setVec4Val(DRAW_COLOR_VAR, rgba);
    DRAW_COLOR = rgba;
}

void resetColor() {
    program->setVec4Val(DRAW_COLOR_VAR, DEFAULT_COLOR);
}
