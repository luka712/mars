//
// Created by Erkapic Luka on 27.3.2025.
//

#ifndef RIGID_BODY_2D_H
#define RIGID_BODY_2D_H

#include "core/physics2d/enums.h"
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

        //! Get the body type.
        //! @return The body type.
        [[nodiscard]] BodyType2D getType() const { return bodyType; }

        //! Set the body type.
        //! @param type The body type.
        void setBodyType(BodyType2D type);

        //! @copydoc
        void initialize() override;

        //! Create the body.
        //! NOTE: This should never be called except when assigned to system. In other words, only Physics2DSystem should call this.
        //! @param system The physics 2D system.
        void createBodyOnSelf(Physics2DSystem *system);

        //! @copydoc
        void update(const Time &time) override;

    private:
        //! The physics 2D system. It is assigned when 'createBodyOnSelf' is called.
        Physics2DSystem* physics2DSystem{};
        RectTransform *rectTransform;
        ACollider2D *collider;
        std::shared_ptr<ABody2D> body;
        BodyType2D bodyType;

        //! Try to find the collider.
        //! @return The collider if found, otherwise nullptr.
        [[nodiscard]] ACollider2D* tryFindCollider() const;

        //! Destroy the body on self.
        void destroyBodyOnSelf();
    };
}

#endif //RIGID_BODY_2D_H
