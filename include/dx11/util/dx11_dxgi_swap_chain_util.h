//
// Created by Erkapic Luka on 11.6.2025.
//

#ifdef _WIN32

#ifndef DX11_DXGI_SWAP_CHAIN_UTIL_H
#define DX11_DXGI_SWAP_CHAIN_UTIL_H

#include <stdexcept>
#include "core/log/Logger.h"
#include "dx11/dx11.h"

using namespace Microsoft::WRL;

namespace mars {
    //! Utility class for creating and managing DirectX 11 swap chains.
    class DX11DxgiSwapChainUtil {
    public:
        //! Construct a new DX11DxgiDeviceUtil object.
        //! @param logger The logger.
        explicit DX11DxgiSwapChainUtil(Logger &logger) : logger(logger) {
        }

        //! Create a DXGI device.
    	//! @param factory The DXGI factory to use for creating the swap chain.
        //! @param device The DirectX 11 device to associate with the swap chain.
    	//! @param hwnd The window handle to associate with the swap chain.
        //! @param format The format of the swap chain buffers (default is DXGI_FORMAT_R8G8B8A8_UNORM).
        //! @param bufferCount The number of buffers in the swap chain (default is 2).
        //! @param swapEffect The swap effect to use (default is DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL).
        //! @return The created DXGI device.
        ComPtr<IDXGISwapChain1> create(
            const ComPtr<IDXGIFactory2>& factory,
            const ComPtr<ID3D11Device>& device,
            HWND hwnd,
            const DXGI_FORMAT format = DXGI_FORMAT_R8G8B8A8_UNORM,
            const uint32_t bufferCount = 2,
            const DXGI_SWAP_EFFECT swapEffect = DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL);

        //! Get the back buffer texture from the swap chain.
        //! @param swapChain The swap chain to get the back buffer from.
        //! @return The back buffer texture as a ComPtr to ID3D11Texture2D.
        ComPtr<ID3D11Texture2D> getBackBuffer(ComPtr<IDXGISwapChain1> swapChain);

    private:
        Logger &logger;
    };
}

#endif //DX11_DXGI_SWAP_CHAIN_UTIL_H

#endif
