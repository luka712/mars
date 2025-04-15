//
// Created by Erkapic Luka on 3.4.2025.
//

#ifndef B2_DRAW_IMPL_H
#define B2_DRAW_IMPL_H

#include <box2d/b2_draw.h>
#include <memory>
#include <vector>
#include "core/pipelines/lines/ALinesRenderPipeline.h"
#include "core/buffers/AInstanceBuffer.h"
#include "core/life_management/State.h"

namespace mars {
    class Framework;

    ///! A Box2D debug draw implementation.
    ///! NOTE: to be used internally only.
    class b2DrawImpl final : public b2Draw {
    public:
        //! Construct a new b2DrawImpl object.
        explicit b2DrawImpl(Framework &framework);

        //! Initialize the debug draw.
        void initialize();

        void DrawPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color) override;

        void DrawSolidPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color) override;

        void DrawCircle(const b2Vec2 &center, float radius, const b2Color &color) override;

        void DrawSolidCircle(const b2Vec2 &center, float radius, const b2Vec2 &axis, const b2Color &color) override;

        void DrawSegment(const b2Vec2 &p1, const b2Vec2 &p2, const b2Color &color) override;

        void DrawTransform(const b2Transform &xf) override;

        void DrawPoint(const b2Vec2 &p, float size, const b2Color &color) override;

        //! Draws the content to the screen.
        //! All other methods "Draw" methods just fill the vertexData buffer.
        void render();

    private:
        static const int32_t VERTEX_FLOATS;
        static const int32_t MAX_VERTICES;
        Framework &framework;
        State currentState{CREATED};
        uint32_t currentVertexCount;
        uint32_t vertexDataIndex;
        std::vector<float> vertexData;
        std::shared_ptr<ALinesRenderPipeline> pipeline;
        std::shared_ptr<AInstanceBuffer> modelBuffer;
        std::shared_ptr<AVertexBuffer> vertexBuffer;

        //! Add a vertex to the vertex data.
        //! @param a The vertex position.
        //! @param color The vertex color.
        void addVertex(const b2Vec2 &a, const b2Color &color);
    };
}

#endif //B2_DRAW_IMPL_H
