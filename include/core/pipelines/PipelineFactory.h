//
// Created by luka on 09.02.25.
//

#ifndef PIPELINE_FACTORY_H
#define PIPELINE_FACTORY_H

#include <memory>
#include "core/pipelines/sprite/ASpriteRenderPipeline.h"
#include "core/pipelines/lines/ALinesRenderPipeline.h"
#include "core/camera/core/OrthographicCamera.h"
#include "core/renderer/enums.h"

namespace mars {
    class Framework;

    //! The pipeline factory.
    class PipelineFactory {
    public:
        explicit PipelineFactory(Framework &framework);

        //! Create a new lines render pipeline.
        //! @param camera The orthographic camera.
        //! @param culling The culling, by default it is `Culling::Back`.
        std::shared_ptr<ASpriteRenderPipeline> createSpriteRenderPipeline(
            OrthographicCamera *camera,
            Culling culling = Culling::Back) const;

        //! Create a new line render pipeline.
        //! @param projectionViewBuffer The projection view buffer.
        //! @param modelBuffer The model buffer.
        std::shared_ptr<ALinesRenderPipeline> createLinesRenderPipeline(
            AUniformBuffer &projectionViewBuffer,
            AInstanceBuffer &modelBuffer) const;

    private:
        Framework &framework;
    };
}


#endif //PIPELINE_FACTORY_H
