//
// Created by Erkapic Luka on 27.5.2025.
//

#if ALLOW_DX11

#include "dx11/util/dx11_dxgi_factory_util.h"

namespace mars {
    Microsoft::WRL::ComPtr<IDXGIFactory1> DX11DxgiFactoryUtil::create() {
        Microsoft::WRL::ComPtr<IDXGIFactory1> factory;
        HRESULT hr = CreateDXGIFactory1(__uuidof(IDXGIFactory), reinterpret_cast<void**>(factory.GetAddressOf()));
        if (FAILED(hr)) {
            std::string msg = "DXGIFactoryUtil::create: Failed to create DXGIFactory. HRESULT: " + std::to_string(hr);
            logger.error(msg);
            throw std::runtime_error(msg);
        }
        return factory;
    }

}

#endif