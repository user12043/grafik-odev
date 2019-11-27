#include <iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <vector>
#include <Snake.h>

#include "drawing.h"
#include "shader_program.h"

using std::cout;
using std::vector;

int main(int argc, char **argv) {
    initializeDrawing();
    Snake snake;
    snake.addCell();
    snake.addCell();
    snake.setDirection(DIRECTION_RIGHT);
    while (!glfwWindowShouldClose(DEFAULT_WINDOW)) {
        drawStart();
        /**
         * draw here
         */
        snake.draw();
        snake.step();
        drawEnd();
    }
    glfwTerminate();
    return 0;
}
