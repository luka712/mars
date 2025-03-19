//
// Created by Erkapic Luka on 18.3.2025.
//

#ifndef A_LINES_RENDER_PIPELINE_H
#define A_LINES_RENDER_PIPELINE_H

#include "core/math/Color.h"
#include "core/buffers/AVertexBuffer.h"

namespace mars {
    //! Simple pipeline for drawing lines.
    class ALinesRenderPipeline {
    public:
        virtual ~ALinesRenderPipeline() = default;

        //! The color of the lines.
        [[nodiscard]] virtual Color getColor() const = 0;

        //! Set the color of the lines.
        //! @param color The color of the lines.
        virtual void setColor(const Color &color) = 0;

        //! Initialize the pipeline.
        virtual void initialize() = 0;

        //! Render the lines.
        //! <p>Expects a vertex buffer with positions and colors in format (xyz + rgba).</p>
        //! @param vertexBuffer The vertex buffer.
        virtual void render(AVertexBuffer &vertexBuffer) = 0;

        //! Render the lines.
        //! <p>Expects a vertex buffer with positions and colors in format (xyz + rgba).</p>
        //! @param vertexBuffer The vertex buffer.
        //! @param instanceCount The number of instances to render.
        //! @param vertexCount The number of vertices to render. If <code>-1</code>, uses <code>AVertexBuffer::getVertexCount()</code>.
        virtual void render(AVertexBuffer &vertexBuffer, uint32_t instanceCount, uint32_t vertexCount) = 0;
    };
}

#endif //A_LINES_RENDER_PIPELINE_H
