#include <iostream>
#include <ecs/entity/Entity.h>

#include "Framework.h"
#include "ecs/ECSManager.h"
// #include "spdlog/spdlog.h"
// #include "spdlog/sinks/basic_file_sink.h"

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

    std::shared_ptr<mars::Entity> entity = entityManager.createEntity("projectile");
    std::shared_ptr<mars::RectTransform> transform = entity->addComponent<mars::RectTransform>();
    transform->setDrawRectangle(mars::Rect { 100, 100, 200, 200 });
    std::shared_ptr<mars::SpriteRenderer> spriteRenderer = entity->addComponent<mars::SpriteRenderer>();

    std::cout << entity->toString() << std::endl;

    entity->removeComponent<mars::SpriteRenderer>();

    std::cout << entity->toString() << std::endl;


    std::shared_ptr<mars::Entity> entity2 = entityManager.createEntity("projectile");
    std::shared_ptr<mars::RectTransform> transform2 = entity2->addComponent<mars::RectTransform>();
    transform->setDrawRectangle(mars::Rect { 300, 300, 200, 200 });
    std::shared_ptr<mars::SpriteRenderer> spriteRenderer2 = entity2->addComponent<mars::SpriteRenderer>();
    spriteRenderer2->color = mars::Color::red();

    framework.subscribeToUpdateEvent([&]( const mars::Time time) {
        ecsManager.update(time);
    });

    framework.subscribeToRenderEvent([&]() {

        framework.getSpriteBatch().begin();
        framework.getSpriteBatch().draw({ 100, 100, 200, 200}, mars::Color::red());
        framework.getSpriteBatch().end();

        ecsManager.render();
    });
    framework.initialize();
    framework.destroy();

    // auto filelog = spdlog::basic_logger_mt("sample-logger", "sample-log.txt");

  //   filelog.get()->info("Sample Info output.");
   // filelog.get()->warn("Sample Warn output.");
   // filelog.get()->error("Sample Error output.");

    // SPDLOG_TRACE("Sample Trace output.");

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.