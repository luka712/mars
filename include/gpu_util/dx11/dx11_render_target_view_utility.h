//
// Created by Erkapic Luka on 12.6.2025.
//

#ifdef _WIN32

#ifndef DX11_RENDER_TARGET_VIEW_UTILITY_H
#define DX11_RENDER_TARGET_VIEW_UTILITY_H

#include <stdexcept>
#include "gpu_util/dx11.h"
#include "gpu_util/logger.h"

using namespace Microsoft::WRL;

namespace gpu_util {
    //! Utility class for creating and managing DirectX 11 render target views.
    class DX11RenderTargetViewUtility {
    public:

        //! Construct a new DX11RenderTargetViewUtility object.
        //! @param logger The logger.
        explicit DX11RenderTargetViewUtility(Logger &logger) : logger(logger) {
        }

        //! Create a render target view for the given texture.
        //! @param device The DirectX 11 device.
        //! @param texture The texture to create the render target view for.
        //! @param format The format of the render target view (default is DXGI_FORMAT_R8G8B8A8_UNORM).
        //! @return The created ID3D11RenderTargetView.
        ComPtr<ID3D11RenderTargetView> createRenderTargetView(
            ComPtr<ID3D11Device> device,
            ComPtr<ID3D11Texture2D> texture,
            const DXGI_FORMAT format = DXGI_FORMAT_R8G8B8A8_UNORM);

        private:
            Logger &logger;
    };
}

#endif //DX11_RENDER_TARGET_VIEW_UTILITY_H

#endif // _WIN32