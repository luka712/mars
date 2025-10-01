#ifdef _WIN32

#ifndef DX11_UNIFORM_BUFFER_H
#define DX11_UNIFORM_BUFFER_H

#include "core/buffers/a_uniform_buffer.h"
#include <memory>
#include <dx11/dx11.h>
#include <dx11/renderer/dx11_renderer.h>

using Microsoft::WRL::ComPtr;

namespace mars {
	class Framework;

	//! The DirectX 11 implementation of the uniform buffer.
	class DX11UniformBuffer : public AUniformBuffer {

	public:
		//! The constructor.
		//! @param framework The framework.
		//! @param label The label.
		//! @param byteSize The size of the buffer.
		//! @param bufferUsage The usage of the buffer.
		DX11UniformBuffer(Framework& framework, const std::string& label, uint32_t byteSize, BufferUsage bufferUsage);

		//! The constructor.
		//! @param framework The framework.
		//! @param inputData The data.
		//! @param label The label.
		//! @param byteSize The size of the buffer.
		//! @param bufferUsage The usage of the buffer.
		DX11UniformBuffer(Framework& framework, const void* inputData, const std::string& label, uint32_t byteSize, BufferUsage bufferUsage);

		//! Gets the DirectX 11 buffer.
		//! @returns The DirectX 11 buffer.
		[[nodiscard]]
		ComPtr<ID3D11Buffer> getBuffer() const { return buffer; }

		//! @inheritDoc
		void update(void* data, uint32_t byteSize) override;

		//! @inheritDoc
		std::string printInfo() override;

		//! @inheritDoc
		void destroy() override;

	protected:
		DX11Renderer* renderer;
		ComPtr<ID3D11Device> device;
		ComPtr<ID3D11DeviceContext> deviceContext;
		ComPtr<ID3D11Buffer> buffer; 

		D3D11_USAGE d3d11Usage;
		size_t d3d11CpuAccessFlags = 0;
	};

	//! Converts the @ref AUniformBuffer to @ref DX11UniformBuffer.
	//! @param uniformBuffer The uniform buffer.
	//! @returns The @ref DX11UniformBuffer.
	DX11UniformBuffer* toDX11UniformBuffer(AUniformBuffer* uniformBuffer);

	//! Converts the @ref AUniformBuffer to @ref DX11UniformBuffer.
	//! @param uniformBuffer The uniform buffer.
	//! @returns The @ref DX11UniformBuffer.
	std::shared_ptr<DX11UniformBuffer> toDX11UniformBuffer(const std::shared_ptr<AUniformBuffer>& uniformBuffer);
}

#endif //DX11_UNIFORM_BUFFER_H

#endif // _WIN32