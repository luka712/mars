//
// Created by Erkapic Luka on 23.2.2025.
//

#ifndef MESH_FACTORY_H
#define MESH_FACTORY_H

#include "core/mesh/Mesh.h"

namespace mars {
    class Framework;

    //! The mesh factory class.
    class MeshFactory {
    public:
        //! The mesh factory constructor.
        //! @param framework The framework.
        explicit MeshFactory(Framework &framework);

        //! Create a mesh.
        //! @param geometry The geometry.
        //! @param format The geometry format.
        //! @return The mesh.
        std::shared_ptr<Mesh> create(const Geometry &geometry, GeometryFormat format);

    private:
        Framework &framework;
    };
}

#endif //MESH_FACTORY_H
