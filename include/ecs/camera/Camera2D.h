//
// Created by lukaa on 22.1.2025..
//

#ifndef CAMERA_H
#define CAMERA_H

#include "ecs/transform/RectTransform.h"
#include "glm/vec2.hpp"

namespace mars {
    //! The Camera2D class, for working with 2D components.
    class Camera2D final : public AComponent {
    public:
        //! Construct a new Camera2D object.
        //! @param entity The entity that the component is attached to.
        explicit Camera2D(Entity *entity);

        //! Get the width of the camera.
        //! @return The width of the camera.
        [[nodiscard]] uint32_t getWidth() const { return width; }

        //! Set the width of the camera.
        //! @param width The width of the camera.
        void setWidth(uint32_t width);

        //! Get the height of the camera.
        //! @return The height of the camera.
        [[nodiscard]] uint32_t getHeight() const { return height; }

        //! Set the height of the camera.
        //! @param height The height of the camera.
        void setHeight(uint32_t height);

        //! Get the rect transform.
        //! @return The rect transform. If not set, returns nullptr.
        [[nodiscard]] RectTransform *getRectTransform() const;

        void initialize() override;

        std::string toString() override;

    private:
        RectTransform *rectTransform{};
        uint32_t width{};
        uint32_t height{};
    };
}


#endif //CAMERA_H
