#version 450 core
layout (location = 0) in vec3 inPosition;
uniform mat3 transformVector;
void main() {
    gl_Position = vec4(transformVector * inPosition, 1.0);
}
