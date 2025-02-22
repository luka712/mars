//
// Created by lukaa on 2.1.2025..
//

#ifndef RENDERER_ENUMS_H
#define RENDERER_ENUMS_H

namespace mars {
    //! The RenderingBackend enum.
    //! Represents the different rendering API backends.
    enum class RenderingBackend {
        //! If none is set, the default is WebGPU.
        None = 0,
        OpenGL,
        OpenGLES,
        D3D11,
        D3D12,
        Vulkan,
        Metal,
        WebGPU,
        //! The SDL renderer.
        //! For testing only.
        SDL
    };

    //! The culling mode.
    enum class Culling {
        None = 0,
        Back,
        Front
    };

    //! The vertex format. Used to describe the format of a vertex attribute.
    enum class VertexFormat {
        Float32x1 = 0,
        Float32x2 = 1,
        Float32x3 = 2,
        Float32x4 = 3,

        //! The format of a 32-bit float with 16 components. Used for matrix attributes.
        Float32x16 = 15
    };
}

#endif //RENDERER_ENUMS_H
