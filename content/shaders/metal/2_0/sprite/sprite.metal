#include <metal_stdlib>
using namespace metal;

// Vertex input structure
struct VertexIn {
    float3 position [[attribute(0)]];
    float4 color [[attribute(1)]];
    float2 texCoords [[attribute(2)]];
};

struct VertexOut {
    float4 position [[position]];
    float4 color;
    float2 texCoords;
};

// Hardcoded triangle positions and colors
vertex VertexOut main_vs(
    VertexIn in [[stage_in]]
    constant float4x4 u_projectionView [[buffer(1)]]
    ) {

    VertexOut out;
    out.position = u_projectionView * float4(in.position, 1.0);
    out.color = in.color;
    out.texCoords = in.texCoords;
    return out;
}



fragment float4 main_fs(
    VertexOut in [[stage_in]]
    texture2d<float> u_texture [[texture(0)]],
    sampler u_sampler [[sampler(0)]]
) {
    return u_texture.sample(u_sampler, in.texCoords, 0) * in.color;
}
