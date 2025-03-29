//
// Created by Erkapic Luka on 27.3.2025.
//

#ifndef RIGID_BODY_2D_H
#define RIGID_BODY_2D_H

#include "ecs/transform/RectTransform.h"
#include "ecs/physics2d/ACollider2D.h"
#include "core/physics2d/body/ABody2D.h"

namespace mars {
    class Physics2DSystem;

    //! The physics 2D body component.
    class RigidBody2D : public AComponent {
    public:
        //! Construct a new Body2D object.
        //! @param entity The entity that the component is attached to.
        explicit RigidBody2D(Entity *entity);

        //! @copydoc
        void initialize() override;

        //! Create the body.
        //! NOTE: This should never be called except when assigned to system. In other words, only Physics2DSystem should call this.
        void createBodyOnSelf(const Physics2DSystem &system);

        //! @copydoc
        void update(const Time &time) override;

    private:
        RectTransform *rectTransform;
        ACollider2D *collider;
        std::shared_ptr<ABody2D> body;

        //! Try to find the collider.
        //! @return The collider if found, otherwise nullptr.
        [[nodiscard]] ACollider2D* tryFindCollider() const;
    };
}

#endif //RIGID_BODY_2D_H
