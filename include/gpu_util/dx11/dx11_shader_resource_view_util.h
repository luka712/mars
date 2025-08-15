//
// Created by Erkapic Luka on 9.8.2025.
//

#ifdef _WIN32

#ifndef DX11_SHADER_RESOURCE_VIEW_UTIL_H
#define DX11_SHADER_RESOURCE_VIEW_UTIL_H

#include <dx11/dx11.h>
#include <string>
#include <gpu_util/logger.h>

using namespace Microsoft::WRL;

namespace gpu_util {

    //! Utility class for creating shader resource views in DirectX 11.
    class DX11ShaderResourceViewUtil {
    public:

        //! Construct a new DX11RenderTargetViewUtility object.
        //! @param logger The logger.
        explicit DX11ShaderResourceViewUtil(Logger &logger) : logger(logger) {
        }

        //! Creates a shader resource view for a texture.
        //! @param device The DirectX 11 device.
        //! @param texture The texture to create the shader resource view for.
        //! @param format The format of the shader resource view (default is DXGI_FORMAT_R8G8B8A8_UNORM).
        //! @param label Optional label for debugging purposes.
        //! @returns The created shader resource view.
        ComPtr<ID3D11ShaderResourceView> createTexure2DView(
            ComPtr<ID3D11Device> device,
            ComPtr<ID3D11Resource> texture,
            DXGI_FORMAT format = DXGI_FORMAT_R8G8B8A8_UNORM,
            const std::string& label = ""
        );

        private:
            Logger &logger;
    };

} // namespace gpu_util

#endif //DX11_SHADER_RESOURCE_VIEW_UTIL_H

#endif 
