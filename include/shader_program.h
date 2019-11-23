//
// Created by user12043 on 22.11.2019.
//

#ifndef GL_ASSIGMENT_SHADER_PROGRAM_H
#define GL_ASSIGMENT_SHADER_PROGRAM_H

#include <glad/glad.h>
#include <string>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <map>

using std::string;
using std::map;
using glm::vec3;
using glm::vec4;

class ShaderProgram {
private:
    GLuint programId;

    static string loadShaderFromFile(const char *fileName);

    map<const char *, GLuint> variables;

public:
    ShaderProgram();

    ~ShaderProgram() = default;

    void use();

    void link();

    void createAndAttachShader(const char *fileName, GLuint shaderType);

    GLuint addVariable(const GLchar *varName);

    void setFloatVal(const GLchar *varName, GLfloat value);

    void setVec3Val(const GLchar *varName, const vec3 &value);

    void setVec4Val(const GLchar *varName, const vec4 &value);
};

#endif //GL_ASSIGMENT_SHADER_PROGRAM_H
