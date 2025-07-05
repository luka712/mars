//
// Created by Erkapic Luka on 26.6.2025.
//

#ifdef _WIN32

#ifndef DX11_BLOB_UTIL_H
#define DX11_BLOB_UTIL_H

#include <string>
#include "gpu_util/dx11.h"
#include "gpu_util/logger.h"

using namespace Microsoft::WRL;

namespace gpu_util {

    //! Utility class for working with Blob in DirectX 11.
    class DX11BlobUtil {
    public:
        //! Construct a new DX11BlobUtil object.
        //! @param logger The logger.
        explicit DX11BlobUtil(Logger &logger) : logger(logger) {
        }

		//! Create a blob from a file.
		//! @param filePath The path to the shader file.
		//! @param profile The shader profile (e.g., "vs_5_0" for vertex shader).
		//! @param entryPoint The entry point of the shader (default is "main").
		//! @return A ComPtr to the created ID3D10Blob, or nullptr if creation failed.
        ComPtr<ID3D10Blob> create(std::string filePath, std::string profile, std::string entryPoint = "main");

      private:
        Logger &logger;
    };

}

#endif //DX11_BLOB_UTIL_H

#endif // _WIN32
