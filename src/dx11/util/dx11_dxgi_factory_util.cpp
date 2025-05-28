//
// Created by Erkapic Luka on 27.5.2025.
//

#include "dx11/util/dx11_dxgi_factory_util.h"

namespace mars {
    Microsoft::WRL::ComPtr<IDXGIFactory1> DX11DxgiFactoryUtil::createFactory() {
        Microsoft::WRL::ComPtr<IDXGIFactory1> factory;
        HRESULT hr = CreateDXGIFactory1(__uuidof(IDXGIFactory), reinterpret_cast<void**>(factory.GetAddressOf()));
        if (FAILED(hr)) {
            std::string msg = "DXGIFactoryUtil::createFactory: Failed to create DXGI Factory. HRESULT: " + std::to_string(hr);
            logger.error(msg);
            throw std::runtime_error(msg);
        }
        return factory;
    }

}