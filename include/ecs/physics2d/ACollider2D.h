//
// Created by Erkapic Luka on 27.3.2025.
//

#ifndef COLLIDER2D_H
#define COLLIDER2D_H

#include "box2d/physics2d/shape/ABox2DShape.h"
#include "ecs/components/AComponent.h"

namespace mars {

    class Entity;

    //! The physics 2D collider component.
    class ACollider2D : public AComponent {
    public:
        //! Construct a new Collider2D object.
        //! @param entity The entity that the component is attached to.
        explicit ACollider2D(Entity *entity);

        //! Get the shape.
        //! @return The shape.
        [[nodiscard]] virtual ABox2DShape* getShape() = 0;
    };
}

#endif //COLLIDER2D_H
