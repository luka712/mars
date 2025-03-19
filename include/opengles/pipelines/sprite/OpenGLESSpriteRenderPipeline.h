
//
// Created by Erkapic Luka on 10.02.25.
//

#ifndef OPEN_GLES_SPRITE_RENDER_PIPELINE_H
#define OPEN_GLES_SPRITE_RENDER_PIPELINE_H

#include <core/renderer/enums.h>
#include "opengles/opengles.h"
#include "core/pipelines/sprite/ASpriteRenderPipeline.h"
#include "opengles/renderer/OpenGLESRenderer.h"
#include "core/camera/core/OrthographicCamera.h"
#include "opengles/texture/OpenGLESTexture2D.h"

namespace mars {
    class Framework;

    //! The OpenGLES implementation of @ref ASpriteRenderPipeline.
    class OpenGLESSpriteRenderPipeline : public ASpriteRenderPipeline {
    public:
        //! The constructor.
        //! @param framework The framework.
        //! @param camera The orthographic camera.
        //! @param culling The culling, by default it is `Culling::Back`.
        explicit OpenGLESSpriteRenderPipeline(
            Framework &framework,
            OrthographicCamera *camera,
            Culling culling = Culling::Back);

        //! @inheritDoc
        Texture2D *getSpriteTexture() override { return texture; }

        //! @inheritDoc
        void setSpriteTexture(Texture2D *spriteTexture) override;

        //! @inheritDoc
        void render(
            AVertexBuffer *vertexBuffer,
            AIndexBuffer *indexBuffer,
            uint32_t indicesCount,
            uint32_t indicesOffset) override;

        //! @inheritDoc
        void destroy() override;

    private:
        Framework &framework;
        OpenGLESRenderer *renderer;
        OrthographicCamera *camera;
        Culling culling;

        GLuint glProgram{};
        GLuint glVao{};
        GLuint glLastVertexBuffer{};
        GLint glProjectionViewMatrixLocation;
        OpenGLESTexture2D *texture{};

        void createProgram();
        void createVao(GLuint vertexBuffer);
    };
}


#endif //OPEN_GLES_SPRITE_RENDER_PIPELINE_H
