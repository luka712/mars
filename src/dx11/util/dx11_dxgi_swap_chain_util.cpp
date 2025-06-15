//
// Created by Erkapic Luka on 11.6.2025.
//

#ifdef _WIN32

#include "dx11/util/dx11_dxgi_swap_chain_util.h"
#include <stdexcept>

namespace mars {

    ComPtr<IDXGISwapChain1> DX11DxgiSwapChainUtil::create(
        const ComPtr<IDXGIFactory2>& factory,
        const ComPtr<ID3D11Device>& device,
        HWND hwnd,
        const DXGI_FORMAT format,
        const uint32_t bufferCount,
        const DXGI_SWAP_EFFECT swapEffect) {
        ComPtr<IDXGISwapChain1> swapChain;

        DXGI_SWAP_CHAIN_DESC1 swapChainDesc = {};
        swapChainDesc.BufferCount = bufferCount;
        swapChainDesc.SwapEffect = swapEffect;
        swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        swapChainDesc.Format = format;
        swapChainDesc.SampleDesc.Count = 1; // No multisampling
        swapChainDesc.SampleDesc.Quality = 0; // No multisampling

        HRESULT hr = factory->CreateSwapChainForHwnd(
            dynamic_cast<IUnknown*>(device.Get()),
            hwnd,
            &swapChainDesc,
            nullptr,
            nullptr,
            swapChain.GetAddressOf());

        if (FAILED(hr)) {
            std::string msg = "DX11DxgiSwapChainUtil::create: Failed to create swap chain. HRESULT: " +
                std::to_string(hr);
            logger.error(msg);
            throw std::runtime_error(msg);
        }

        return swapChain;
    }

    ComPtr<ID3D11Texture2D> DX11DxgiSwapChainUtil::getBackBuffer(ComPtr<IDXGISwapChain1> swapchain) {

		ComPtr<ID3D11Texture2D> backBuffer;
		HRESULT hr = swapchain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(backBuffer.GetAddressOf()));
		if (FAILED(hr)) {
			std::string msg = "DX11DxgiSwapChainUtil::getBackBuffer: Failed to get back buffer. HRESULT: " + std::to_string(hr);
			logger.error(msg);
			throw std::runtime_error(msg);
		}
		return backBuffer;
    }

} // namespace mars

#endif
