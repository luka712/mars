#include <iostream>
#include <SDL_image.h>
#include <ecs/entity/Entity.h>
#include <ecs/sprite/AnimatedSpriteRenderer.h>
#include <sdl/renderer/SDLRenderer.h>

#include "Framework.h"
#include "core/sprite/AnimatedSprite.h"
#include "ecs/ECSManager.h"
#include "ecs/tilemap/TileMap.h"
// #include "spdlog/spdlog.h"
// #include "spdlog/sinks/basic_file_sink.h"

#include "box2d/physics2d/Box2DWorld2D.h"

class MovePlayer final : public mars::AScript {
    mars::RectTransform *transform;

public:
    MovePlayer(mars::Entity *entity)
        : AScript(entity) {
    }

    void initialize() override {
        transform = entity->getComponent<mars::RectTransform>();
    }

    void update(const mars::Time &time) override {
        auto keyboardState = framework.getInputManager().getKeyboardState();
        auto rect = transform->getDrawRectangle();

        if (keyboardState.isKeyDown(mars::Key::A)) {
            rect.x -= 1;
        } else if (keyboardState.isKeyDown(mars::Key::D)) {
            rect.x += 1;
        }

        transform->setDrawRectangle(rect);
    }
};


void createScene(const mars::Framework &framework, mars::EntityManager &entityManager) {
    std::shared_ptr<mars::Texture2D> uvTestTexture = framework
            .getContentManager()
            .load<mars::Texture2D>("texture/uv_test.png");

    std::shared_ptr<mars::Texture2D> tileMapTexture = framework
            .getContentManager()
            .load<mars::Texture2D>("tilemaps/jungle.png");

    std::shared_ptr<mars::Entity> tileMap = entityManager.createEntity("tilemap");
    tileMap->addComponent<mars::RectTransform>();
    auto tileMapComponent = tileMap->addComponent<mars::TileMap>();
    tileMapComponent->setTexture(tileMapTexture);
    tileMapComponent->loadTiles(glm::vec2(32, 32),
                                {
                                    {2, 2, 2, 2},
                                    {1, 1, 1, 1},
                                    {2, 2, 2, 2},
                                    {3, 3, 3, 3},
                                    {1, 2, 1, 1, 1, 1, 1}
                                });
    tileMapComponent->tileSize = glm::vec2(64, 64);

    std::shared_ptr<mars::Entity> player = entityManager.createEntity("player");
    auto playerTransform = player->addComponent<mars::RectTransform>();
    playerTransform->setDrawRectangle(mars::Rect{300, 100, 200, 200});
    auto playerSpriteRenderer = player->addComponent<mars::AnimatedSpriteRenderer>();
    playerSpriteRenderer->setSprite(new mars::Sprite(uvTestTexture));
    playerSpriteRenderer->addAnimation("left", {mars::Rect{0, 0, 50, 50}, mars::Rect{50, 0, 50, 50}});
    playerSpriteRenderer->playAnimation("left");
    auto playerMoveScript = player->addComponent<MovePlayer>();

    std::shared_ptr<mars::Entity> entity = entityManager.createEntity("projectile");
    mars::RectTransform *transform = entity->addComponent<mars::RectTransform>();
    transform->setDrawRectangle(mars::Rect{100, 100, 200, 200});
    mars::SpriteRenderer *spriteRenderer = entity->addComponent<mars::SpriteRenderer>();
    spriteRenderer->setSprite(new mars::Sprite(uvTestTexture));
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
    });


    mars::ECSManager ecsManager(framework);

    mars::EntityManager &entityManager = ecsManager.getEntityManager();

    framework.initialize();

    std::vector<float> vertex = {
        0.0f, 0.0f, 0.0f,
        100.0f, 0.0f, 0.0f,
        100.0f, 100.0f, 0.0f,
        0.0f, 100.0f, 0.0f
    };
    auto vertexBuffer = framework.getBuffersFactory().createVertexBuffer(vertex, 4, mars::BufferUsage::Vertex, "Hello");
    auto indexBuffer = framework.getBuffersFactory().createIndexBuffer({0, 1, 2, 2, 3, 0}, "Hello");
    std::vector<float> data = {1.0f, 2.0f, 3.0f, 4.0f};
    auto uniformBuffer = framework.getBuffersFactory().createUniformBuffer(
        data.data(), "Hello", 16, mars::BufferUsage::Uniform);
    std::shared_ptr<mars::Texture2D> tileMapTexture = framework
            .getContentManager()
            .load<mars::Texture2D>("images/radar.png");
    vertexBuffer->printInfo();
    indexBuffer->printInfo();
    uniformBuffer->printInfo();
    tileMapTexture->printInfo();

    std::shared_ptr<mars::OrthographicCamera> camera = framework.getCameraFactory().createOrthographicCamera(
        -10, 10, 10, -10, 0.1, 100);
    camera->printInfo();

    std::shared_ptr<mars::ASpriteRenderPipeline> pipeline = framework.getPipelineFactory().
            createSpriteRenderPipeline(camera.get());
    pipeline->setSpriteTexture(tileMapTexture.get());

    std::shared_ptr<mars::Geometry > geometry = framework.getGeometryBuilder().quadGeometry();
    std::shared_ptr<mars::Mesh> mesh = framework.getMeshFactory().create(*geometry, mars::GeometryFormat::Pos3_Color4_TextureCoords2_Normal3);

    // PHYSICS.
    mars::WorldDefinition2D worldDef{};
    worldDef.gravity = glm::vec2(0, -9.8f);

    std::unique_ptr<mars::AWorld2D> world2D = std::make_unique<mars::Box2DWorld2D>(worldDef);

    // FRAME START EVENT?

    framework.subscribeToUpdateEvent([&](const mars::Time time) {
        ecsManager.frameStart();
        ecsManager.update(time);
    });

    framework.subscribeToRenderEvent([&]() {
        // framework.getSpriteBatch().begin();
        //  framework.getSpriteBatch().drawString(spriteFont.get(), "Hello World!", glm::vec2(100, 300));
        //framework.getSpriteBatch().end();


        // ecsManager.render();
        pipeline->render(vertexBuffer.get(), indexBuffer.get(), 6, 0);

    });

    // createScene(framework, entityManager);

    framework.runEventLoop();
    framework.destroy(); // SPDLOG_TRACE("Sample Trace output.");

    return 0;
}


// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.
