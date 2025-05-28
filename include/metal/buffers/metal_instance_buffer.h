//
// Created by Luka Erkapic on 19.05.25.
//

#ifndef METAL_INSTANCE_BUFFER_H
#define METAL_INSTANCE_BUFFER_H

#if __APPLE__

#include "metal/metal.h"
#include "core/buffers/AInstanceBuffer.h"
#include "metal/renderer/metal_renderer.h"

namespace mars {

    class Framework;

    //! The Metal implementation of Instance Buffer.
    class MetalInstanceBuffer final : public AInstanceBuffer {

    public:
        //! Construct a new MetalInstanceBuffer object.
        //! @param framework The framework.
        //! @param label The label of the buffer.
        explicit MetalInstanceBuffer(Framework &framework, std::string label = "");

        //! Get the underlying Metal buffer.
        //! @return The underlying Metal buffer.
        [[nodiscard]] MTL::Buffer* getBuffer() const { return buffer; }

        uint32_t getInstanceCount() override { return instanceCount; }

        uint32_t getByteSize() override { return byteSize; }

        uint32_t getByteStride() override { return byteStride; }

        const std::string &getLabel() override { return label; }

        void initialize(const void *data, uint32_t byteSize, uint32_t strideInBytes, uint32_t instanceCount) override;

        void destroy() override;

    private:
        Framework &framework;
        MetalRenderer &renderer;
        Logger &logger;

        // FRAMEWORK
        BufferUsage usage;

        // METAL
        MTL::Device *device{};
        MTL::ResourceOptions options{};
        MTL::Buffer *buffer{};

        uint32_t instanceCount = 1;
        uint32_t byteSize = 0;
        uint32_t byteStride = 0;
        std::string label;
    };

    //! Converts the @ref AInstanceBuffer to @ref MetalInstanceBuffer.
    //! @param instanceBuffer The instance buffer.
    //! @returns The @ref MetalInstanceBuffer.
    MetalInstanceBuffer* toMetalInstanceBuffer(AInstanceBuffer* instanceBuffer);

    //! Converts the @ref AInstanceBuffer to @ref MetalInstanceBuffer.
    //! @param instanceBuffer The instance buffer.
    //! @returns The @ref MetalInstanceBuffer.
    std::shared_ptr<MetalInstanceBuffer> toMetalInstanceBuffer(const std::shared_ptr<AInstanceBuffer> &instanceBuffer);;

}

#endif //METAL_INSTANCE_BUFFER_H

#endif