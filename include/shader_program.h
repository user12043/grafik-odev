//
// Created by user12043 on 22.11.2019.
//

#ifndef GL_ASSIGMENT_SHADER_PROGRAM_H
#define GL_ASSIGMENT_SHADER_PROGRAM_H

#include <glad/glad.h>
#include <string>

using std::string;

class ShaderProgram {
private:
    GLuint programId;

    static string loadShaderFromFile(const char *fileName);

public:
    ShaderProgram();

    ~ShaderProgram() = default;

    void use();

    void link();

    void createAndAttachShader(const char *fileName, GLuint shaderType);
};

#endif //GL_ASSIGMENT_SHADER_PROGRAM_H
