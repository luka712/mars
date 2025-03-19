//
// Created by Erkapic Luka on 18.3.2025.
//

#ifndef A_INSTANCE_BUFFER_H
#define A_INSTANCE_BUFFER_H

#include <cstdint>
#include <string>

namespace mars {

    //! The instance buffer.
    class AInstanceBuffer {

    public:
        virtual ~AInstanceBuffer() = default;

        /// The number of instances that buffer supports. <code>1</code> by default.
        virtual uint32_t getInstanceCount() = 0;

        //! The total byte size of the buffer.
        virtual uint32_t getByteSize() = 0;

        //! The byte stride of the buffer.
        virtual uint32_t getByteStride() = 0;

        //! The label of the buffer.
        virtual const std::string& getLabel() = 0;

        //! Initialize the buffer.
        //! @param data The data to initialize the buffer with.
        //! @param byteSize The size of the buffer in bytes.
        //! @param strideInBytes The stride in bytes.
        //! @param instanceCount The number of instances.
        virtual void initialize(const void *data,
            uint32_t byteSize,
            uint32_t strideInBytes,
            uint32_t instanceCount) = 0;

        //! Destroys the buffer and frees the memory.
        virtual void destroy() = 0;
    };
}

#endif //A_INSTANCE_BUFFER_H
