//
// Created by Erkapic Luka on 23.2.2025.
//


#include <memory>

#include "core/geometry/GeometryBuilder.h"

namespace mars {
    std::shared_ptr<Geometry> GeometryBuilder::quadGeometry() {

        std::shared_ptr<Geometry> geometry = std::make_shared<Geometry>();
        geometry->setVertexCount(4);
        geometry->setPositions({
            -0.5f, -0.5f, 0.0f, // bottom left
            -0.5f, 0.5f, 0.0f, // top left
            0.5f, -0.5f, 0.0f, // bottom right
            0.5f, 0.5f, 0.0f, // top right
        });
        geometry->setIndices({
            3, 2, 0, // t1
            0, 1, 3 // t2
        });
        geometry->setColors({
            1, 1, 1, 1,
            1, 1, 1, 1,
            1, 1, 1, 1,
            1, 1, 1, 1
        });
        geometry->setTextureCoords({
            0, 1, // bottom left
            0, 0, // top left
            1, 1, // bottom right
            1, 0 // top right
        });
        geometry->setNormals({
            0, 0, 1,
            0, 0, 1,
            0, 0, 1,
            0, 0, 1
        });

        return geometry;
    }

}
