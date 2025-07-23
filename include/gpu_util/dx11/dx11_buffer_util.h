//
// Created by Erkapic Luka on 12.7.2025.
//

#ifdef _WIN32

#ifndef DX11_BUFFER_UTIL_H
#define DX11_BUFFER_UTIL_H

#include <string>
#include <vector>
#include "gpu_util/dx11.h"
#include "gpu_util/logger.h"

using namespace Microsoft::WRL;

namespace gpu_util {

    //! Utility class for DirectX 11 buffer operations.
    class DX11BufferUtil {
    public:
        //! Construct a new DX11BufferUtil object.
        //! @param logger The logger.
        explicit DX11BufferUtil(Logger& logger) : logger(logger) {
        }

        //! Create a DirectX 11 buffer.
        //! @param device The DirectX 11 device to create the buffer on.
        //! @param data Pointer to the data to initialize the buffer with.
        //! @param byteSize The size of the data in bytes.
        //! @param byteStride The stride of the buffer (0 for default).
        //! @param usage The usage of the buffer (default is D3D11_USAGE_DEFAULT).
        //! @param bindFlags The bind flags for the buffer (default is D3D11_BIND_VERTEX_BUFFER).
        //! @param cpuAccessFlags The CPU access flags for the buffer (default is 0).
        //! @param miscFlags Miscellaneous flags for the buffer (default is 0).
        //! @param label The label for the buffer (default is empty string).
        //! @return A ComPtr to the created ID3D11Buffer, or nullptr if creation failed.
        ComPtr<ID3D11Buffer> create(
            ComPtr<ID3D11Device> device,
            const void* data,
            uint32_t byteSize,
            uint32_t byteStride,
            D3D11_USAGE usage = D3D11_USAGE_DEFAULT,
            UINT bindFlags = D3D11_BIND_VERTEX_BUFFER,
            UINT cpuAccessFlags = 0,
            UINT miscFlags = 0,
            const std::string& label = "");

		//! Create a DirectX 11 buffer which is setup as index buffer.
		//! Buffer is created with D3D11_BIND_INDEX_BUFFER flag and D3D11_USAGE_IMMUTABLE usage.
		//! @param device The DirectX 11 device to create the buffer on.
		//! @param data Pointer to the data to initialize the buffer with.
		//! @param label The label for the buffer (default is empty string).
		//! @param T The type of the index data (e.g., uint16_t or uint32_t).
		//! @return A ComPtr to the created ID3D11Buffer, or nullptr if creation failed.
		template<typename T>
        ComPtr<ID3D11Buffer> createIndexBuffer(ComPtr<ID3D11Device> device, const std::vector<T>& data, const std::string& label = "")
        {
			// Create the buffer using the create method
			return create(
				device,
				data.data(),
				data.size() * sizeof(T),
				sizeof(T),
		        D3D11_USAGE_IMMUTABLE,
				D3D11_BIND_INDEX_BUFFER,
				0, // No CPU access for index buffers
				0, // No miscellaneous flags
				label);
        }

    private:
        Logger& logger;
    };
}

#endif //DX11_BUFFER_UTIL_H

#endif // _WIN32