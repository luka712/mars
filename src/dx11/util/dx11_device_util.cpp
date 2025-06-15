//
// Created by Erkapic Luka on 27.5.2025.
//

#ifdef _WIN32

#include <stdexcept>
#include <tuple>
#include <string>
#include "dx11/dx11.h"
#include "dx11/util/dx11_device_util.h"

namespace mars {
    //! Create a DirectX 11 device and device context.
    //! @return A tuple containing the created ID3D11Device and ID3D11DeviceContext.
    std::tuple<Microsoft::WRL::ComPtr<ID3D11Device>, Microsoft::WRL::ComPtr<ID3D11DeviceContext> >
    DX11DeviceUtil::createDeviceAndDeviceContext() {
        Microsoft::WRL::ComPtr<ID3D11Device> device;
        Microsoft::WRL::ComPtr<ID3D11DeviceContext> deviceContext;

        uint32_t deviceFlags = 0;
#ifdef _DEBUG
        deviceFlags |= D3D11_CREATE_DEVICE_DEBUG; // Enable debug layer in debug builds.
#endif

        // 11.1 is the latest feature level supported by most modern hardware.
        D3D_FEATURE_LEVEL featureLevelRequested = D3D_FEATURE_LEVEL_11_1;
        uint32_t numFeatureLevelsRequested = 1;
        D3D_FEATURE_LEVEL featureLevelSupported;

        HRESULT hr = D3D11CreateDevice(
            nullptr, // Use default adapter. One could query for adapters if there are multiple GPU's to choose from.
            D3D_DRIVER_TYPE_HARDWARE,
            nullptr, // No software rasterizer
            0, // Default flags
            &featureLevelRequested, // Use default feature levels
            numFeatureLevelsRequested,
            D3D11_SDK_VERSION,
            &device,
            &featureLevelSupported,
            &deviceContext
        );

        if (FAILED(hr)) {
            std::string msg =
                    "DX11DeviceUtil::createDeviceAndDeviceContext: Failed to create DirectX 11 device. HRESULT: " +
                    std::to_string(hr);
            logger.error(msg);
            throw std::runtime_error(msg);
        }

        logger.info(
            "DX11DeviceUtil::createDeviceAndDeviceContext: Created DirectX 11 device with feature level: " +
            std::to_string(featureLevelSupported));

        return std::make_tuple(device, deviceContext);
    }

    std::string DX11DeviceUtil::getDeviceName(Microsoft::WRL::ComPtr<IDXGIDevice> dxgiDevice, Microsoft::WRL::ComPtr<ID3D11Device> device) {

        // TODO: move outside
        IDXGIAdapter* dxgiAdapter;
        HRESULT hr = dxgiDevice->GetAdapter(&dxgiAdapter);
        if (FAILED(hr)) {
            std::string msg = "DX11DeviceUtil::getDeviceName: Failed to get IDXGIAdapter. HRESULT: " +
                              std::to_string(hr);
            logger.error(msg);
            throw std::runtime_error(msg);
        }

        DXGI_ADAPTER_DESC desc;
        hr = dxgiAdapter->GetDesc(&desc);
        if (FAILED(hr)) {
            std::string msg = "DX11DeviceUtil::getDeviceName: Failed to get adapter description. HRESULT: " +
                              std::to_string(hr);
            logger.error(msg);
            throw std::runtime_error(msg);
        }

        // Convert the wide string to a UTF-8 string.
        std::wstring wideStr(desc.Description);
        std::string deviceName(wideStr.begin(), wideStr.end());

        return deviceName;
    }
}

#endif // __WIN32__
