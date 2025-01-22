//
// Created by lukaa on 22.1.2025..
//

#ifndef CAMERA2DSYSTEM_H
#define CAMERA2DSYSTEM_H

#include <vector>
#include "ecs/camera/Camera2D.h"

namespace mars {
    class Framework;

    //! The Camera2DSystem class.
    class Camera2DSystem {
    public:
        //! Construct a new Camera2DSystem object.
        //! @param framework The framework.
        explicit Camera2DSystem(Framework &framework);

        //! Get the Camera2D components.
        //! @return The Camera2D components.
        [[nodiscard]] const std::vector<Camera2D*>& getCameraComponents() const { return activeCameraComponents; }

        //! Add a Camera2D component to the system.
        //! @param camera2D The Camera2D component.
        void add(Camera2D *camera2D);

        //! Update the Camera2D components.
        //! @param time The game time.
        void update(const Time &time);

        //! Remove a Camera2D component from the system.
        //! @param camera2D The Camera2D component.
        void remove(const Camera2D *camera2D);

        //! Render the sprite components.
        void render();

    private:
        Framework &framework;
        std::vector<Camera2D *> activeCameraComponents;
    };
}

#endif //CAMERA2DSYSTEM_H
