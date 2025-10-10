//
// Created by Erkapic Luka on 12.7.2025.
//
#ifdef _WIN32

#include "gpu_util/dx11/dx11_buffer_util.h"

namespace gpu_util {

	ComPtr<ID3D11Buffer> DX11BufferUtil::create(
		ComPtr<ID3D11Device> device,
		const void* data,
		uint32_t byteSize,
		uint32_t byteStride,
		D3D11_USAGE usage,
		UINT bindFlags,
		UINT cpuAccessFlags,
		UINT miscFlags,
		const std::string& label) {

		D3D11_BUFFER_DESC bufferDesc = {};
		bufferDesc.ByteWidth = byteSize;
		bufferDesc.Usage = usage;
		bufferDesc.BindFlags = bindFlags;
		bufferDesc.CPUAccessFlags = cpuAccessFlags;
		bufferDesc.MiscFlags = miscFlags;

		if (byteStride > 0) {
			bufferDesc.StructureByteStride = byteStride; // For structured buffers
		}

		D3D11_SUBRESOURCE_DATA initData = {};
		initData.pSysMem = data;
		initData.SysMemPitch = 0; // Not used for buffers
		initData.SysMemSlicePitch = 0; // Not used for buffers

		ComPtr<ID3D11Buffer> buffer;
		HRESULT hr = device->CreateBuffer(&bufferDesc, data ? &initData : nullptr, buffer.GetAddressOf());

		if (FAILED(hr)) {
			logger.error("DX11BufferUtil::create: Failed to create buffer. HRESULT: " + std::to_string(hr));
			return nullptr;
		}

		logger.info("DX11BufferUtil::create: Successfully constant created buffer with label: " + label);
		return buffer;
	}

	ComPtr<ID3D11Buffer> DX11BufferUtil::createConstantBuffer(ComPtr<ID3D11Device> device, uint32_t byteSize, D3D11_USAGE usage, UINT cpuAccessFlags, const std::string& label)
	{
		return create(
			device,
			nullptr,
			byteSize,
			0, // No stride for constant buffers 
			usage,
			D3D11_BIND_CONSTANT_BUFFER,
			cpuAccessFlags,
			0,
			label);
	}

	void DX11BufferUtil::updateSubresource(
		ComPtr<ID3D11DeviceContext> context,
		ComPtr<ID3D11Buffer> buffer,
		void* data,
		uint32_t dataSize,
		uint32_t bufferOffset)
	{
		context->UpdateSubresource(buffer.Get(), 0, nullptr, data, dataSize, bufferOffset);
	}

} // namespace gpu_util

#endif // _WIN32