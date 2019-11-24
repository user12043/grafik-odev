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
    GLfloat rAngle = 0.0f;
    while (!glfwWindowShouldClose(DEFAULT_WINDOW)) {
        drawStart();
        vector<vec3> verticesVec;
        verticesVec.emplace_back(-0.4f, 0.0f, 0.0f);
        verticesVec.emplace_back(0.4f, 0.0f, 0.0f);
        verticesVec.emplace_back(0.0f, 0.4f, 0.0f);
        setForegroundColor(vec4(0.0f, 0.0f, 1.0f, 1.0f));
        drawCircle(0.0f, 0.0f, 0.4f);
        setRotation(rAngle);
        rAngle += 1.0f;
        setForegroundColor(vec4(0.0f, 1.0f, 1.0f, 1.0f));
        drawTriangle(verticesVec);
        drawEnd();
    }
    glfwTerminate();
    return 0;
}
