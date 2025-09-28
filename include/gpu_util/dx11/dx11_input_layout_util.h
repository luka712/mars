//
// Created by Erkapic Luka on 12.7.2025.
//

#ifdef _WIN32

#ifndef DX11_INPUT_LAYOUT_UTIL_H
#define DX11_INPUT_LAYOUT_UTIL_H

#include <stdexcept>
#include "gpu_util/dx11.h"
#include "gpu_util/logger.h"
#include <vector>

using Microsoft::WRL::ComPtr;

namespace gpu_util {

    //! Utility class for creating DirectX 11 input layouts.
    class DX11InputLayoutUtil {
    public:
        //! Construct a new DX11DxgiDeviceUtil object.
        //! @param logger The logger.
        explicit DX11InputLayoutUtil(Logger &logger) : logger(logger) {
        }

        //! Creates a DirectX 11 input layout from the provided shader blob and input element description.
        //! @param device The DirectX 11 device.
        //! @param shaderBlob The compiled shader blob.
        //! @param inputElementDesc The input element description array.
        //! @return A ComPtr to the created ID3D11InputLayout.
        ComPtr<ID3D11InputLayout> create(
            ComPtr<ID3D11Device> device,
            ComPtr<ID3D10Blob> shaderBlob,
			std::vector<D3D11_INPUT_ELEMENT_DESC>& inputElementDesc);

		//! Creates a DirectX 11 input layout for position, color, and texture coordinates in interleaved format.
		//! Position is a vec3 (3 floats), color is a vec4 (4 floats), and texture coordinates is a vec2 (2 floats).
		//! @param device The DirectX 11 device.
		//! @param shaderBlob The compiled shader blob.
		//! @return A ComPtr to the created ID3D11InputLayout.
        ComPtr<ID3D11InputLayout> createPositionColorTextureCoordinatesInputLayout(
            ComPtr<ID3D11Device> device,
            ComPtr<ID3D10Blob> shaderBlob);

    private:
        Logger &logger; // Logger for logging messages
    };

} // namespace gpu_util

#endif //DX11_INPUT_LAYOUT_UTIL_H

#endif