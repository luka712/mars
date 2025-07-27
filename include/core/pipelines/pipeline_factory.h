//
// Created by Erkapic Luka on 09.02.25.
//

#ifndef PIPELINE_FACTORY_H
#define PIPELINE_FACTORY_H

#include <memory>

#include "core/pipelines/sprite/ASpriteRenderPipeline.h"
#include "core/pipelines/lines/ALinesRenderPipeline.h"
#include "core/pipelines/test/a_triangle_test_pipeline.h"
#include "core/pipelines/test/a_position_color_test_pipeline.h"
#include "core/camera/core/OrthographicCamera.h"
#include "core/renderer/enums.h"
#include "core/pipelines/test/a_texture_test_pipeline.h"

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

        //! Creates a test pipeline that renders simple triangle centered around origin,
        //! NOTE: Intended to be used for test purposes only.
        //! @return The shared pointer for ATriangleTestPipeline.
        std::shared_ptr<ATriangleTestPipeline> createTriangleTestPipeline() const;

        //! Creates a test pipeline that renders that uses buffer object that takes position and color attributes,
        //! NOTE: Intended to be used for test purposes only.
        //! @return The shared pointer for ATriangleTestPipeline.
        std::shared_ptr<APositionColorTestPipeline> createPositionColorTestPipeline() const;

        //! Create a text pipeline which allows texture to be used.
        //! NOTE: Intended to be used for test purposes only.
        //! @return The shared pointer for ATextureTestPipeline.
        std::shared_ptr<ATextureTestPipeline> createTextureTestPipeline() const;

    private:
        Framework &framework;
    };
}


#endif //PIPELINE_FACTORY_H
