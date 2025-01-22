//
// Created by lukaa on 11.1.2025..
//

#include "ecs/transform/RectTransform.h"
#include "ecs/script/AScript.h"

class MovePlayer final : public mars::AScript {
    mars::RectTransform *transform;
    mars::AnimatedSpriteRenderer *spriteRenderer;



public:
    MovePlayer(mars::Entity *entity)
        : AScript(entity) {
    }

    mars::Entity *camera;

    void initialize() override {
        transform = entity->getComponent<mars::RectTransform>();
        spriteRenderer = entity->getComponent<mars::AnimatedSpriteRenderer>();

    }

    void update(const mars::Time &time) override {

        mars::Camera2D* cameraComponent = camera->getComponent<mars::Camera2D>();

        auto keyboardState = framework.getInputManager().getKeyboardState();
        auto rect = transform->getDrawRectangle();

        if (keyboardState.isKeyDown(mars::Key::A)) {
            rect.x -= 1;
            spriteRenderer->playAnimation("left");
        } else if (keyboardState.isKeyDown(mars::Key::D)) {
            rect.x += 1;
            spriteRenderer->playAnimation("right");
        }

        if (keyboardState.isKeyDown(mars::Key::W)) {
            rect.y -= 1;
            spriteRenderer->playAnimation("up");
        } else if (keyboardState.isKeyDown(mars::Key::S)) {
            rect.y += 1;
            spriteRenderer->playAnimation("down");
        }

        int32_t cameraWidth = cameraComponent->getWidth();
        int32_t cameraHeight = cameraComponent->getHeight();
        int32_t cameraX = rect.x - static_cast<int32_t>(cameraWidth * .5f);
        int32_t cameraY = rect.y - static_cast<int32_t>(cameraHeight * .5f);

        if (cameraX < 0) {
            cameraX = 0;
        }
        if (cameraY < 0) {
            cameraY = 0;
        }

        cameraComponent->getRectTransform()->setDrawRectangle( {
            cameraX,
            cameraY,
            cameraWidth,
            cameraHeight
        });
        transform->setDrawRectangle(rect);
    }
};
