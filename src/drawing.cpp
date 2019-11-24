//
// Created by user12043 on 23.11.2019.
//

#include <iostream>
#include <cstdlib>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include "drawing.h"
#include "shader_program.h"

using std::cout;

GLFWwindow *DEFAULT_WINDOW;
static vec4 DEFAULT_COLOR;
static vec4 DRAW_COLOR;
static ShaderProgram *program;

void clearBuffer() {
    glClearColor(1.0f,
                 1.0f,
                 1.0f,
                 1.0f
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
    program = new ShaderProgram;
    program->createAndAttachShader("./shaders/vertex.glsl", GL_VERTEX_SHADER);
    program->createAndAttachShader("./shaders/fragment.glsl", GL_FRAGMENT_SHADER);
    program->link();
    program->use();

    program->addVariable(DRAW_COLOR_VAR);
    program->addVariable(TRANSFORM_VECTOR_VAR);

    // set default color
    DEFAULT_COLOR = vec4(0.1f, 0.5f, 0.7f, 1.0f);
    program->setVec4Val(DRAW_COLOR_VAR, vec4(
            DEFAULT_COLOR.r,
            DEFAULT_COLOR.g,
            DEFAULT_COLOR.b,
            DEFAULT_COLOR.a)
    );

    // set default move to 0
    program->setVec3Val(TRANSFORM_VECTOR_VAR, vec3(0.0f, 0.0f, 0.0f));

    GLuint vertexBufferObject;
    GLuint vertexArrayObject;
    GLuint indexBufferObject;

    // array, buffer
    glGenVertexArrays(1, &vertexArrayObject);
    glGenBuffers(1, &vertexBufferObject);
    glGenBuffers(1, &indexBufferObject);

    glBindVertexArray(vertexArrayObject);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferObject);


    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 3, nullptr);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, nullptr);
    glEnableVertexAttribArray(0);
}

void initializeDrawing() {
    initializeWindow();
    initializeGl();
}

void drawTriangle(GLfloat *vertices, int count) {
    clearBuffer();
    program->setVec3Val(TRANSFORM_VECTOR_VAR, vec3(0.0f, 0.0f, 0.0f));
    glBufferData(GL_ARRAY_BUFFER, count * 36, vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 3, nullptr);
    glEnableVertexAttribArray(0);
    glDrawArrays(GL_TRIANGLES, 0, count * 3);
    drawEnd();
}


void drawTriangle(const vector<vec3> &vertices) {
    clearBuffer();
    program->setVec3Val(TRANSFORM_VECTOR_VAR, vec3(0.0f, 0.0f, 0.0f));
    glBufferData(GL_ARRAY_BUFFER, sizeof(vec3) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glDrawArrays(GL_TRIANGLES, 0, vertices.size());
    drawEnd();
}

void drawCircle(GLfloat centerX, GLfloat centerY, GLfloat radius) {
    clearBuffer();
    int verticesNumber = 4 * CIRCLE_DETAIL;
    int trianglesNumber = verticesNumber - 2;
    GLfloat unitAngle = 360.0f / (GLfloat) verticesNumber;

    vector<vec3> vertices;
    // place vertices
    for (int a = 0; a < verticesNumber; ++a) {
        vec3 nexPosition;
        GLfloat currentAngle = unitAngle * (GLfloat) a;
        const GLfloat currentAngleRadian = glm::radians(currentAngle);
        nexPosition.x = radius * glm::cos(currentAngleRadian);
        nexPosition.y = radius * glm::sin(currentAngleRadian);
        nexPosition.z = 0.0f;
        vertices.emplace_back(nexPosition);
    }

    // place indices
    vector<GLuint> indices;
    for (int a = 0; a < trianglesNumber; ++a) {
        indices.emplace_back(0);
        indices.emplace_back(a + 1);
        indices.emplace_back(a + 2);
    }

    // set move position
    program->setVec3Val(TRANSFORM_VECTOR_VAR, vec3(centerX, centerY, 0.0f));

    glBufferData(GL_ARRAY_BUFFER, sizeof(vec3) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &indices[0], GL_STATIC_DRAW);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, nullptr);
    drawEnd();
}

void setForegroundColor(vec4 rgba) {
    program->setVec4Val(DRAW_COLOR_VAR, rgba);
    DRAW_COLOR = rgba;
}

void resetColor() {
    program->setVec4Val(DRAW_COLOR_VAR, DEFAULT_COLOR);
}
