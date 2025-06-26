//
// Created by Erkapic Luka on 26.6.2025.
//

#ifdef _WIN32

#include <iostream>
#include <fstream>
#include "gpu_util/dx11/dx11_blob_util.h"


namespace gpu_util {
	ComPtr<ID3D10Blob> DX11BlobUtil::create(std::string filePath, std::string profile, std::string entryPoint)
	{
		// First check if file exists.
		std::ifstream file;
		if (!file.good()) {
			logger.error("DX11BlobUtil::create: File not found: " + filePath);
			return nullptr;
		}
		file.close();

		ComPtr<ID3D10Blob> blob;
		ComPtr<ID3D10Blob> errorBlob;

		HRESULT hresult = D3DCompileFromFile(
			std::wstring(filePath.begin(), filePath.end()).c_str(),
			nullptr,
			D3D_COMPILE_STANDARD_FILE_INCLUDE,
			entryPoint.c_str(),
			profile.c_str(),
			0, // shader compile flags
			0,
			&blob,
			&errorBlob
		);

		// If compilation failed, log the error and return nullptr.
		if (FAILED(hresult)) {
			if (errorBlob) {
				std::string errorMessage = static_cast<const char*>(errorBlob->GetBufferPointer());
				logger.error("DX11BlobUtil::create: Shader compilation failed: " + errorMessage);
			}
			else {
				logger.error("DX11BlobUtil::create: Shader compilation failed with unknown error.");
			}
			return nullptr;
		}

		// If blob was not created, log an error.
		if (!blob) {
			logger.error("DX11BlobUtil::create: Failed to create blob from file: " + filePath);
			return nullptr;
		}

		logger.info("DX11BlobUtil::create: Successfully created blob from file: " + filePath);

		return blob;
	}
} // namespace gpu_util

#endif
