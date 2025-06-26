struct VSOutput {
    float4 position : SV_POSITION;
    float3 color : COLOR;
};

VSOutput main(uint vertexID : SV_VertexID) {
    // Triangle positions in NDC space
    float2 positions[3] = {
        float2( 0.0f,  0.5f),   // Top
        float2( 0.5f, -0.5f),   // Bottom right
        float2(-0.5f, -0.5f)    // Bottom left
    };

    // Colors for each vertex
    float3 colors[3] = {
        float3(1.0f, 0.0f, 0.0f),  // Red
        float3(0.0f, 1.0f, 0.0f),  // Green
        float3(0.0f, 0.0f, 1.0f)   // Blue
    };

    VSOutput output;
    output.position = float4(positions[vertexID], 0.0f, 1.0f);
    output.color = colors[vertexID];
    return output;
}
