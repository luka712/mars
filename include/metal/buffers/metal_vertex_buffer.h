//
// Created by Luka Erkapic on 11.05.25.
//

#ifndef METAL_VERTEX_BUFFER_H
#define METAL_VERTEX_BUFFER_H

#include "core/buffers/a_vertex_buffer.h"
#include "metal/metal.h"
#include "metal/renderer/metal_renderer.h"
#include "Framework.h"

namespace mars {
    //! The Metal implementation of the AVertexBuffer.
    class MetalVertexBuffer final : public AVertexBuffer {
    public:
        //! The constructor.
        //! @param framework The framework.
        //! @param label The label.
        explicit MetalVertexBuffer(const Framework &framework, const std::string &label = "");

        //! Gets the underlying buffer.
        //! @returns The Metal buffer.
        [[nodiscard]] MTL::Buffer *getBuffer() const { return buffer; }

        [[nodiscard]] bool isWritable() const override { return true; }

        //! @copyDoc AVertexBuffer::initialize
        void initialize(const void *data,
                        const uint32_t byteSize,
                        const uint32_t byteStride,
                        const uint32_t vertexCount,
                        const BufferUsage usage) override;
        
        //! @copyDoc AVertexBuffer::initialize
        void initialize(const uint32_t byteSize,
                        const uint32_t byteStride,
                        const uint32_t vertexCount
                        ) override;

        void update(void *data, uint32_t byteSize, uint32_t offset) override;

        std::string printInfo() override;

        void destroy() override;

    private:
        MetalRenderer &renderer;
        Logger &logger;

        // FRAMEWORK
        BufferUsage usage;

        // METAL
        MTL::Device *device{};
        MTL::CommandQueue *queue{};
        MTL::ResourceOptions options{};
        MTL::Buffer *buffer;
    };

    //! Convert the @ref AVertexBuffer to the @ref MetalVertexBuffer.
    //! @param vertexBuffer The vertex buffer.
    //! @returns The @ref MetalVertexBuffer.
    MetalVertexBuffer *toMetalVertexBuffer(AVertexBuffer *vertexBuffer);
}

#endif //METAL_VERTEX_BUFFER_H
