//
// Created by Erkapic Luka on 23.2.2025.
//

#include "core/mesh/MeshFactory.h"

namespace mars {

    MeshFactory::MeshFactory(Framework &framework)
        : framework(framework) {
    }

    std::shared_ptr<Mesh> MeshFactory::create(const Geometry &geometry, GeometryFormat format) {
        auto mesh = std::make_shared<Mesh>(framework);
        mesh->setGeometry(geometry, format);
        return mesh;
    }
}
