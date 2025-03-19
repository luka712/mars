//
// Created by Erkapic Luka on 1.2.2025.
//

#ifndef COLLISION2D_SYSTEM_H
#define COLLISION2D_SYSTEM_H

#include <vector>
#include <ecs/camera/Camera2D.h>
#include "ecs/collision/Collider2D.h"
#include "core/pipelines/lines/ALinesRenderPipeline.h"


namespace mars {
    class Framework;

    //! The system that handles 2D collisions.
    class Collision2DSystem {

    public:
        //! Construct a new Collision2DSystem object.
        //! @param framework The framework.
        explicit Collision2DSystem(Framework &framework);

        //! Initialize the system.
        void initialize();

        //! Add a collider component to the system.
        //! @param collider The Collider2D component.
        void add(Collider2D *collider);

        //! Remove a collider component from the system.
        //! @param collider The Collider2D component.
        void remove(const Collider2D *collider);

        //! Update the script components.
        //! @param time The game time.
        void update(const Time &time);

        //! Render the sprite components.
        void render(Camera2D& camera);

    private:
        Framework &framework;
        std::vector<Collider2D *> colliders;
        std::vector<float> vertexData;
        std::shared_ptr<AVertexBuffer> vertexBuffer;
        std::shared_ptr<AInstanceBuffer> modelBuffer{};
        std::shared_ptr<ALinesRenderPipeline> linesRenderPipeline{};

        //! Add a line to the vertex buffer data.
        //! @param start The start of the line.
        //! @param end The end of the line.
        //! @param color The color of the line.
        //! @param index The index of data buffer.
        void addLine(const glm::vec2 &start, const glm::vec2 &end, const Color &color, size_t* index);
    };
};


#endif //COLLISION2D_SYSTEM_H
