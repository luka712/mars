//
// Created by Erkapic Luka on 18.1.2025.
//

#ifndef A_BUFFERS_FACTORY_H
#define A_BUFFERS_FACTORY_H

#include <memory>
#include <vector>

#include "AInstanceBuffer.h"
#include "core/buffers/a_vertex_buffer.h"
#include "core/buffers/AIndexBuffer.h"
#include "core/buffers/AUniformBuffer.h"

namespace mars {

    class Framework;

    //! The abstract factory for creating buffers.
    class BuffersFactory {

       public:
        //! Construct a new BuffersFactory object.
        //! @param framework The framework.
        explicit BuffersFactory(Framework& framework);

        //! Create a new vertex buffer.
        //! @param data The data to initialize the buffer with.
        //! @param vertexCount The number of vertices.
        //! @param usage The usage of the buffer.
        //! @param label The label of the buffer.
        //! @return The shared pointer to the vertex buffer.
        std::shared_ptr<AVertexBuffer> createVertexBuffer(
            const std::vector<float>& data,
            uint32_t vertexCount,
            BufferUsage usage,
            const std::string& label) const;

        //! Create a new index buffer.
        //! @param data The data to initialize the buffer with.
        //! @param label The label of the buffer.
        //! @return The shared pointer to the index buffer.
        std::shared_ptr<AIndexBuffer> createIndexBuffer(
            const std::vector<uint16_t>& data,
            const std::string& label) const;

        //! Create a new uniform buffer.
        //! @param data The data to initialize the buffer with.
        //! @param label The label of the buffer.
        //! @param byteSize The size of the buffer.
        //! @param bufferUsage The usage of the buffer.
        //! @return The shared pointer to the uniform buffer.
        std::shared_ptr<AUniformBuffer> createUniformBuffer(
            void* data,
            const std::string& label,
            uint32_t byteSize,
            BufferUsage bufferUsage) const;

        //! Create a new instance buffer.
        //! @param data The data to initialize the buffer with.
        //! @param byteSize The size of the buffer.
        //! @param strideInBytes The stride in bytes.
        //! @param instanceCount The number of instances.
        //! @param label The label of the buffer.
        //! @return The shared pointer to the instance buffer.
        std::shared_ptr<AInstanceBuffer> createInstanceBuffer(
            const void* data,
            uint32_t byteSize,
            uint32_t strideInBytes,
            uint32_t instanceCount,
            const std::string& label) const;

    private:
        Framework& framework;
    };
}


#endif //A_BUFFERS_FACTORY_H
