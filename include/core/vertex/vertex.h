//
// Created by Luka Erkapic on 19.07.25.
//

#ifndef POSITION_COLOR_VERTEX_H
#define POSITION_COLOR_VERTEX_H

#include <glm/glm.hpp>
#include "core/math/color.h"

namespace mars {

    //! @brief PositionColorVertex represents a vertex with position and color attributes.
    struct PositionColorVertex {

        //! @brief Default constructor for PositionColorVertex.
        PositionColorVertex() = default;

        //! @brief Constructs a PositionColorVertex with the given position and color.
        //! @param position The position of the vertex in 3D space.
        //! @param color The color of the vertex.
        PositionColorVertex(const glm::vec3 position, const Color color)
            : position(position), color(color) {}

        //! @brief Position in 3D space.
        glm::vec3 position;

        //! @brief Color of the vertex.
        Color color;
    };

    //! @brief PositionColorTexCoordVertex represents a vertex with position, color and texture coordinates attributes.
    struct PositionColorTexCoordVertex {

        //! @brief Default constructor for PositionColorVertex.
        PositionColorTexCoordVertex() = default;

        //! @brief Constructs a PositionColorVertex with the given position and color.
        //! @param position The position of the vertex in 3D space.
        //! @param color The color of the vertex.
        //! @param texCoord The texture coordinate.
        PositionColorTexCoordVertex(const glm::vec3 position, const Color color, const glm::vec2 texCoord)
            : position(position), color(color), texCoord(texCoord) {}

        //! @brief Position in 3D space.
        glm::vec3 position;

        //! @brief Color of the vertex.
        Color color;

        //! @brief The texture coordinate of the vertex.
        glm::vec2 texCoord;
    };
}

#endif //POSITION_COLOR_VERTEX_H
