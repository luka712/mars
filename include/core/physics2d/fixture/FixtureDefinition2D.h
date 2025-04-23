//
// Created by Erkapic Luka on 8.3.2025.
//

#ifndef FIXTURE_DEFINITION_2D_H
#define FIXTURE_DEFINITION_2D_H

#include "core/physics2d/shape/AShape2D.h"

namespace mars {

//! The 2D fixture definition.
struct FixtureDefinition2D {

    //! The shape.
    AShape2D* shape;

    //! The friction coefficient, usually in the range [0,1].
    float friction;

    //! The density, usually in kg/m^2.
    float density;
};

}

#endif //FIXTURE_DEFINITION_2D_H
