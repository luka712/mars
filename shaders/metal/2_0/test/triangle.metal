#include <metal_stdlib>
using namespace metal;

struct VertexOut {
    float4 position [[position]];
    float4 color;
};

// Hardcoded triangle positions and colors
vertex VertexOut main_vs(uint vertex_id [[vertex_id]]) {
    float4 positions[3] = {
        float4( 0.0,  0.5, 0.0, 1.0),  // Top
        float4(-0.5, -0.5, 0.0, 1.0),  // Bottom Left
        float4( 0.5, -0.5, 0.0, 1.0)   // Bottom Right
    };

    float4 colors[3] = {
        float4(1.0, 0.0, 0.0, 1.0), // Red
        float4(0.0, 1.0, 0.0, 1.0), // Green
        float4(0.0, 0.0, 1.0, 1.0)  // Blue
    };

    VertexOut out;
    out.position = positions[vertex_id];
    out.color = colors[vertex_id];
    return out;
}

fragment float4 main_fs(VertexOut in [[stage_in]]) {
    return in.color;
}
