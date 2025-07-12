#include <metal_stdlib>
using namespace metal;

// Vertex input structure
struct VertexIn {
    float3 position [[attribute(0)]];
    float4 color [[attribute(1)]];
};
struct VertexOut {
    float4 position [[position]];
    float4 color;
};

// Hardcoded triangle positions and colors
vertex VertexOut main_vs(VertexIn in [[stage_in]]) {

    VertexOut out;
    out.position = float4(in.position, 1.0);
    out.color = in.color;
    return out;
}

fragment float4 main_fs(VertexOut in [[stage_in]]) {
    return in.color;
}
