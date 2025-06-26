//
// Created by Erkapic Luka on 26.6.2025.
//

#ifdef _WIN32


#ifndef DX11_PIXEL_SHADER_UTIL_H
#define DX11_PIXEL_SHADER_UTIL_H

#include "gpu_util/dx11.h"
#include "gpu_util/logger.h"

using namespace Microsoft::WRL;

namespace gpu_util {

    //! The utility class for working with DirectX 11 pixel shaders.
    class DX11PixelShaderUtil {
    public:
        //! Construct a new DX11PixelShaderUtil object.
        //! @param logger The logger.
        explicit DX11PixelShaderUtil(Logger &logger) : logger(logger) {
        }

        //! Creates a DirectX 11 pixel shader from the provided shader blob.
        //! @param device The DirectX 11 device.
        //! @param shaderBlob The compiled shader blob.
        //! @return A ComPtr to the created pixel shader.
        ComPtr<ID3D11PixelShader> create(
            ComPtr<ID3D11Device> device,
            ComPtr<ID3D10Blob> shaderBlob);

    private:
        Logger &logger;
    };

}

#endif //DX11_PIXEL_SHADER_UTIL_H

#endif