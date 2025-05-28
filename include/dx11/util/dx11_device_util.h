//
// Created by Erkapic Luka on 27.5.2025.
//

#ifndef DX11_DEVICE_UTIL_H
#define DX11_DEVICE_UTIL_H

#if ALLOW_DX11

#include <stdexcept>
#include "core/log/Logger.h"
#include "dx11/dx11.h"
#include <tuple>
#include <string>

namespace mars {

    //! Utility class for creating and managing DirectX 11 devices and related resources.
    class DX11DeviceUtil {
    public:
        //! Construct a new DX11DeviceUtil object.
        //! @param logger The logger.
        explicit DX11DeviceUtil(Logger &logger) : logger(logger) {

        }

        //! Create a DirectX 11 device and device context.
        //! @return A tuple containing the created ID3D11Device and ID3D11DeviceContext.
        std::tuple<Microsoft::WRL::ComPtr<ID3D11Device>, Microsoft::WRL::ComPtr<ID3D11DeviceContext>>  createDeviceAndDeviceContext();

        //! Get the name of the DirectX 11 device.
        //! @param device The DirectX 11 device.
        //! @return The name of the device as a string.
        std::string getDeviceName(Microsoft::WRL::ComPtr<ID3D11Device> device);

    private:
        Logger &logger;
      };
}

#endif

#endif //DX11_DEVICE_UTIL_H
