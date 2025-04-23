//
// Created by Erkapic Luka on 29.3.2025.
//

#ifndef BOX_COLLIDER2D_H
#define BOX_COLLIDER2D_H

#include <memory>
#include "ecs/physics2d/ACollider2D.h"
#include "box2d/physics2d/shape/Box2DPolygonShape.h"
#include "ecs/transform/RectTransform.h"


namespace mars {
    class Entity;

    //! The physics 2D box collider component.
    class BoxCollider2D final : public ACollider2D {
    public:
        //! Construct a new BoxCollider2D object.
        //! @param entity The entity that the component is attached to.
        explicit BoxCollider2D(Entity *entity);

        //! @copydoc
        AShape2D *getShape() override;

        //! @copydoc
        void initialize() override;

    private:
        std::shared_ptr<Box2DPolygonShape> shape;
        RectTransform *rectTransform;
    };
}

#endif //BOX_COLLIDER2D_H
