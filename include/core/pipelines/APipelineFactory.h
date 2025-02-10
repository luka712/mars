//
// Created by luka on 09.02.25.
//

#ifndef APIPELINEFACTORY_H
#define APIPELINEFACTORY_H

#include <memory>
#include <core/pipelines/sprite/ASpriteRenderPipeline.h>

namespace mars {

    //! The pipeline factory.
    class APipelineFactory {

      public:
        std::shared_ptr<ASpriteRenderPipeline> createSpriteRenderPipeline();

    };

}



#endif //APIPELINEFACTORY_H
