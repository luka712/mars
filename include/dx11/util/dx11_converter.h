//
// Created by Erkapic Luka on 12.7.2025.
//

#ifdef _WIN32

#ifndef DX11_CONVERTER_H
#define DX11_CONVERTER_H

#include "core/log/Logger.h"
#include "dx11/dx11.h"
#include "core/buffers/buffer_enums.h"

namespace mars {

    //! The class that helps with converting <b>mars</b> types to <b>d3d11</b> types and vice-versa.
    class DX11Converter {

    public:
        //! Initialize the converted and assign logger.
        //! @param logger The logger.
        static void initialize(Logger *logger);

        //! Convert <b>mars</b> buffer usage to <b>d3d11</b> buffer usage.
        //! @param usage The <b>mars</b> buffer usage.
        //! @return The <b>d3d11</b> buffer usage.
        static D3D11_USAGE convertBufferUsage(BufferUsage usage);

		//! Convert <b>mars</b> buffer usage to <b>d3d11</b> bind flags.
		//! @param usage The <b>mars</b> buffer usage.
		//! @return The <b>d3d11</b> bind flags.
        static UINT convertToBindFlags(BufferUsage usage);

		//! Convert <b>mars</b> buffer usage to <b>d3d11</b> resource misc flags.
		//! @param usage The <b>mars</b> buffer usage.
		//! @return The <b>d3d11</b> resource misc flags.
        static UINT convertToResourceMiscFlags(BufferUsage usage);

    private:
        static Logger* logger;
    };

}

#endif //DX11_CONVERTER_H

#endif