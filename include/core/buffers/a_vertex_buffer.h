//
// Created by Erkapic Luka on 18.1.2025.
//

#ifndef A_VERTEX_BUFFER_H
#define A_VERTEX_BUFFER_H

#include <cstdint>
#include <string>
#include <utility>
#include "core/buffers/buffer_enums.h"

namespace mars {
    class AVertexBuffer {
    public:
        //! Construct a new AVertexBuffer object.
        //! @param label The label of the buffer.
        explicit AVertexBuffer(std::string  label)
            : label(std::move(label)) {
        }

        virtual ~AVertexBuffer() = default;

        //! Can buffer be written to.
        [[nodiscard]] virtual bool isWritable() const = 0;

        //! Get the label of the vertex buffer.
        [[nodiscard]] const std::string &getLabel() const { return label; }

        //! Gets the vertex count.
        [[nodiscard]] uint32_t getVertexCount() const { return vertexCount; }

        //! Gets the byte size.
        [[nodiscard]] uint32_t getByteSize() const { return byteSize; }

        //! Gets the byte stride.
        [[nodiscard]] uint32_t getByteStride() const { return byteStride; }

        //! Initialize the vertex buffer.
        //! @param data The data to initialize the buffer with.
        //! @param byteSize The size of the buffer in bytes.
        //! @param byteStride The stride of a vertex in the buffer in bytes.
        //! @param vertexCount The number of vertices.
        //! @param usage The usage of the buffer.
        virtual void initialize(const void *data,
                                const  uint32_t byteSize,
                                const uint32_t byteStride,
                                const  uint32_t vertexCount,
                                const  BufferUsage usage) = 0;

        //! Initialize the vertex buffer. This will create a writable buffer since data is not passed in.
        //! Creates writable buffer by default.
        //! @param byteSize The size of the buffer in bytes.
        //! @param byteStride The stride of a vertex in the buffer in bytes.
        //! @param vertexCount The number of vertices.
        virtual void initialize(const uint32_t byteSize, const uint32_t byteStride, const  uint32_t vertexCount) = 0;

        //! Update the vertex buffer.
        //! @param data The data to update the buffer with.
        //! @param byteSize The size of the data in bytes.
        //! @param offset The offset in the buffer.
        virtual void update(void *data, const uint32_t byteSize, const  uint32_t offset) = 0;

        //! Logs information about the buffer and returns it as a string.
        //! @return The information about the buffer.
        virtual std::string printInfo() = 0;

        //! Destroy the vertex buffer.
        virtual void destroy() = 0;

    protected:
        std::string label;
        uint32_t vertexCount{};
        uint32_t byteSize{};
        uint32_t byteStride{};
    };
}

#endif //A_VERTEX_BUFFER_H
