//
// Created by lukaa on 22.12.2024..
//

#ifndef TEXTUREENUMS_H
#define TEXTUREENUMS_H

namespace mars {

    //! The usage of the texture.
    enum class TextureUsage {

        //! Can be used in case where it's not relevant, such as in OpenGL.
        None,

        //! Texture can be read from but has no other usages.
        //! Corresponds to WGPU_COPY_SRC in WebGPU.
        //! In D3D11 can be translated to following properties:
        //! - D3D11_BIND_SHADER_RESOURCE
        //! - D3D11_USAGE_STAGING
        //! - D3D11_BIND_FLAG_NONE
        CopySrc,

        //! The texture is used as a destination for copying.
        //! Corresponds to WGPU_COPY_DST in WebGPU.
        CopyDst,

        //! The texture is used as a source for texture binding.
        //! Can be read in shader.
        /// Corresponding binding in D3D11 is D3D11_BIND_SHADER_RESOURCE.
        TextureBinding,

        //! Combination of CopySrc and CopyDst.
        CopyDst_TextureBinding,
    };

    //! The texture format.
    enum class TextureFormat {
        //! Ordinary format with four 8-bit normalized unsigned integer components in RGBA order.
        RGBA_8_Unorm,

        //! Ordinary format with four 8-bit normalized unsigned integer components in BGRA order.
        BGRA_8_Unorm,

        //! Ordinary format with four 8-bit normalized unsigned integer components in BGRA order. Uses sRGB color space.
        BGRA_8_Unorm_sRGB,

        //! Depth 24 and stencil 8.
        Depth_24_Stencil_8,
    };
}

#endif //TEXTUREENUMS_H
