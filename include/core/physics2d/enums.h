//
// Created by Erkapic Luka on 8.3.2025.
//

#ifndef PHYSICS_ENUMS_H
#define PHYSICS_ENUMS_H

namespace mars {

    //! The 2D physics body type.
    enum class BodyType2D {
        /// Zero mass, zero velocity, may be manually moved.
        StaticBody,

        /// Zero mass, non-zero velocity set by user, moved by solver.
        KinematicBody,

        /// Positive mass, non-zero velocity determined by forces, moved by solver.
        DynamicBody,
    };

}

#endif //PHYSICS_ENUMS_H
