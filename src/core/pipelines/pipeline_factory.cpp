//
// Created by Erkapic Luka on 09.02.25.
//

#include <stdexcept>
#include "Framework.h"
#include "core/pipelines/pipeline_factory.h"
#include "opengles/pipelines/test/opengles_triangle_test_pipeline.h"
#include "opengles/pipelines/lines/OpenGLESLinesRenderPipeline.h"
#include "opengles/pipelines/sprite/opengles_sprite_render_pipeline.h"
#include "opengles/pipelines/test/opengles_position_color_test_pipeline.h"
#include "opengles/pipelines/test/opengles_texture_test_pipeline.h"

#if __APPLE__
#include "metal/pipelines/test/metal_triangle_test_pipeline.h"
#include "metal/pipelines/test/metal_position_color_test_pipeline.h"
#include "metal/pipelines/test/metal_texture_test_pipeline.h"
#endif

#if _WIN32
#include "dx11/pipelines/test/dx11_triangle_test_pipeline.h"
#include "dx11/pipelines/test/dx11_position_color_test_pipeline.h"
#include "dx11/pipelines/test/dx11_texture_test_pipeline.h"
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

	std::shared_ptr<ATriangleTestPipeline> PipelineFactory::createTriangleTestPipeline() const {
		switch (framework.getRenderingBackend()) {
#if __APPLE__
		case RenderingBackend::Metal:
			return std::make_shared<MetalTriangleTestPipeline>(framework);
#endif 
#if _WIN32
		case RenderingBackend::D3D11:
			return std::make_shared<DX11TriangleTestPipeline>(framework);
#endif 
		case RenderingBackend::OpenGLES:
			return std::make_shared<OpenGLESTriangleTestPipeline>(framework);
		default:
			const std::string msg = "Rendering backend not supported.";
			framework.getLogger().error(msg);
			throw std::runtime_error(msg);
		}
	}

	std::shared_ptr<APositionColorTestPipeline> PipelineFactory::createPositionColorTestPipeline() const {
		switch (framework.getRenderingBackend()) {
#if __APPLE__
		case RenderingBackend::Metal:
            return std::make_shared<MetalPositionColorTestPipeline>(framework);
#endif
#if _WIN32
		case RenderingBackend::D3D11:
			return std::make_shared<DX11PositionColorTestPipeline>(framework);
#endif 
		case RenderingBackend::OpenGLES:
			return std::make_shared<OpenGLESPositionColorTestPipeline>(framework);
		default:
			const std::string msg = "Rendering backend not supported.";
			framework.getLogger().error(msg);
			throw std::runtime_error(msg);
		}
	}

	std::shared_ptr<ATextureTestPipeline> PipelineFactory::createTextureTestPipeline() const {
		switch (framework.getRenderingBackend()) {
#if __APPLE__
			case RenderingBackend::Metal:
				return std::make_shared<MetalTextureTestPipeline>(framework);
#endif
#if _WIN32
			case RenderingBackend::D3D11:
				return std::make_shared<DX11TextureTestPipeline>(framework);

#endif
			case RenderingBackend::OpenGLES:
				return std::make_shared<OpenGLESTextureTestPipeline>(framework);
			default:
				const std::string msg = "Rendering backend not supported.";
				framework.getLogger().error(msg);
				throw std::runtime_error(msg);
		}
	}
}
