#version 300 es

precision highp float;
precision highp int;

layout(location = 0) in vec3 a_position;
layout(location = 1) in vec4 a_color;
layout(location = 2) in vec2 a_texCoord;

uniform mat4x4 u_projectionView;

smooth out vec4 v_color;
smooth out vec2 v_texCoord;

void main() {
    gl_Position = u_projectionView * vec4(a_position, 1.0);
    v_color = a_color;
    v_texCoord = a_texCoord;
    return;
}

