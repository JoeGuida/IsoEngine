#version 330 core

layout (location = 0) in vec3 position;

out vec3 vertex_color;

uniform vec3 color;
uniform mat4 model;
uniform mat4 projection;

void main() {
    gl_Position = projection * model * vec4(position, 1.0);
    vertex_color = color;
}