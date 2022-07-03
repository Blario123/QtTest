#version 330 core

out vec4 fragColor;

in vec4 vertexOut;

void main(void) {
    fragColor = vertexOut;
}