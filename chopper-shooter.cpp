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


std::vector<std::vector<int> > loadMap(const mars::Framework &framework) {
    std::string jungleMap = framework.getFileLoader().loadFile("content/tilemaps/jungle.map");
    std::vector<std::vector<int> > map;
    std::istringstream mapSS(jungleMap);
    std::string line;
    while (std::getline(mapSS, line)) {
        std::istringstream lineSS(line);
        std::string value;
        std::vector<int> row;
        while (std::getline(lineSS, value, ',')) {
            int index = std::stoi(value);
            row.push_back(index);
        }
        map.push_back(row);
    }
    return map;
}

void createScene(const mars::Framework &framework,
                 mars::EntityManager &entityManager,
                 const std::vector<std::shared_ptr<mars::Layer> > &layers) {
    auto spriteFont = framework.getSpriteFontManager().getDefaultFont();

    std::vector<std::vector<int32_t> > map = loadMap(framework);


    std::shared_ptr<mars::Texture2D> playerTexture = framework
            .getContentManager()
            .load<mars::Texture2D>("images/chopper-spritesheet.png");

    std::shared_ptr<mars::Texture2D> enemyTexture = framework
            .getContentManager()
            .load<mars::Texture2D>("images/tank-big-left.png");

    std::shared_ptr<mars::Texture2D> tileMapTexture = framework
            .getContentManager()
            .load<mars::Texture2D>("tilemaps/jungle.png");

    std::shared_ptr<mars::Texture2D> radarTexture = framework
            .getContentManager()
            .load<mars::Texture2D>("images/radar.png");

    std::shared_ptr<mars::Texture2D> heliportTexture = framework
            .getContentManager()
            .load<mars::Texture2D>("images/heliport.png");

    // TILEMAP
    std::shared_ptr<mars::Entity> tileMap = entityManager.createEntity("tilemap");
    tileMap->setLayer(layers[0]);
    tileMap->addComponent<mars::RectTransform>();
    auto tileMapComponent = tileMap->addComponent<mars::TileMap>();
    tileMapComponent->setTexture(tileMapTexture);
    tileMapComponent->loadTiles(glm::vec2(32, 32), map);
    tileMapComponent->tileSize = glm::vec2(64, 64);

    // CAMERA
    std::shared_ptr<mars::Entity> camera = entityManager.createEntity("camera");
    camera->addComponent<mars::RectTransform>();
    camera->addComponent<mars::Camera2D>();

    // PLAYER
    std::shared_ptr<mars::Entity> player = entityManager.createEntity("player");
    player->setLayer(layers[1]);
    auto playerTransform = player->addComponent<mars::RectTransform>();
    playerTransform->setDrawRectangle(mars::Rect{300, 100, 64, 64});
    auto playerSpriteRenderer = player->addComponent<mars::AnimatedSpriteRenderer>();
    playerSpriteRenderer->setSprite(new mars::Sprite(playerTexture));
    playerSpriteRenderer->addAnimation("left", {mars::Rect{0, 64, 32, 32}, mars::Rect{32, 64, 32, 32}});
    playerSpriteRenderer->addAnimation("right", {mars::Rect{0, 32, 32, 32}, mars::Rect{32, 32, 32, 32}});
    playerSpriteRenderer->addAnimation("down", {mars::Rect{0, 0, 32, 32}, mars::Rect{32, 0, 32, 32}});
    playerSpriteRenderer->addAnimation("up", {mars::Rect{0, 96, 32, 32}, mars::Rect{32, 96, 32, 32}});
    playerSpriteRenderer->playAnimation("left");
    auto playerMoveScript = player->addComponent<MovePlayer>();
    playerMoveScript->camera = camera.get();
    auto playerCollider = player->addComponent<mars::Collider2D>();
    playerCollider->setDebug(true);
    playerCollider->subscribeToOnCollision([&](const mars::Collider2D *playerCollider, const mars::Collider2D *otherCollider) {
        framework.getLogger().info("Collision detected.");
    });


    // ENEMY
    std::shared_ptr<mars::Entity> enemy = entityManager.createEntity("enemy");
    enemy->setLayer(layers[1]);
    mars::RectTransform *enemyTransform = enemy->addComponent<mars::RectTransform>();
    enemyTransform->setDrawRectangle(mars::Rect{500, 100, 64, 64});
    mars::SpriteRenderer *enemySpriteRenderer = enemy->addComponent<mars::SpriteRenderer>();
    enemySpriteRenderer->setSprite(new mars::Sprite(enemyTexture));
    enemy->addComponent<mars::Collider2D>()->setDebug(true);

    // Radar
    std::shared_ptr<mars::Entity> radar = entityManager.createEntity("radar");
    radar->setLayer(layers[2]);
    mars::RectTransform *radarTransform = radar->addComponent<mars::RectTransform>();
    radarTransform->setDrawRectangle(mars::Rect{1200, 15, 64, 64});
    mars::AnimatedSpriteRenderer *radarSpriteRenderer = radar->addComponent<mars::AnimatedSpriteRenderer>();
    radarSpriteRenderer->isFixed = true;
    radarSpriteRenderer->setSprite(new mars::Sprite(radarTexture));
    radarSpriteRenderer->addAnimation("play", {
                                          mars::Rect{64 * 0, 0, 64, 64},
                                          mars::Rect{64 * 1, 0, 64, 64},
                                          mars::Rect{64 * 2, 0, 64, 64},
                                          mars::Rect{64 * 3, 0, 64, 64},
                                          mars::Rect{64 * 4, 0, 64, 64},
                                          mars::Rect{64 * 5, 0, 64, 64},
                                          mars::Rect{64 * 6, 0, 64, 64},
                                          mars::Rect{64 * 7, 0, 64, 64},
                                      });
    radarSpriteRenderer->playAnimation("play");

    // HELIPORT
    std::shared_ptr<mars::Entity> heliport = entityManager.createEntity("heliport");
    heliport->setLayer(layers[1]);
    mars::RectTransform *heliportTransform = heliport->addComponent<mars::RectTransform>();
    heliportTransform->setDrawRectangle(mars::Rect{470, 450, 64, 64});
    mars::SpriteRenderer *heliportSpriteRenderer = heliport->addComponent<mars::SpriteRenderer>();
    heliportSpriteRenderer->setSprite(new mars::Sprite(heliportTexture));
    mars::Collider2D* collider = heliport->addComponent<mars::Collider2D>();
    // collider->setDebug(true);
    collider->subscribeToOnCollision([&](const mars::Collider2D *playerCollider, const mars::Collider2D *otherCollider) {
        framework.getLogger().info("Heliport collision detected.");
    });


    radarSpriteRenderer->setSprite(new mars::Sprite(radarTexture));
}

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main(int argc, char *argv[]) {
    // spdlog::info("Sample Info output.", 1);
    // spdlog::warn("Sample Warn output.");
    // spdlog::error("Sample Error output.");

    std::cout << "Hello, World!" << std::endl;

    mars::Framework framework(mars::FrameworkOptions{
        mars::WindowBounds(1280, 720),
        mars::RenderingBackend::SDL
    });

    mars::ECSManager ecsManager(framework);

    std::vector<std::shared_ptr<mars::Layer> > layers = {
        ecsManager.getLayerManager().createLayer("MAP", 0, "The map layer"),
        ecsManager.getLayerManager().createLayer("GameObjects", 1, "The Game Objects Layer"),
        ecsManager.getLayerManager().createLayer("UI", 2, "THE UI LAYER")
    };

    mars::EntityManager &entityManager = ecsManager.getEntityManager();

    framework.initialize();

    framework.subscribeToUpdateEvent([&](const mars::Time time) {
        ecsManager.frameStart();
        ecsManager.update(time);
    });

    framework.subscribeToRenderEvent([&]() {
        framework.getSpriteBatch().begin();
        framework.getSpriteBatch().end();

        ecsManager.render();
    });

    createScene(framework, entityManager, layers);

    framework.runEventLoop();
    framework.destroy(); // SPDLOG_TRACE("Sample Trace output.");

    return 0;
}


// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.
