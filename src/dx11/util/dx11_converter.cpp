//
// Created by Erkapic Luka on 12.7.2025.
//

#ifdef _WIN32

#include "dx11/util/dx11_converter.h"
#include <stdexcept>

namespace mars {

	Logger* DX11Converter::logger = nullptr;

	void DX11Converter::initialize(Logger* logger) {
		DX11Converter::logger = logger;
	}

	D3D11_USAGE DX11Converter::convertBufferUsage(BufferUsage usage) {
		switch (usage) {
		case BufferUsage::Vertex:
			return D3D11_USAGE_IMMUTABLE;
		case BufferUsage::Vertex_CopyDst:
		case BufferUsage::Uniform:
			return D3D11_USAGE_DEFAULT;
		default:
			logger->error("Unknown buffer usage type.");
			throw std::invalid_argument("Unknown buffer usage type.");
		}
	}

	UINT DX11Converter::convertToBindFlags(BufferUsage usage) {
		switch (usage)
		{
		case BufferUsage::Vertex:
		case BufferUsage::Vertex_CopyDst:
			return D3D11_BIND_VERTEX_BUFFER;
		default:
			logger->error("Unknown buffer usage type.");
			throw std::invalid_argument("Unknown buffer usage type.");
		}
	}

	UINT DX11Converter::convertToResourceMiscFlags(BufferUsage usage) {
		switch (usage)
		{
		case BufferUsage::Vertex:
		case BufferUsage::Vertex_CopyDst:
			return 0;
		default:
			logger->error("Unknown buffer usage type.");
			throw std::invalid_argument("Unknown buffer usage type.");
		}
	}


} // namespace mars

#endif // _WIN32