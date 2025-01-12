#include <iostream>
#include <SDL_image.h>
#include <sstream>
#include <ecs/entity/Entity.h>
#include <ecs/sprite/AnimatedSpriteRenderer.h>


#include "Framework.h"
#include "core/sprite/AnimatedSprite.h"
#include "ecs/ECSManager.h"
#include "ecs/tilemap/TileMap.h"


#include "game/chopper-shooter/move-player.h"

std::vector<std::vector<int>> loadMap(const mars::Framework& framework) {
    std::string jungleMap = framework.getFileLoader().loadFile("content/tilemaps/jungle.map");
    std::vector<std::vector<int>> map;
    std::istringstream mapSS(jungleMap);
    std::string line;
    while (std::getline(mapSS, line)) {
        std::istringstream lineSS(line);
        std::string value;
        std::vector<int> row;
        while (std::getline(lineSS, value, ',' )) {
            int index = std::stoi(value);
            row.push_back(index);
        }
        map.push_back(row);
    }
    return map;
}

void createScene(const mars::Framework& framework, mars::EntityManager& entityManager) {

    auto spriteFont = framework.getSpriteFontManager().getDefaultFont();
    std::vector<std::vector<int32_t>> map = loadMap(framework);


    std::shared_ptr<mars::Texture2D> playerTexture = framework
        .getContentManager()
        .load<mars::Texture2D>("images/chopper-spritesheet.png");

    std::shared_ptr<mars::Texture2D> tileMapTexture = framework
        .getContentManager()
        .load<mars::Texture2D>("tilemaps/jungle.png");

    std::shared_ptr<mars::Texture2D> radarTexture = framework
        .getContentManager()
        .load<mars::Texture2D>("images/radar.png");

    // TILEMAP
    std::shared_ptr<mars::Entity> tileMap = entityManager.createEntity("tilemap");
    tileMap->addComponent<mars::RectTransform>();
    auto tileMapComponent = tileMap->addComponent<mars::TileMap>();
    tileMapComponent->setTexture(tileMapTexture);
    tileMapComponent->loadTiles(glm::vec2(32, 32),map);
    tileMapComponent->tileSize = glm::vec2(64, 64);

    // PLAYER
    std::shared_ptr<mars::Entity> player = entityManager.createEntity("player");
    auto playerTransform = player->addComponent<mars::RectTransform>();
    playerTransform->setDrawRectangle(mars::Rect { 300, 100, 64, 64 });
    auto playerSpriteRenderer = player->addComponent<mars::AnimatedSpriteRenderer>();
    playerSpriteRenderer->setSprite(new mars::Sprite(playerTexture));
    playerSpriteRenderer->addAnimation("left", { mars::Rect { 0, 64, 32, 32 }, mars::Rect { 32, 64, 32, 32 } });
    playerSpriteRenderer->addAnimation("right", { mars::Rect { 0, 32, 32, 32 }, mars::Rect { 32, 32, 32, 32 } });
    playerSpriteRenderer->addAnimation("down", { mars::Rect { 0, 0, 32, 32 }, mars::Rect { 32, 0, 32, 32 } });
    playerSpriteRenderer->addAnimation("up", { mars::Rect { 0, 96, 32, 32 }, mars::Rect { 32, 96, 32, 32 } });
    playerSpriteRenderer->playAnimation("left");
    auto playerMoveScript = player->addComponent<MovePlayer>();

    std::shared_ptr<mars::Entity> radar = entityManager.createEntity("radar");
    mars::RectTransform* radarTransform = radar->addComponent<mars::RectTransform>();
    radarTransform->setDrawRectangle(mars::Rect { 1200, 15, 64, 64 });
    mars::AnimatedSpriteRenderer* radarSpriteRenderer = radar->addComponent<mars::AnimatedSpriteRenderer>();
    radarSpriteRenderer->setSprite(new mars::Sprite(radarTexture));
    radarSpriteRenderer->addAnimation("play",{
        mars::Rect { 64 * 0, 0, 64, 64 },
        mars::Rect { 64 * 1, 0, 64, 64 },
        mars::Rect { 64 * 2 , 0, 64, 64 },
        mars::Rect { 64 * 3, 0, 64, 64 },
        mars::Rect { 64 * 4, 0, 64, 64 },
        mars::Rect { 64 * 5, 0, 64, 64 },
        mars::Rect { 64 * 6, 0, 64, 64 },
        mars::Rect { 64 * 7, 0, 64, 64 },

    });
    radarSpriteRenderer->playAnimation("play");

    radarSpriteRenderer->setSprite(new mars::Sprite(radarTexture));
}

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main(int argc, char* argv[]) {

    // spdlog::info("Sample Info output.", 1);
    // spdlog::warn("Sample Warn output.");
    // spdlog::error("Sample Error output.");

    std::cout << "Hello, World!" << std::endl;

    mars::Framework framework(mars::FrameworkOptions {
        mars::WindowBounds(1280, 720),
        mars::RenderingBackend::SDL
    });


    mars::ECSManager ecsManager(framework);

    mars::EntityManager& entityManager = ecsManager.getEntityManager();

    framework.initialize();

    framework.subscribeToUpdateEvent([&]( const mars::Time time) {
        ecsManager.update(time);
    });

    framework.subscribeToRenderEvent([&]() {

        framework.getSpriteBatch().begin();
        framework.getSpriteBatch().end();

        ecsManager.render();
    });

    createScene(framework, entityManager);

    framework.runEventLoop();
    framework.destroy();// SPDLOG_TRACE("Sample Trace output.");

    return 0;
}


// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.