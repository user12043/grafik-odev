#include <iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include "drawing.h"
#include "shader_program.h"

using std::cout;

int main(int argc, char **argv) {
    initializeDrawing();
    while (!glfwWindowShouldClose(DEFAULT_WINDOW)) {
        float vertices[] = {
                -0.4f, 0.0f, 0.0f,
                0.4f, 0.0f, 0.0f,
                0.0f, 0.4f, 0.0f
        };
        drawTriangle(vertices, 1);
    }
    glfwTerminate();
    return 0;
}
