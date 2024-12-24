#include <iostream>
#include <SDL_image.h>
#include <ecs/entity/Entity.h>
#include <sdl/renderer/SDLRenderer.h>

#include "Framework.h"
#include "ecs/ECSManager.h"
// #include "spdlog/spdlog.h"
// #include "spdlog/sinks/basic_file_sink.h"


void createScene(mars::Framework& framework, mars::EntityManager& entityManager) {
    std::shared_ptr<mars::Texture2D> uvTestTexture = framework.getTextureFactory().createTextureFromImageFile("../assets/texture/uv_test.png");
    std::shared_ptr<mars::Entity> entity = entityManager.createEntity("projectile");
    mars::RectTransform* transform = entity->addComponent<mars::RectTransform>();
    transform->setDrawRectangle(mars::Rect { 100, 100, 200, 200 });
    mars::SpriteRenderer* spriteRenderer = entity->addComponent<mars::SpriteRenderer>();
    spriteRenderer->setSprite(new mars::Sprite(uvTestTexture));

    std::shared_ptr<mars::Entity> entity2 = entityManager.createEntity("projectile");
    mars::RectTransform* transform2 = entity2->addComponent<mars::RectTransform>();
    transform2->setDrawRectangle(mars::Rect { 300, 100, 200, 200 });
    mars::SpriteRenderer* spriteRenderer2 = entity2->addComponent<mars::SpriteRenderer>();
    spriteRenderer2->setSprite(new mars::Sprite(uvTestTexture));
}

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main(int argc, char* argv[]) {

    // spdlog::info("Sample Info output.", 1);
    // spdlog::warn("Sample Warn output.");
    // spdlog::error("Sample Error output.");

    std::cout << "Hello, World!" << std::endl;

    mars::Framework framework(mars::FrameworkOptions {
        mars::WindowBounds(1280, 720)
    });


    mars::ECSManager ecsManager(framework);

    mars::EntityManager& entityManager = ecsManager.getEntityManager();

    framework.subscribeToUpdateEvent([&]( const mars::Time time) {
        ecsManager.update(time);
    });

    framework.subscribeToRenderEvent([&]() {

        // framework.getSpriteBatch().begin();
        // framework.getSpriteBatch().draw({ 100, 100, 200, 200}, mars::Color::red());
        // framework.getSpriteBatch().end();

        ecsManager.render();
    });
    framework.initialize();

    createScene(framework, entityManager);

    framework.runEventLoop();
    framework.destroy();// SPDLOG_TRACE("Sample Trace output.");

    return 0;
}


// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.