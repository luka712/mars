//
// Created by Erkapic Luka on 09.02.25.
//

#include <stdexcept>
#include "Framework.h"
#include "core/pipelines/PipelineFactory.h"
#include "opengles/pipelines/lines/OpenGLESLinesRenderPipeline.h"
#include "opengles/pipelines/sprite/OpenGLESSpriteRenderPipeline.h"

#if __APPLE__
#include "metal/pipelines/test/metal_triangle_test_pipeline.h"
#endif

#if _WIN32
#include "dx11/pipelines/test/dx11_triangle_test_pipeline.h"
#endif 

namespace mars {
	PipelineFactory::PipelineFactory(Framework& framework)
		: framework(framework) {
	}

	std::shared_ptr<ASpriteRenderPipeline> PipelineFactory::createSpriteRenderPipeline(
		OrthographicCamera* camera,
		Culling culling) const {
		switch (framework.getRenderingBackend()) {
		case RenderingBackend::OpenGLES:
			return std::make_shared<OpenGLESSpriteRenderPipeline>(framework, camera, culling);
		default:
			const std::string msg = "Rendering backend not supported.";
			framework.getLogger().error(msg);
			throw std::runtime_error(msg);
		}

		return nullptr;
	}

	std::shared_ptr<ALinesRenderPipeline> PipelineFactory::createLinesRenderPipeline(
		AUniformBuffer& projectionViewBuffer,
		AInstanceBuffer& modelBuffer) const {



		switch (framework.getRenderingBackend()) {
		case RenderingBackend::OpenGLES:
			return  std::make_shared<OpenGLESLinesRenderPipeline>(framework, projectionViewBuffer, modelBuffer);
		default:
			const std::string msg = "Rendering backend not supported.";
			framework.getLogger().error(msg);
			throw std::runtime_error(msg);
		}
	}

	std::shared_ptr<ATriangleTestPipeline> PipelineFactory::createTriangleTestPipeline() {
		switch (framework.getRenderingBackend()) {
#if __APPLE__
		case RenderingBackend::Metal:
			return std::make_shared<MetalTriangleTestPipeline>(framework);
#endif 
#if _WIN32
		case RenderingBackend::D3D11:
			return std::make_shared<DX11TriangleTestPipeline>(framework);
#endif 
		default:
			const std::string msg = "Rendering backend not supported.";
			framework.getLogger().error(msg);
			throw std::runtime_error(msg);
		}
	}
}
