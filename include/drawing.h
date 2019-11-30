//
// Created by user12043 on 23.11.2019.
//

#ifndef GL_ASSIGMENT_DRAWING_H
#define GL_ASSIGMENT_DRAWING_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <vector>
#include "shader_program.h"

#define DRAW_COLOR_VAR "drawColor"
#define TRANSFORM_VECTOR_VAR "transformVector"
#define CIRCLE_DETAIL 12

using std::vector;
using glm::vec2;
using glm::vec3;
using glm::vec4;

struct Vertex {
    vec3 position;
    vec2 texture;
};

extern GLFWwindow *DEFAULT_WINDOW;

void drawStart();

void drawEnd();

void initializeDrawing();

void drawTriangle(Vertex *vertices, int count);

void drawTriangle(const vector<Vertex> &vertices);

void drawCircle(GLfloat centerX, GLfloat centerY, GLfloat radius);

void setForegroundColor(float r, float g, float b, float a);

void resetColor();

void setTranslation(GLfloat x, GLfloat y);

void setRotation(GLfloat degree);

void setScale(GLfloat scaleX, GLfloat scaleY);

void resetTransform();

void setAutoResetTransform(bool val);

#endif //GL_ASSIGMENT_DRAWING_H
