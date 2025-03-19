#version 300 es
precision mediump float;
precision highp int;

in highp vec4 v_color;

uniform vec4 u_color;

layout(location = 0) out highp vec4 o_outputColor;

void main()
{
    o_outputColor = u_color * v_color;
}

