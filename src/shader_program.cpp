//
// Created by user12043 on 22.11.2019.
//

/**
 * Muaz KARATAŞ - b161210039
 * Erkam BAYINDIR - b081210006
 */

#include "shader_program.h"
#include <iostream>
#include <fstream>

using std::ifstream;

string ShaderProgram::loadShaderFromFile(const char *fileName) {
    ifstream file(fileName);
    string content;

    if (file.is_open()) {
        char read;
        while ((read = file.get()) != EOF) {
            content += read;
        }
        file.close();
    }
    return content;
}

ShaderProgram::ShaderProgram() {
    programId = glCreateProgram();
}

/*ShaderProgram::~ShaderProgram() {
    std::cout << "isProgram: " << glIsProgram(programId) << std::endl;
    glDeleteProgram(programId);
}*/

void ShaderProgram::use() {
    glUseProgram(programId);
}

void ShaderProgram::link() {
    glLinkProgram(programId);
    int isLinked;
    char log[512];
    glGetProgramiv(programId, GL_LINK_STATUS, &isLinked);

    if (!isLinked) {
        glGetProgramInfoLog(programId, 512, nullptr, log);

        std::cerr << "Shader program linking error:" << std::endl << log << std::endl;
    }
}

void ShaderProgram::createAndAttachShader(const char *fileName, GLuint shaderType) {
    GLuint shaderId = glCreateShader(shaderType);
    string sourceCode = loadShaderFromFile(fileName);
    const char *chSourceCode = &sourceCode[0];
    glShaderSource(shaderId, 1, &chSourceCode, nullptr);
    glCompileShader(shaderId);
    int isCompiled;
    char log[512];
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &isCompiled);
    if (!isCompiled) {
        glGetShaderInfoLog(shaderId, 512, nullptr, log);
        string strType;
        switch (shaderType) {
            case GL_VERTEX_SHADER:
                strType = "Vertex Shader";
                break;
            case GL_FRAGMENT_SHADER:
                strType = "Fragment Shader";
                break;
            default:
                break;
        }
        std::cerr << "Shader Type:" << strType << std::endl << log << std::endl;
    }
    glAttachShader(programId, shaderId);
    glDeleteShader(shaderId);
}

GLuint ShaderProgram::addVariable(const GLchar *varName) {
    GLuint varId = glGetUniformLocation(programId, varName);
    variables[varName] = varId;
    return varId;
}

void ShaderProgram::setFloatVal(const GLchar *varName, GLfloat value) {
    glUniform1f(variables[varName], value);
}

void ShaderProgram::setVec3Val(const GLchar *varName, const vec3 &value) {
    glUniform3f(variables[varName], value.x, value.y, value.z);
}

void ShaderProgram::setVec4Val(const GLchar *varName, const vec4 &value) {
    glUniform4f(variables[varName], value.r, value.g, value.b, value.a);
}

void ShaderProgram::setMat3Val(const GLchar *varName, const mat3 *value) {
    glUniformMatrix3fv(variables[varName], 1, GL_FALSE, reinterpret_cast<const GLfloat *>(value));
}
