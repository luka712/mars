//
// Created by Luka on 23.2.2025.
//

#ifndef GEOMETRY_BUILDER_H
#define GEOMETRY_BUILDER_H

#include <memory>

#include "core/geometry/Geometry.h"

namespace mars {
    //! The geometry builder.
    class GeometryBuilder {

    public:
        //! Creates the geometry of a quad.
        //! @return The geometry of a quad.
        std::shared_ptr<Geometry> quadGeometry();

    };
}

#endif //GEOMETRY_BUILDER_H
