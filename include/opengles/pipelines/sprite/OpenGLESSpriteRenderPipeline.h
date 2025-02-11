//
// Created by luka on 10.02.25.
//

#ifndef OPENGLESSPRITERENDERPIPELINE_H
#define OPENGLESSPRITERENDERPIPELINE_H

#include "core/pipelines/sprite/ASpriteRenderPipeline.h"
#include "opengles/renderer/OpenGLESRenderer.h"

namespace mars
{
    class Framework;

    class OpenGLESSpriteRenderPipeline : public ASpriteRenderPipeline {
    public:

        //! The OPENGLES sprite render pipeline constructor.
        explicit OpenGLESSpriteRenderPipeline(Framework &framework);

        //! @inheritDoc
        void render(
            AVertexBuffer *vertexBuffer,
            AIndexBuffer *indexBuffer,
            uint32_t indicesCount,
            uint32_t indicesOffset) override;

    private:
        OpenGLESRenderer &renderer;
    };
}


#endif //OPENGLESSPRITERENDERPIPELINE_H
