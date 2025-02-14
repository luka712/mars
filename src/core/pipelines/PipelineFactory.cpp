//
// Created by luka on 09.02.25.
//
#include "Framework.h"
#include "core/pipelines/PipelineFactory.h"
#include "opengles/pipelines/sprite/OpenGLESSpriteRenderPipeline.h"


namespace mars {
    PipelineFactory::PipelineFactory(Framework &framework)
        : framework(framework) {
    }


    std::shared_ptr<ASpriteRenderPipeline> PipelineFactory::createSpriteRenderPipeline(
        OrthographicCamera *camera,
        Culling culling) const {

        switch (framework.getRenderingBackend()) {
            case RenderingBackend::OpenGLES:
                return std::make_shared<OpenGLESSpriteRenderPipeline>(framework, camera, culling);
            default:
                return nullptr;
        }

        return nullptr;
    }
}
