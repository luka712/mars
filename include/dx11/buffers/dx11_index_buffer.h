//
// Created by Erkapic Luka on 23.7.2025.
//

#ifdef _WIN32

#ifndef DX11_INDEX_BUFFER_H
#define DX11_INDEX_BUFFER_H

#include "core/buffers/a_index_buffer.h"
#include "dx11/dx11.h"
#include "dx11/renderer/dx11_renderer.h"
#include <string>
#include <vector>

namespace mars {

    class Framework;

    //! The D3D11 implementation of the AIndexBuffer.
    class DX11IndexBuffer final : public AIndexBuffer {
    public:
        //! The constructor.
        //! @param framework The framework.
        //! @param label The label.
        explicit DX11IndexBuffer(const Framework &framework, const std::string &label = "");

        //! Gets the underlying buffer.
        //! @returns The ID3D11Buffer buffer.
        [[nodiscard]] ComPtr<ID3D11Buffer> getBuffer() const { return buffer; }

        //! @copydoc AIndexBuffer::initialize(const std::vector<uint16_t>&)
        void initialize(const std::vector<uint16_t>& data) override;

        //! @copydoc AIndexBuffer::initialize(const std::vector<uint32_t>&)
        void initialize(const std::vector<uint32_t>& data) override;

        //! @copydoc AIndexBuffer::printInfo()
        std::string printInfo() override;

        //! @copydoc AIndexBuffer::destroy()
        void destroy() override;

    private:
        DX11Renderer &renderer;
        Logger &logger;

        // D3D11
        ComPtr<ID3D11Device> device;
        ComPtr<ID3D11Buffer> buffer;
    };

    //! Convert the @ref AIndexBuffer to the @ref DX11IndexBuffer.
    //! @param indexBuffer The index buffer.
    //! @returns The @ref DX11IndexBuffer.
    DX11IndexBuffer *toDX11IndexBuffer(AIndexBuffer *indexBuffer);

} // namespace mars

#endif //DX11_INDEX_BUFFER_H

#endif