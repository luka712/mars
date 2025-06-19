struct VSInput
{
    @location(0) position: vec3f,
    @location(1) color: vec4f,
    @location(2) texCoord: vec2f,
}

struct VSOutput {
    @builtin(position) position: vec4f,
    @location(1) color: vec4f,
    @location(2) texCoord: vec2f,
}

@group(0) @binding(0)
var<uniform> u_projectionView: mat4x4f;

@vertex
fn main_vs(
    in: VSInput,
) -> VSOutput
{
    var out : VSOutput;
    out.position = u_projectionView * vec4f(in.position, 1.0);
    out.color = in.color;
    out.texCoord = in.texCoord;

    return out;
}

@group(1) @binding(0)
var u_diffuseTexture: texture_2d<f32>;
@group(1) @binding(1)
var u_diffuseTexSampler: sampler;

@fragment
fn main_fs(in : VSOutput) -> @location(0) vec4f
{
    return textureSample(u_diffuseTexture, u_diffuseTexSampler, in.texCoord) * in.color;
}