
#if __APPLE__

#define NS_PRIVATE_IMPLEMENTATION
#define CA_PRIVATE_IMPLEMENTATION
#define MTL_PRIVATE_IMPLEMENTATION

// NOTE: MUST BE INCLUDED IN ONE CPP FILE
#include <Foundation/Foundation.hpp>
#include <Metal/Metal.hpp>
#include <QuartzCore/QuartzCore.hpp>

#include <format>
#include "Framework.h"
#include "metal/util/metal_util.h"
#include "metal/renderer/metal_renderer.h"

namespace mars {
    static Logger *staticLogger = nullptr;


    MetalRenderer::MetalRenderer(Framework &framework, const glm::vec2 frameBufferSize)
        : Renderer(framework), window(nullptr), metalLayer(nullptr), currentDrawable(nullptr), device(nullptr),
          queue(nullptr),
          renderCommandBuffer(nullptr), renderCommandEncoder(nullptr) {
        this->frameBufferSize = frameBufferSize;
    }

    void MetalRenderer::initialize() {

        window = framework.getWindowManager().getWindow();
        Logger &logger = framework.getLogger();
        staticLogger = &logger;

        MetalUtil::initialize(logger);

        metalLayer = framework.getWindowManager().getMetalLayer();
        device = CreateSystemDefaultDevice();
        const NS::String *nsDeviceName = device->name();
        const auto deviceName = std::string(nsDeviceName->cString(NS::StringEncoding::ASCIIStringEncoding));
        logger.info("Retrieved Metal device: " + deviceName);

        // Get queue
        queue = device->newCommandQueue();

    }

    void MetalRenderer::setupNewRenderPass() {

        // COMMAND BUFFER
        renderCommandBuffer = queue->commandBuffer();

        // - RENDER PASS
        currentDrawable = metalLayer->nextDrawable();
        MTL::RenderPassDescriptor *descriptor = MTL::RenderPassDescriptor::renderPassDescriptor();

        // Get the texture from current surface
        const MTL::Texture* surfaceTexture = currentDrawable->texture();

        // Setup color attachments.
        MTL::RenderPassColorAttachmentDescriptor *colorAttachment = descriptor
            ->colorAttachments()
            ->object(0);
        colorAttachment->setClearColor(MTL::ClearColor(
            clearColor.r,
            clearColor.g,
            clearColor.b,
            clearColor.a)
        );
        colorAttachment->setLoadAction(MTL::LoadAction::LoadActionClear);
        colorAttachment->setStoreAction(MTL::StoreAction::StoreActionStore);
        colorAttachment->setTexture(surfaceTexture);

        // RENDER COMMAND ENCODER
        renderCommandEncoder = renderCommandBuffer->renderCommandEncoder(descriptor);
        NS::String* label = NS::String::string("Render Pass", NS::StringEncoding::ASCIIStringEncoding);
        renderCommandEncoder->setLabel(label);

        // VIEWPORT
        renderCommandEncoder->setViewport(MTL::Viewport(
            0,
            0,
            frameBufferSize.x,
            frameBufferSize.y)
        );

        // SCISSOR RECT
        renderCommandEncoder->setScissorRect(MTL::ScissorRect(
            0,
            0,
            static_cast<NS::Integer>(frameBufferSize.x),
            static_cast<NS::Integer>(frameBufferSize.y))
        );

        // RELEASE
        descriptor->release();
        label->release();
    }


    void MetalRenderer::beginRenderPass() {

        setupNewRenderPass();
    }

    void MetalRenderer::endRenderPass() {
        renderCommandEncoder->endEncoding();
        renderCommandBuffer->presentDrawable(currentDrawable);
        renderCommandBuffer->commit();
        renderCommandBuffer->waitUntilCompleted();

        renderCommandEncoder->release();
    }

    void MetalRenderer::destroy() {
    }

    MetalRenderer& toMetalRenderer(Renderer& renderer) {
        return *dynamic_cast<MetalRenderer*>(&renderer);
    }
}

#endif