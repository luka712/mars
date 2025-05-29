//
// Created by Erkapic Luka on 29.5.2025.
//

//
// Created by Erkapic Luka on 27.5.2025.
//

#if ALLOW_DX11

#include "dx11/util/dx11_dxgi_device_util.h"

namespace mars {
    Microsoft::WRL::ComPtr<IDXGIDevice> DX11DxgiDeviceUtil::create() {
        Microsoft::WRL::ComPtr<IDXGIDevice> device;
        HRESULT hr = CreateDXGIFactory1(__uuidof(IDXGIDevice), reinterpret_cast<void**>(device.GetAddressOf()));
        if (FAILED(hr)) {
            std::string msg = "DX11DxgiDeviceUtil::create: Failed to create DXGIDevice. HRESULT: " + std::to_string(hr);
            logger.error(msg);
            throw std::runtime_error(msg);
        }
        return device;
    }

}

#endif
