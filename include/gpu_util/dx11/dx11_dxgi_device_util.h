//
// Created by Erkapic Luka on 29.5.2025.
//

#ifndef DX11_DXGI_DEVICE_UTIL_H
#define DX11_DXGI_DEVICE_UTIL_H

#ifdef _WIN32

#include <stdexcept>
#include "gpu_util/dx11.h"
#include "gpu_util/logger.h"

using namespace Microsoft::WRL;

namespace gpu_util {

    class DX11DxgiDeviceUtil {
    public:
        //! Construct a new DX11DxgiDeviceUtil object.
        //! @param logger The logger.
        explicit DX11DxgiDeviceUtil(Logger &logger) : logger(logger) {

        }

        //! Create a DXGI device.
		//! @param device The DirectX 11 device to associate with the DXGI device.
        //! @return The created DXGI device.
        ComPtr<IDXGIDevice> create(ComPtr<ID3D11Device> device);

    private:
        Logger &logger;
    };
}

#endif

#endif //DX11_DXGI_DEVICE_UTIL_H
