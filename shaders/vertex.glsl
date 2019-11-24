#version 450 core
layout (location = 0) in vec3 inPosition;
uniform vec3 moveVector;
void main() {
    gl_Position = vec4(inPosition + moveVector, 1.0);
}
