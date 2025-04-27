#define NS_PRIVATE_IMPLEMENTATION
#define CA_PRIVATE_IMPLEMENTATION
#define MTL_PRIVATE_IMPLEMENTATION

// NOTE: MUST BE INCLUDED IN ONE CPP FILE
#include <Foundation/Foundation.hpp>
#include <Metal/Metal.hpp>
#include <QuartzCore/QuartzCore.hpp>

#include <SDL.h>
#include <format>
#include "Framework.h"
#include "metal/renderer/MetalRenderer.h"

namespace mars {
    static Logger *staticLogger = nullptr;


    MetalRenderer::MetalRenderer(Framework &framework, const glm::vec2 frameBufferSize)
        : Renderer(framework), window(nullptr), device(nullptr) {
        this->frameBufferSize = frameBufferSize;
    }

    void MetalRenderer::initialize() {

        window = framework.getWindowManager().getWindow();
        Logger &logger = framework.getLogger();
        staticLogger = &logger;

        const CA::MetalLayer* metalLayer = framework.getWindowManager().getMetalLayer();
        device = MTL::CreateSystemDefaultDevice();
        const NS::String *nsDeviceName = device->name();
        const auto deviceName = std::string(nsDeviceName->cString(NS::StringEncoding::ASCIIStringEncoding));
        logger.info("Retrieved Metal device: " + deviceName);

    }

    void MetalRenderer::beginRenderPass() {

    }

    void MetalRenderer::endRenderPass() {
    }

    void MetalRenderer::destroy() {
    }
}
