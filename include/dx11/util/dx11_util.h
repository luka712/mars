//
// Created by Erkapic Luka on 27.5.2025.
//

#ifndef DX11_UTIL_H
#define DX11_UTIL_H

#if ALLOW_DX11

#include "dx11/util/dx11_dxgi_factory_util.h"
#include "dx11/util/dx11_device_util.h"
#include "dx11/util/dx11_dxgi_device_util.h"

namespace mars {
    static DX11DxgiFactoryUtil *dxgiFactoryUtil = nullptr;
    static DX11DeviceUtil *dx11DeviceUtil = nullptr;
    static DX11DxgiDeviceUtil *dxgiDeviceUtil = nullptr;

    class DX11Util {
    public:
        //! Initialize the MetalUtil.
        //! @param logger The logger.
        static void initialize(Logger &logger) {
            dxgiFactoryUtil = new DX11DxgiFactoryUtil(logger);
            dxgiDeviceUtil = new DX11DxgiDeviceUtil(logger);
            dx11DeviceUtil = new DX11DeviceUtil(logger);
        }

        //! Gets the DXGIFactoryUtil. Used to create DXGI factories.
        //! @return The DXGIFactoryUtil pointer.
        static DX11DxgiFactoryUtil &getDxgiFactory() { return *dxgiFactoryUtil; }

        //! Gets the DXGIDeviceUtil. Used to create DXGI devices.
        //! @return The DXGIDeviceUtil pointer.
        static DX11DxgiDeviceUtil &getDxgiDevice() { return *dxgiDeviceUtil; }

        //! Gets the DX11DeviceUtil for working with DirectX 11 devices.
        //! @return The DX11DeviceUtil ptr.
        static DX11DeviceUtil &getDevice() { return *dx11DeviceUtil; }
};
}

#endif

#endif //DX11_UTIL_H
