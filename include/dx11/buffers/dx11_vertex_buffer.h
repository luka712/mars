//
// Created by Luka Erkapic on 11.05.25.
//

#ifdef _WIN32

#ifndef DX11_VERTEX_BUFFER_H
#define DX11_VERTEX_BUFFER_H

#include "core/buffers/a_vertex_buffer.h"
#include "dx11/dx11.h"
#include "dx11/renderer/dx11_renderer.h"
#include "Framework.h"

namespace mars {
    //! The D3D11 implementation of the AVertexBuffer.
    class DX11VertexBuffer final : public AVertexBuffer {
    public:
        //! The constructor.
        //! @param framework The framework.
        //! @param label The label.
        explicit DX11VertexBuffer(const Framework &framework, const std::string &label = "");

        //! Gets the underlying buffer.
        //! @returns The ID3D11Buffer buffer.
        [[nodiscard]] ComPtr<ID3D11Buffer> getBuffer() const { return buffer; }

        [[nodiscard]] bool isWritable() const override { return true; }

        void initialize(const void *data, const uint32_t byteSize, const uint32_t byteStride, const uint32_t vertexCount, const BufferUsage usage) override;

        void initialize(const uint32_t byteSize, const uint32_t byteStride, const uint32_t vertexCount) override;

        void update(void *data, uint32_t byteSize, uint32_t offset) override;

        std::string printInfo() override;

        void destroy() override;

    private:
        DX11Renderer &renderer;
        Logger &logger;

        // FRAMEWORK
        BufferUsage usage;

		// D3D11
		ComPtr<ID3D11Device> device;
		ComPtr<ID3D11Buffer> buffer;
    };

    //! Convert the @ref AVertexBuffer to the @ref DX11VertexBuffer.
    //! @param vertexBuffer The vertex buffer.
    //! @returns The @ref DX11VertexBuffer.
    DX11VertexBuffer *toDX11VertexBuffer(AVertexBuffer *vertexBuffer);
}

#endif //METAL_VERTEX_BUFFER_H

#endif // _WIN32