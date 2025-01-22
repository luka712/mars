//
// Created by lukaa on 1.1.2025..
//

#include "Framework.h"
#include "ecs/camera/Camera2DSystem.h"

namespace mars {
    Camera2DSystem::Camera2DSystem(Framework &framework)
        : framework(framework) {
    }

    void Camera2DSystem::add(Camera2D *camera2D) {
        activeCameraComponents.emplace_back(camera2D);

        // By default, camera is size of window bounds.
        WindowBounds windowBounds = framework.getWindowManager().getWindowBounds();
        camera2D->setWidth(windowBounds.width);
        camera2D->setHeight(windowBounds.height);
    }

    void Camera2DSystem::remove(const Camera2D *camera2D) {
        for (int i = 0; i < activeCameraComponents.size(); i++) {
            if (activeCameraComponents[i] == camera2D) {
                activeCameraComponents.erase(activeCameraComponents.begin() + i);
                break;
            }
        }
    }

    void Camera2DSystem::update(const Time &time) {
        for (Camera2D *camera: activeCameraComponents) {
            camera->update(time);
        }
    }

    void Camera2DSystem::render() {
        for (Camera2D *camera: activeCameraComponents) {
            camera->render();
        }
    }
}
