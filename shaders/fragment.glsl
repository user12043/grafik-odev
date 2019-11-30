#version 450 core
out vec4 fragColor;
in vec2 textureCoordinate;

uniform vec4 drawColor;
uniform sampler2D textureVar;
void main() {
    fragColor = texture(textureVar, textureCoordinate);
}
