#version 300 es

precision highp float;
precision highp int;

uniform highp sampler2D u_texture;

smooth in vec4 v_color;
smooth in vec2 v_texCoords;

layout(location = 0) out vec4 o_position;

void main() {
    o_position = texture(u_texture, vec2(v_texCoords)) * v_color;
    return;
}

