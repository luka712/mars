//
// Created by lukaa on 29.11.2024..
//

#ifndef SPRITEBATCHMESH_H
#define SPRITEBATCHMESH_H

#include "core/mesh/Mesh.h"
#include <glm/glm.hpp>

namespace mars {
    class Framework;

    //! Mesh that can be used to batch and write collection of sprites.
    //! Note that changing positions, indices, colors, texture coordinates and normals will have no effect.
    class SpriteBatchMesh : public Mesh {


    public:
        //! Construct a new SpriteBatchMesh object.
        //! @param framework The framework.
        //! @param numberOfInstances The number of instances.
        SpriteBatchMesh(Framework &framework, const uint32_t numberOfInstances);

        //! The maximum number of instances that can be batched.
        [[nodiscard]] inline size_t getMaxInstances() const { return maxInstances; }

        //! @copydoc
        void initialize() override;

        //! The number of instances that are currently batched.
        void resize(size_t newSize);

        //! Write a sprite to the batch.
        //! @param instance The instance index position.
        //! @param position The position of the sprite.
        //! @param size The size of the sprite.
        void writeSprite(size_t instance, glm::vec3 position, glm::vec2 size);

    private:
        //! The number of floats components per vertex.
        //! 9 since it's build as (xyz rgba uv).
        const size_t TOTAL_FLOATS_PER_VERTEX = 9;

        //! The total number of floats in the sprite.
        //! 4 for each vertex * 9 floats per vertex (xyz rgba uv).
        const size_t TOTAL_FLOATS_IN_SPRITE = 4 * TOTAL_FLOATS_PER_VERTEX;

        std::vector<uint16_t> indices;

        size_t maxInstances;

        void setupIndices();
    };

#endif //SPRITEBATCHMESH_H
}
