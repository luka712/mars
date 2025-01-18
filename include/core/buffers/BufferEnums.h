//
// Created by lukaa on 18.1.2025..
//

#ifndef BUFFERENUMS_H
#define BUFFERENUMS_H

namespace mars {
    enum class BufferUsage {
        //! No buffer usage is defined.
        None,

        //! The buffer is used for storing vertex data.
        //! Corresponding binding in WGPU is WGPU_VERTEX.
        Vertex,

        //! The buffer is used for storing index data.
        //! Corresponding binding in WGPU is WGPU_INDEX.
        Index,

        //! The buffer is used for storing uniform or constant data.
        //! Corresponding binding in WGPU is WGPU_UNIFORM.
        Uniform,

        //! Buffer is used as destination for copying data.
        //! Common use case if for writing data to a buffer.
        //! Corresponding binding in WGPU is WGPU_COPY_DST.
        CopyDst,

        //! Combination of @ref BufferUsage::Vertex and @ref BufferUsage::CopyDst.
        //! Example usage, is for vertex buffer that needs to be written to.
        Vertex_CopyDst,
    };

    //! The type of index buffer.
    enum class IndexBufferType {

        //! Indices are 2 bytes unsigned integers.
        Uint16,
        //! Indices are 4 bytes unsigned integers.
        Uint32
    };
}

#endif //BUFFERENUMS_H
