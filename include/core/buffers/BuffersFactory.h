//
// Created by lukaa on 18.1.2025..
//

#ifndef ABUFFERSFACTORY_H
#define ABUFFERSFACTORY_H

#include <memory>
#include <vector>
#include "core/buffers/AVertexBuffer.h"
#include "core/buffers/AIndexBuffer.h"

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
            std::vector<float> data,
            uint32_t vertexCount,
            BufferUsage usage,
            const std::string& label) const;

        //! Create a new index buffer.
        //! @param data The data to initialize the buffer with.
        //! @param label The label of the buffer.
        std::shared_ptr<AIndexBuffer> createindexBuffer(
            std::vector<uint16_t> data,
            const std::string& label);

    private:
        Framework& framework;
    };
}


#endif //ABUFFERSFACTORY_H
