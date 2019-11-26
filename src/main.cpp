#include <iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <vector>

#include "drawing.h"
#include "shader_program.h"

using std::cout;
using std::vector;

int main(int argc, char **argv) {
    initializeDrawing();
    while (!glfwWindowShouldClose(DEFAULT_WINDOW)) {
        drawStart();
        /**
         * draw here
         */
        drawEnd();
    }
    glfwTerminate();
    return 0;
}
