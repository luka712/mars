#include "Framework.h"
#include "box2d/physics2d/draw/b2DrawImpl.h"
#include "glm/mat4x4.hpp"
#include <iostream>

namespace mars {
    const int32_t b2DrawImpl::VERTEX_FLOATS = 7;
    const int32_t b2DrawImpl::MAX_VERTICES = 1000;

    b2DrawImpl::b2DrawImpl(Framework &framework)
        : framework(framework) {
        vertexData = std::vector<float>(VERTEX_FLOATS * MAX_VERTICES);
        currentVertexCount = 0;
        vertexDataIndex = 0;

        // Set flags for what to draw (shapes, joints, etc.)
        SetFlags(e_shapeBit | e_jointBit);
    }

    void b2DrawImpl::initialize() {
        // - VERTEX BUFFER
        vertexBuffer = framework.getBuffersFactory().createVertexBuffer(
            vertexData,
            MAX_VERTICES,
            BufferUsage::Vertex_CopyDst,
            "b2DrawImpl.vertexBuffer");

        // - MODEL BUFFER
        constexpr auto identityMatrix = glm::mat4(1.0f);
        modelBuffer = framework.getBuffersFactory().createInstanceBuffer(
            &identityMatrix,
            sizeof(glm::mat4),
            sizeof(glm::mat4),
            1,
            "b2DrawImpl.modelBuffer");

        // - PIPELINE
        const auto camera = framework.getSpriteBatch().getCamera();
        pipeline = framework.getPipelineFactory().createLinesRenderPipeline(
            camera.getProjectionViewBuffer(),
            *modelBuffer.get());

        currentState = INITIALIZED;
    }

    void b2DrawImpl::addVertex(const b2Vec2 &a, const b2Color &color) {
        vertexData[vertexDataIndex++] = a.x;
        vertexData[vertexDataIndex++] = a.y;
        vertexData[vertexDataIndex++] = 0.0;
        vertexData[vertexDataIndex++] = color.r;
        vertexData[vertexDataIndex++] = color.g;
        vertexData[vertexDataIndex++] = color.b;
        vertexData[vertexDataIndex++] = color.a;
        currentVertexCount++;
    }

    void b2DrawImpl::DrawPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color) {
        for (int32 i = 0; i < vertexCount - 1; i++) {
            b2Vec2 a = vertices[i];
            b2Vec2 b = vertices[i+1];

            addVertex(a, color);
            addVertex(b, color);
        }

        // We need to wrap around the last vertex to the first vertex.
        const b2Vec2 a = vertices[vertexCount - 1];
        const b2Vec2 b = vertices[0];
        addVertex(a, color);
        addVertex(b, color);
    }

    void b2DrawImpl::DrawSolidPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color) {
        for (int32 i = 0; i < vertexCount - 1; i++) {
            b2Vec2 a = vertices[i];
            b2Vec2 b = vertices[i+1];

            addVertex(a, color);
            addVertex(b, color);
        }

        // We need to wrap around the last vertex to the first vertex.
        const b2Vec2 a = vertices[vertexCount - 1];
        const b2Vec2 b = vertices[0];
        addVertex(a, color);
        addVertex(b, color);
    }

    void b2DrawImpl::DrawCircle(const b2Vec2 &center, float radius, const b2Color &color) {
        std::cout << "DrawCircle" << std::endl;
    }

    void b2DrawImpl::DrawSolidCircle(const b2Vec2 &center, float radius, const b2Vec2 &axis, const b2Color &color) {
        std::cout << "DrawCircle" << std::endl;
    }

    void b2DrawImpl::DrawSegment(const b2Vec2 &p1, const b2Vec2 &p2, const b2Color &color) {
        std::cout << "DrawCircle" << std::endl;
    }

    void b2DrawImpl::DrawTransform(const b2Transform &xf) {
        std::cout << "DrawCircle" << std::endl;
    }

    void b2DrawImpl::DrawPoint(const b2Vec2 &p, float size, const b2Color &color) {
        std::cout << "DrawCircle" << std::endl;
    }

    void b2DrawImpl::render() {

        if (currentState != INITIALIZED) {

            const std::string msg = "b2DrawImpl::render() cannot be called before initialize() is called.";
            framework.getLogger().error(msg);
            throw std::runtime_error(msg);
        }

        vertexBuffer->update(vertexData.data(), currentVertexCount * VERTEX_FLOATS * sizeof(float), 0);
        pipeline->render(*vertexBuffer.get(), 1, currentVertexCount);
        currentVertexCount = 0;
        vertexDataIndex = 0;
    }
}
