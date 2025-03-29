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
#include "lua/LuaManager.h"

static     std::map<std::string, std::shared_ptr<mars::Texture2D>> textures;


std::vector<std::vector<int> > loadMap(const mars::Framework &framework) {
    std::string jungleMap = framework.getFileReader().readFile("content/tilemaps/jungle.map");
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
                 mars::ECSManager& ecsManager,
                 mars::EntityManager &entityManager,
                 mars::EntityBuilderLua& entityBuilder,
                 const std::vector<std::shared_ptr<mars::Layer> > &layers,
                 sol::state& luaState) {
    auto spriteFont = framework.getSpriteFontManager().getDefaultFont();

    // LOAD ASSETS
    sol::table luaLevel = luaState["Level1"];
    sol::table luaTextures = luaLevel["textures"];
    uint32_t textureIndex = 0;
    while (true) {
        sol::optional<sol::table> existsLuaTexture = luaTextures[textureIndex];
        if (!existsLuaTexture) {
            break;
        }
        sol::table luaTexture = luaTextures[textureIndex];
        std::string id = luaTexture["id"];
        std::string file = luaTexture["file"];
        textures[id] = framework.getContentManager().load<mars::Texture2D>(file, id);
        ecsManager.getSpriteManager().addSprite(textures[id], id);
        textureIndex++;
    }

    std::shared_ptr<mars::Texture2D>& playerTexture = textures["chopper"];

    std::shared_ptr<mars::Texture2D>& enemyTexture = textures["tank"];

    std::shared_ptr<mars::Texture2D>& tileMapTexture = textures["jungle"];

    std::shared_ptr<mars::Texture2D> radarTexture = framework
            .getContentManager()
            .load<mars::Texture2D>("images/radar.png");

    std::shared_ptr<mars::Texture2D> heliportTexture = framework
            .getContentManager()
            .load<mars::Texture2D>("images/heliport.png");

    std::vector<std::vector<int32_t> > map = loadMap(framework);

    // TILEMAP
    std::shared_ptr<mars::Entity> tileMap = entityManager.createEntity("tilemap");
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
    sol::table playerTable = luaLevel["entities"][0];
    std::shared_ptr<mars::Entity> player = entityBuilder.buildEntity(playerTable, layers);
    //player->setLayer(layers[1]);
    // Build from lua script
    //auto playerTransform = player->addComponent<mars::RectTransform>();
    //playerTransform->setDrawRectangle(mars::Rect{300, 100, 64, 64});

   // auto playerSpriteRenderer = player->addComponent<mars::AnimatedSpriteRenderer>();
   // playerSpriteRenderer->setSprite(std::make_shared<mars::Sprite>(playerTexture));
   //playerSpriteRenderer->addAnimation("down", {mars::Rect{0, 64, 32, 32}, mars::Rect{32, 64, 32, 32}, mars::Rect{64, 64, 32, 32}, mars::Rect{96, 64, 32, 32}});
   // playerSpriteRenderer->addAnimation("right", {mars::Rect{0, 32, 32, 32}, mars::Rect{32, 32, 32, 32}});
   //playerSpriteRenderer->addAnimation("left", {mars::Rect{0, 96, 32, 32}, mars::Rect{32, 96, 32, 32}, mars::Rect{64, 96, 32, 32}, mars::Rect{96, 96, 32, 32}});
   //playerSpriteRenderer->addAnimation("up", {mars::Rect{0, 96, 32, 32}, mars::Rect{32, 96, 32, 32}});
   //playerSpriteRenderer->playAnimation("left");
    player->getComponent<mars::AnimatedSpriteRenderer>()->playAnimation("left");
    auto playerMoveScript = player->addComponent<MovePlayer>();
    playerMoveScript->camera = camera.get();
    auto playerCollider = player->addComponent<mars::Collider2D>();
    // playerCollider->setDebug(true);
    playerCollider->subscribeToOnCollision([&](const mars::Collider2D *playerCollider, const mars::Collider2D *otherCollider) {
        framework.getLogger().info("Collision detected.");
    });


    // ENEMY
    sol::table enemyTable = luaLevel["entities"][1];
    std::shared_ptr<mars::Entity> enemy = entityBuilder.buildEntity(enemyTable, layers);
    // enemy->setLayer(layers[1]);
    // mars::RectTransform *enemyTransform = enemy->addComponent<mars::RectTransform>();
    // enemyTransform->setDrawRectangle(mars::Rect{500, 100, 64, 64});
    // mars::SpriteRenderer *enemySpriteRenderer = enemy->addComponent<mars::SpriteRenderer>();
   // enemySpriteRenderer->setSprite(std::make_shared<mars::Sprite>(enemyTexture));
    enemy->addComponent<mars::Collider2D>()->setDebug(true);

    // Radar
    std::shared_ptr<mars::Entity> radar = entityManager.createEntity("radar");
    radar->setLayer(layers[2]);
    mars::RectTransform *radarTransform = radar->addComponent<mars::RectTransform>();
    radarTransform->setDrawRectangle(mars::Rect{1200, 15, 64, 64});
    mars::AnimatedSpriteRenderer *radarSpriteRenderer = radar->addComponent<mars::AnimatedSpriteRenderer>();
    radarSpriteRenderer->isFixed = true;
    radarSpriteRenderer->setSprite(std::make_shared<mars::Sprite>(radarTexture));
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
    heliportSpriteRenderer->setSprite(std::make_shared<mars::Sprite>(heliportTexture));
    mars::Collider2D* collider = heliport->addComponent<mars::Collider2D>();
    // collider->setDebug(true);
    collider->subscribeToOnCollision([&](const mars::Collider2D *playerCollider, const mars::Collider2D *otherCollider) {
        framework.getLogger().info("Heliport collision detected.");
    });


    radarSpriteRenderer->setSprite(std::make_shared<mars::Sprite>(radarTexture));
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
        mars::RenderingBackend::OpenGLES,
        glm::vec2(1280, 720)
    });

    mars::ECSManager ecsManager(framework);
    mars::LuaManager luaManager(framework);

    sol::state& luaState = luaManager.getLuaState();
    luaState.script_file("content/scripts/Level1.lua");

    sol::table luaLevel = luaState["Level1"];
    sol::table luaLayers = luaLevel["layers"];

    std::vector<std::shared_ptr<mars::Layer> > layers;
    uint32_t layerIndex = 0;
    while (true) {
        sol::optional<sol::table> existsLuaLayer = luaLayers[layerIndex];
        if (existsLuaLayer == sol::nullopt) {
            break;
        }
        else {
            sol::table luaLayer = luaLayers[layerIndex];
            std::string layerName = luaLayer["name"];
            uint32_t orderIndex = static_cast<uint32_t>(luaLayer["order"]);
            std::string description = luaLayer["description"];
            layers.push_back(ecsManager.getLayerManager().createLayer(
                layerName, orderIndex, description
            ));
        }
        layerIndex++;

    }

    mars::EntityManager &entityManager = ecsManager.getEntityManager();
    mars::EntityBuilderLua &entityBuilder = ecsManager.getEntityBuilderLua();

    framework.initialize();
    ecsManager.initialize();

    framework.subscribeToUpdateEvent([&](const mars::Time time) {
        ecsManager.frameStart();
        ecsManager.update(time);
    });

    framework.subscribeToRenderEvent([&]() {
        framework.getSpriteBatch().begin();
        framework.getSpriteBatch().end();

        ecsManager.render();
    });

    createScene(framework, ecsManager, entityManager, entityBuilder, layers, luaState);

    framework.runEventLoop();
    framework.destroy(); // SPDLOG_TRACE("Sample Trace output.");

    return 0;
}


// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.
