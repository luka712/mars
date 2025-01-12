//
// Created by lukaa on 11.1.2025..
//

#include "ecs/transform/RectTransform.h"
#include "ecs/script/AScript.h"

class MovePlayer final : public mars::AScript{

    mars::RectTransform* transform;
    mars::AnimatedSpriteRenderer *spriteRenderer;

public:
    MovePlayer(mars::Entity *entity)
        : AScript(entity){
    }

    void initialize() override {
        transform = entity->getComponent<mars::RectTransform>();
        spriteRenderer = entity->getComponent<mars::AnimatedSpriteRenderer>();
    }

    void update(const mars::Time& time) override {
        auto keyboardState = framework.getInputManager().getKeyboardState();
        auto rect = transform->getDrawRectangle();

        if (keyboardState.isKeyDown(mars::Key::A)) {
            rect.x -= 1;
            spriteRenderer->playAnimation("left");
        }
        else if (keyboardState.isKeyDown(mars::Key::D)) {
            rect.x += 1;
            spriteRenderer->playAnimation("right");
        }

        if (keyboardState.isKeyDown(mars::Key::W)) {
            rect.y -= 1;
            spriteRenderer->playAnimation("up");
        }
        else if (keyboardState.isKeyDown(mars::Key::S)) {
            rect.y += 1;
            spriteRenderer->playAnimation("down");
        }

        transform->setDrawRectangle(rect);
    }
};