//
// Created by Erkapic Luka on 8.7.2025.
//

#ifndef A_POSITION_COLOR_TEST_PIPELINE_H
#define A_POSITION_COLOR_TEST_PIPELINE_H

#include "core/buffers/a_vertex_buffer.h"
#include "core/buffers/a_index_buffer.h"

namespace mars {
    //! The test pipeline for rendering rendering a simple mesh with position and color attributes.
    //! Mainly used for testing purposes.
    class APositionColorTestPipeline {
    public:
        //! The destructor.
        virtual ~APositionColorTestPipeline() = default;

        //! Render the triangle from the pipeline.
        //! @param vertexBuffer The vertex buffer containing the position and color attributes.
        virtual void render(AVertexBuffer& vertexBuffer) = 0;

        //! Render the triangle from the pipeline.
        //! @param vertexBuffer The vertex buffer containing the position and color attributes.
        //! @param indexBuffer The index buffer containing the indices to render the mesh.
        virtual void render(AVertexBuffer& vertexBuffer, AIndexBuffer& indexBuffer) = 0;

        //! Destroys the pipeline.
        virtual void destroy() = 0;
    };
}

#endif //A_POSITION_COLOR_TEST_PIPELINE_H
