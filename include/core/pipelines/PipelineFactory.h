//
// Created by luka on 09.02.25.
//

#ifndef PIPELINEFACTORY_H
#define PIPELINEFACTORY_H

#include <memory>
#include "core/pipelines/sprite/ASpriteRenderPipeline.h"
#include "core/camera/core/OrthographicCamera.h"
#include "core/renderer/enums.h"

namespace mars {

    class Framework;

    //! The pipeline factory.
    class PipelineFactory {

      public:
        explicit PipelineFactory(Framework& framework);

        std::shared_ptr<ASpriteRenderPipeline> createSpriteRenderPipeline(
            OrthographicCamera* camera,
            Culling culling = Culling::Back) const;

        private:
          Framework& framework;
    };

}



#endif //PIPELINEFACTORY_H
