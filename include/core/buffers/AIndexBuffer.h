//
// Created by luka on 18.1.2025.
//

#ifndef A_INDEX_BUFFER_H
#define A_INDEX_BUFFER_H

#include <cstdint>
#include <string>
#include <utility>
#include <vector>
#include "core/buffers/BufferEnums.h"

namespace mars {


    //! The index buffer.
    class AIndexBuffer {
    public:
        //! Construct a new AIndexBuffer object.
        //! @param label The label of the buffer.
        explicit AIndexBuffer(std::string label)
            : label(std::move(label)) {
        }

        virtual ~AIndexBuffer() = default;

        //! Get the label of the vertex buffer.
        [[nodiscard]] const std::string &getLabel() const { return label; }

        //! Gets the vertex count.
        [[nodiscard]] uint32_t getIndicesCount() const { return indicesCount; }

        //! Gets the byte size.
        [[nodiscard]] uint32_t getByteSize() const { return byteSize; }

        //! Gets the type of the index buffer.
        [[nodiscard]] IndexBufferType getType() const { return type; }

        //! Gets the element byte size.
        [[nodiscard]] uint32_t getElementByteSize() const {
            return type == IndexBufferType::Uint16 ? 2 : 4;
        }

        //! Initialize the vertex buffer.
        //! @param data The data to initialize the buffer with.
        virtual void initialize(const std::vector<uint16_t>& data) = 0;

        //! Initialize the vertex buffer.
        //! @param data The data to initialize the buffer with.
        virtual void initialize(const std::vector<uint32_t>& data) = 0;

        //! Logs information about the buffer and returns it as a string.
        //! @return The information about the buffer.
        virtual std::string printInfo() = 0;

        //! Destroy the index buffer.
        virtual void destroy() = 0;

    protected:
        std::string label;
        uint32_t indicesCount{};
        uint32_t byteSize{};
        IndexBufferType type{};
    };
}


#endif //A_INDEX_BUFFER_H
