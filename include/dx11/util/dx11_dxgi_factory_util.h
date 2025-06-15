//
// Created by Erkapic Luka on 27.5.2025.
//

#ifndef DXGI_FACTORY_UTIL_H
#define DXGI_FACTORY_UTIL_H

#ifdef _WIN32

#include "core/log/Logger.h"
#include "dx11/dx11.h"

namespace mars {

    class DX11DxgiFactoryUtil {
          public:
        //! Construct a new DXGIFactoryUtil object.
        //! @param logger The logger.
        explicit DX11DxgiFactoryUtil(Logger &logger) : logger(logger) {

        }

        //! Create a DXGI factory.
        //! @return The created DXGI factory.
        Microsoft::WRL::ComPtr<IDXGIFactory2> create();

        private:
        Logger &logger;
    };
}

#endif

#endif //DXGI_FACTORY_UTIL_H
