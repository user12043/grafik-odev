#version 450 core
layout (location = 0) in vec3 inPosition;
layout (location = 1) in vec2 inTextureCoordinate;

uniform mat3 transformVector;
out vec2 textureCoordinate;
void main() {
    gl_Position = vec4(transformVector * inPosition, 1.0);
    textureCoordinate = inTextureCoordinate;
}
