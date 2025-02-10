//
// Created by luka on 09.02.25.
//

#ifndef ASPRITERENDERPIPELINE_H
#define ASPRITERENDERPIPELINE_H


#include "core/texture/Texture2D.h"
#include "core/buffers/AVertexBuffer.h"
#include "core/buffers/AIndexBuffer.h"

namespace mars
{
    //! The render pipeline for working with sprites.
    class ASpriteRenderPipeline
    {
    public:
        virtual ~ASpriteRenderPipeline() = default;
        //! Get the current texture.
        virtual Texture2D* getSpriteTexture() = 0;

        //! Sets the current texture.
        //! @param spriteTexture The texture to set.
        virtual void setSpriteTexture(Texture2D* spriteTexture) = 0;

        //! Draws the pipeline.
        //! @param vertexBuffer The vertex buffer.
        //! @param indexBuffer The index buffer.
        //! @param indicesCount The number of indices to draw. If <code>-1</code> draws all indices.
        //! @param indicesOffset Indices offset. By default, it is <code>0</code> for no offset.
        virtual void render(
            AVertexBuffer* vertexBuffer,
            AIndexBuffer* indexBuffer,
            uint32_t indicesCount = -1,
            uint32_t indicesOffset = 0) = 0;

        //! Destroys the pipeline.
        virtual void destroy() = 0;
    };
}

#endif //ASPRITERENDERPIPELINE_H
