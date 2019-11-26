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
    GLfloat tAngle = 0.0f;
    while (!glfwWindowShouldClose(DEFAULT_WINDOW)) {
        drawStart();
        vector<vec3> verticesVec;
        verticesVec.emplace_back(-0.4f, 0.0f, 1.0f);
        verticesVec.emplace_back(0.4f, 0.0f, 1.0f);
        verticesVec.emplace_back(0.0f, 0.4f, 1.0f);
        setForegroundColor(vec4(0.0f, 0.0f, 1.0f, 1.0f));
        setRotation(rAngle);
        drawCircle(0.0f, 0.0f, 0.4f);
//        setTranslation(-0.3f, 0.4f);
        rAngle += 1.0f;
        tAngle -= 1.0f;
        setForegroundColor(vec4(0.0f, 1.0f, 1.0f, 1.0f));
//        setTranslation(0.4f, 0.4f);
        setScale(0.1f, 1.0f);
        setRotation(tAngle);
        drawTriangle(verticesVec);
        drawEnd();
    }
    glfwTerminate();
    return 0;
}
