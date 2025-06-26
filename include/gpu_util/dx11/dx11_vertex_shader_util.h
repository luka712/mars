//
// Created by Erkapic Luka on 26.6.2025.
//

#ifdef _WIN32

#ifndef DX11_VERTEX_SHADER_UTIL_H
#define DX11_VERTEX_SHADER_UTIL_H

#include "gpu_util/dx11.h"
#include "gpu_util/logger.h"

using namespace Microsoft::WRL;

namespace gpu_util {

    //! The utility class for working with DirectX 11 vertex shaders.
    class DX11VertexShaderUtil {
      public:
        //! Construct a new DX11VertexShaderUtil object.
        //! @param logger The logger.
        explicit DX11VertexShaderUtil(Logger &logger) : logger(logger) {
        }

        //! Creates a DirectX 11 vertex shader from the provided shader blob.
        //! @param device The DirectX 11 device.
        //! @param shaderBlob The compiled shader blob.
        //! @return A ComPtr to the created vertex shader.
        ComPtr<ID3D11VertexShader> create(
            ComPtr<ID3D11Device> device,
            ComPtr<ID3D10Blob> shaderBlob);

        private:
        Logger &logger;
      };

}

#endif //DX11_VERTEX_SHADER_UTIL_H

#endif // _WIN32