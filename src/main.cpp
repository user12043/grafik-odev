#include <iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <vector>
#include <Snake.h>

#include "drawing.h"
#include "shader_program.h"

using std::cout;
using std::vector;


Snake snake;
bool paused = false;

void keyCallback(GLFWwindow *glfwWindow, int key, int scanCode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE) {
        glfwTerminate();
        exit(EXIT_SUCCESS);
    }
    if (action == GLFW_PRESS) {
        if (key == GLFW_KEY_UP) {
            snake.setDirection(DIRECTION_UP);
        }
        if (key == GLFW_KEY_DOWN) {
            snake.setDirection(DIRECTION_DOWN);
        }
        if (key == GLFW_KEY_RIGHT) {
            snake.setDirection(DIRECTION_RIGHT);
        }
        if (key == GLFW_KEY_LEFT) {
            snake.setDirection(DIRECTION_LEFT);
        }
        if (key == GLFW_KEY_SPACE) {
            snake.addCell();
        }
        if (key == GLFW_KEY_P) {
            paused = !paused;
        }
    }
}

int main(int argc, char **argv) {
    initializeDrawing();
    glfwSetKeyCallback(DEFAULT_WINDOW, keyCallback);
    while (!glfwWindowShouldClose(DEFAULT_WINDOW)) {
        drawStart();
        /**
         * draw here
         */
        if (!paused) {
            snake.step();
        }
        snake.draw();
        drawEnd();
    }
    glfwTerminate();
    return 0;
}
