#version 300 es

precision highp float;
precision highp int;

uniform highp sampler2D u_diffuseTexture;

smooth in vec4 v_color;
smooth in vec2 v_texCoord;

layout(location = 0) out vec4 o_position;

void main() {
    o_position = texture(u_diffuseTexture, vec2(v_texCoord)) + v_color;
    return;
}

