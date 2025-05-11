//
// Created by Luka Erkapic on 11.05.25.
//

#ifndef METAL_INDEX_BUFFER_H
#define METAL_INDEX_BUFFER_H

#include "metal/metal.h"
#include "Framework.h"
#include "core/buffers/AIndexBuffer.h"
#include "metal/renderer/metal_renderer.h"

namespace mars {
    //! The Metal implementation of the AIndexBuffer.
    class MetalIndexBuffer final : public AIndexBuffer {

        public:
        //! Construct a new MetalIndexBuffer.
        //! @param framework The framework.
        //! @param label The label of the buffer.
        MetalIndexBuffer(const Framework& framework, const std::string &label);

        //! Gets the underlying buffer.
        //! @returns The Metal buffer.
        [[nodiscard]] MTL::Buffer* getBuffer() const { return buffer; }

        void initialize(const std::vector<uint16_t>& data) override;

        void initialize(const std::vector<uint32_t>& data) override;

        std::string printInfo() override;

        void destroy() override;

    private:
        MetalRenderer& renderer;
        Logger& logger;

        // FRAMEWORK
        BufferUsage usage;

        // METAL
        MTL::Device *device{};
        MTL::ResourceOptions options{};
        MTL::Buffer *buffer{};
    };

    //! Converts the @ref AIndexBuffer to @ref MetalIndexBuffer.
    //! @param indexBuffer The index buffer.
    //! @returns The @ref MetalIndexBuffer.
    MetalIndexBuffer* toMetalIndexBuffer(AIndexBuffer* indexBuffer);
}

#endif //METAL_INDEX_BUFFER_H
