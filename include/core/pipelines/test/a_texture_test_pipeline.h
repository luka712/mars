//
// Created by Erkapic Luka on 27.07.25.
//

#ifndef A_TEXTURE_TEST_PIPELINE_H
#define A_TEXTURE_TEST_PIPELINE_H

#include "core/buffers/a_vertex_buffer.h"
#include "core/buffers/a_index_buffer.h"
#include "core/texture/a_texture2d.h"

namespace mars {
    //! The test pipeline for rendering a simple mesh with position and color attributes.
    //! Mainly used for testing purposes.
    class ATextureTestPipeline {
    public:
        //! The destructor.
        virtual ~ATextureTestPipeline() = default;

        //! Gets the texture.
        //! @return The texture 2d.
        virtual ATexture2D* getTexture2D() = 0;

        //! Sets the texture.
        //! @param texture The texture.
        virtual void setTexture2D(ATexture2D* texture) = 0;

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

#endif //A_TEXTURE_TEST_PIPELINE_H
