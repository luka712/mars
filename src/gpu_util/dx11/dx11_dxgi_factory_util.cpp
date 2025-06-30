//
// Created by Erkapic Luka on 27.5.2025.
//

#ifdef _WIN32

#include "gpu_util/dx11/dx11_dxgi_factory_util.h"
#include <stdexcept>

namespace gpu_util {
    Microsoft::WRL::ComPtr<IDXGIFactory2> DX11DxgiFactoryUtil::create() {
        Microsoft::WRL::ComPtr<IDXGIFactory2> factory;
        HRESULT hr = CreateDXGIFactory(__uuidof(IDXGIFactory2), reinterpret_cast<void**>(factory.GetAddressOf()));
        if (FAILED(hr)) {
            std::string msg = "DXGIFactoryUtil::create: Failed to create DXGIFactory. HRESULT: " + std::to_string(hr);
            logger.error(msg);
            throw std::runtime_error(msg);
        }
        return factory;
    }

}

#endif