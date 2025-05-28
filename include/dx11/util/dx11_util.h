//
// Created by Erkapic Luka on 27.5.2025.
//

#ifndef DX11_UTIL_H
#define DX11_UTIL_H

#if __WIN32__

#include "dx11/util/dx11_dxgi_factory_util.h"
#include "dx11/util/dx11_device_util.h"

namespace mars {
    static DX11DxgiFactoryUtil *dxgiFactoryUtil = nullptr;
    static DX11DeviceUtil *dx11DeviceUtil = nullptr;

    class DX11Util {
    public:
        //! Initialize the MetalUtil.
        //! @param logger The logger.
        static void initialize(Logger &logger) {
            dxgiFactoryUtil = new DX11DxgiFactoryUtil(logger);
            dx11DeviceUtil = new DX11DeviceUtil(logger);
        }

        //! Gets the DXGIFactoryUtil. Used to create DXGI factories.
        //! @return The DXGIFactoryUtil pointer.
        static DX11DxgiFactoryUtil &getDxgiFactory() { return *dxgiFactoryUtil; }

        //! Gets the DX11DeviceUtil for working with DirectX 11 devices.
        //! @return The DX11DeviceUtil ptr.
        static DX11DeviceUtil &getDeviceUtil() { return *dx11DeviceUtil; }
};
}

#endif

#endif //DX11_UTIL_H
