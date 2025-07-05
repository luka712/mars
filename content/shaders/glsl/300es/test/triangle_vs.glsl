#version 300 es
precision mediump float;

out vec3 vColor;

void main() {
    // Define a triangle in normalized device coordinates using gl_VertexID
    vec2 positions[3];
    positions[0] = vec2(0.0, 0.5);   // top
    positions[1] = vec2(-0.5, -0.5); // bottom-left
    positions[2] = vec2(0.5, -0.5);  // bottom-right

    vec3 colors[3];
    colors[0] = vec3(1.0, 0.0, 0.0); // red
    colors[1] = vec3(0.0, 1.0, 0.0); // green
    colors[2] = vec3(0.0, 0.0, 1.0); // blue

    gl_Position = vec4(positions[gl_VertexID], 0.0, 1.0);
    vColor = colors[gl_VertexID];
}
