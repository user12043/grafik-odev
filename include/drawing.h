//
// Created by user12043 on 23.11.2019.
//

#ifndef GL_ASSIGMENT_DRAWING_H
#define GL_ASSIGMENT_DRAWING_H

#include <GLFW/glfw3.h>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glad/glad.h>
#include "shader_program.h"

#define DRAW_COLOR_VAR "drawColor"

using glm::vec3;
using glm::vec4;

extern GLFWwindow *DEFAULT_WINDOW;

void initializeDrawing();

void drawTriangle(GLfloat *vertices, int count);

void drawCircle(GLfloat centerX, GLfloat centerY, int r);

void setForegroundColor(vec4 rgba);

void resetColor();

#endif //GL_ASSIGMENT_DRAWING_H
