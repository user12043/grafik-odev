#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

char *vertexShaderSource = "#version 330 core\n"
                           "layout(location = 0) in vec3 position;\n"
                           "\n"
                           "void main() {\n"
                           "    gl_Position = vec4(position, 1.0);\n"
                           "}";

char *fragmentShaderSource = "#version 330 core\n"
                             "\n"
                             "out vec4 fragColor;\n"
                             "\n"
                             "void main() {\n"
                             "    fragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);\n"
                             "}";
float vertices[] = {
        -0.5f, -0.3f, 0.0f,
        -0.0f, 0.4f, 0.0f,
        0.5f, -0.3f, 0.0f
};
id_t vao;
id_t vbo;

int main(int argc, char **argv) {
    std::cout << "Goodbye, World!" << std::endl;

//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

//    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

    if (!glfwInit()) {
        return -1;
    }

    GLFWwindow *window = glfwCreateWindow(800, 600, "glAssigment", nullptr, nullptr);
    if (window == nullptr) {
        std::cerr << "Can not initialize window object!\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cerr << "Can not initialize glad!\n";
        glfwTerminate();
        return -1;
    }

    // create shaders
    id_t vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShaderId, 1, &vertexShaderSource, nullptr);
    glCompileShader(vertexShaderId);

    id_t fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShaderId, 1, &fragmentShaderSource, nullptr);
    glCompileShader(fragmentShaderId);

    // create program
    id_t programId = glCreateProgram();
    glAttachShader(programId, vertexShaderId);
    glAttachShader(programId, fragmentShaderId);
    glLinkProgram(programId);

    // VAO and VBO
    glGenVertexArrays(1, &vao);

    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);


    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void *) nullptr);
    glEnableVertexAttribArray(0);

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.0f, 0.0f, 0.7f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(programId);
        glBindVertexArray(vao);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}