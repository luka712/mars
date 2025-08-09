//
// Created by Erkapic Luka on 9.8.2025.
//

#ifdef _WIN32

#ifndef DX11_TEXTURE_UTIL_H
#define DX11_TEXTURE_UTIL_H

#include <stdexcept>
#include "gpu_util/dx11.h"
#include "gpu_util/logger.h"

using namespace Microsoft::WRL;

namespace gpu_util {
    //! Utility class for creating and managing DirectX 11 textures.
    class DX11Texture2DUtil {
    public:

        //! Construct a new DX11TextureUtility object.
        //! @param logger The logger.
        explicit DX11Texture2DUtil(Logger &logger) : logger(logger) {
        }


        ComPtr<ID3D11Texture2D> create(
            ComPtr<ID3D11Device> device,
            ComPtr<ID3D11DeviceContext> context,
            const void *data,
            uint32_t width,
            uint32_t height,
            const DXGI_FORMAT format = DXGI_FORMAT_R8G8B8A8_UNORM,
            const D3D11_USAGE usage = D3D11_USAGE_DEFAULT,
            UINT bindFlags = D3D11_BIND_SHADER_RESOURCE,
            const std::string& label = ""
            );

    private:
        Logger &logger;
    };
}


#endif //DX11_TEXTURE_UTIL_H

#endif // _WIN32
