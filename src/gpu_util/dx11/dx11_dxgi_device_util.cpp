//
// Created by Erkapic Luka on 29.5.2025.
//

//
// Created by Erkapic Luka on 27.5.2025.
//

#ifdef _WIN32

#include "gpu_util/dx11/dx11_dxgi_device_util.h"

namespace gpu_util {
    ComPtr<IDXGIDevice> DX11DxgiDeviceUtil::create(ComPtr<ID3D11Device> device) {
        ComPtr<IDXGIDevice> dxgiDevice;
        HRESULT hr = device->QueryInterface(__uuidof(IDXGIDevice), reinterpret_cast<void**>(dxgiDevice.GetAddressOf()));
        if (FAILED(hr)) {
            std::string msg = "DX11DxgiDeviceUtil::create: Failed to create DXGIDevice. HRESULT: " + std::to_string(hr);
            logger.error(msg);
            throw std::runtime_error(msg);
        }
        return dxgiDevice;
    }

}

#endif
