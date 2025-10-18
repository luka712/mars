//
// Created by Luka Erkapic on 18.05.25.
//

#ifndef METAL_UNIFORM_BUFFER_H
#define METAL_UNIFORM_BUFFER_H

#if __APPLE__

#include "core/buffers/a_uniform_buffer.h"
#include "metal/metal.h"
#include "Framework.h"
#include "metal/renderer/metal_renderer.h"

namespace mars {
    //! The Metal implementation of the Uniform Buffer.
    class MetalUniformBuffer final : public AUniformBuffer {
    public:
        //! The constructor.
        //! @param framework The framework.
        //! @param label The label.
        //! @param byteSize The size of the buffer.
        //! @param bufferUsage The usage of the buffer.
        MetalUniformBuffer(Framework &framework,
            const std::string &label,
            uint32_t byteSize,
            BufferUsage bufferUsage);

        //! The constructor.
        //! @param framework The framework.
        //! @param inputData The data.
        //! @param label The label.
        //! @param byteSize The size of the buffer.
        //! @param bufferUsage The usage of the buffer.
        MetalUniformBuffer(Framework &framework,
            const void *inputData,
            const std::string &label,
            uint32_t byteSize,
            BufferUsage bufferUsage);

        //! @inheritDoc
        void update(void *data, uint32_t byteSize) override;

        //! @inheritDoc
        std::string printInfo() override;

        //! @inheritDoc
        void destroy() override;

    private:
        MetalRenderer &renderer;
        Logger &logger;

        // FRAMEWORK
        BufferUsage usage;

        // METAL
        MTL::Device *device{};
        MTL::ResourceOptions options{};
        MTL::Buffer *buffer{};
    };

    //! Converts the @ref AUniformBuffer to @ref MetalUniformBuffer.
    //! @param uniformBuffer The uniform buffer.
    //! @returns The @ref MetalUniformBuffer.
    MetalUniformBuffer *toMetalUniformBuffer(AUniformBuffer *uniformBuffer);

    //! Converts the @ref AUniformBuffer to @ref MetalUniformBuffer.
    //! @param uniformBuffer The uniform buffer.
    //! @returns The @ref MetalUniformBuffer.
    std::shared_ptr<MetalUniformBuffer> toMetalUniformBuffer(const std::shared_ptr<AUniformBuffer> &uniformBuffer);
}

#endif

#endif //METAL_UNIFORM_BUFFER_H
