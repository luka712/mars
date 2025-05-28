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

        //! Allows buffer to be mapped for writing.
        //! Common use in case of mapping CPU data directly to the GPU buffer.
        //! Corresponding binding in WGPU is WGPU_MAP_WRITE.
        //! If metal has this flag, buffer will be created with MTL::ResourceStorageModeShared to allow access to both CPU and GPU.
        MapWrite,

        //! Combination of @ref BufferUsage::Vertex and @ref BufferUsage::CopyDst.
        //! Example usage, is for vertex buffer that needs to be written to.
        Vertex_CopyDst,

        //! Combination of @ref BufferUsage::Uniform and @ref BufferUsage::MapWrite.
        //! Example usage, is for uniform buffer where CPU data is mapped to the GPU.
        //! In Metal this will result in synchronization while writing CPU data to the GPU.
        //! In WebGPU this means that <code>MapAsync</code> is called which may or may not stall CPU.
        //! Depending on, if we're waiting or allowing it to be async.
        Uniform_MapWrite,
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
