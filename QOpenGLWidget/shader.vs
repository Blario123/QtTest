#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec4 vertexOut;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main(void) {
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    vertexOut = vec4(aColor, 1.0);
}
