#version 330 core

in vec2 vertex_tex_coords;

out vec4 FragColor;

uniform sampler2D tex;

void main() {
    FragColor = texture(tex, vertex_tex_coords);
}