#include <iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include "shader_program.h"

float vertices[] = {
        -0.6f, -0.6f, 0.0f,
        0.6f, -0.6f, 0.0f,
        0.0f, 0.6f, 0.0f
};

GLuint vbo;
GLuint vao;

int main(int argc, char **argv) {
    std::cout << "Goodbye, World!" << std::endl;
    if (!glfwInit()) {
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

    GLFWwindow *window = glfwCreateWindow(800, 800, "glAssigment", nullptr, nullptr);

    if (window == nullptr) {
        std::cerr << "Can not initialize window object!\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cerr << "Can not initialize glad!\n";
        glfwTerminate();
        return -1;
    }

    ShaderProgram program;
    program.createAndAttachShader("./shaders/vertex.glsl", GL_VERTEX_SHADER);
    program.createAndAttachShader("./shaders/fragment.glsl", GL_FRAGMENT_SHADER);
    program.link();

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, nullptr);
    glEnableVertexAttribArray(0);


    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.0f, 0.4f, 0.7f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        program.use();
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}
