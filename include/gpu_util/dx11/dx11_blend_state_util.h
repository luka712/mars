//
// Created by Erkapic Luka on 16.8.2025.
//


#ifdef _WIN32

#ifndef DX11_BLEND_STATE_UTIL_H
#define DX11_BLEND_STATE_UTIL_H

#include <string>
#include "gpu_util/dx11.h"
#include "gpu_util/logger.h"

using namespace Microsoft::WRL;

namespace gpu_util {

    //! Utility class for creating DirectX 11 blend states.
    class DX11BlendStateUtil {
    public:

        //! Construct a new DX11BlendStateUtil object.
        //! @param logger The logger.
        explicit DX11BlendStateUtil(Logger &logger) : logger(logger) {
        }

        //! Creates a blend state with the specified parameters.
        //! @param device The DirectX 11 device.
        //! @param blendEnable If true, blending is enabled.
        //! @param srcBlend The source blend factor. By default, it is set to D3D11_BLEND_SRC_ALPHA.
        //! @param destBlend The destination blend factor. By default, it is set to D3D11_BLEND_INV_SRC_ALPHA.
        //! @param blendOp The blend operation. By default, it is set to D3D11_BLEND_OP_ADD.
        //! @return The created ID3D11BlendState.
        ComPtr<ID3D11BlendState> create(
            ComPtr<ID3D11Device> device,
            bool blendEnable = true,
            D3D11_BLEND srcBlend = D3D11_BLEND_SRC_ALPHA,
            D3D11_BLEND destBlend = D3D11_BLEND_INV_SRC_ALPHA,
            D3D11_BLEND_OP blendOp = D3D11_BLEND_OP_ADD
        );

        private:
            Logger &logger; // Logger for logging messages
    };

} // namespace gpu_util

#endif //DX11_BLEND_STATE_UTIL_H

#endif _WIN32