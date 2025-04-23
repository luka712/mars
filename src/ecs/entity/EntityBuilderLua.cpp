//
// Created by Erkapic LUka on 22.3.2025.
//

#include "Framework.h"
#include "ecs/ECSManager.h"
#include "ecs/entity/EntityBuilderLua.h"
#include "ecs/entity/Entity.h"

namespace mars {
    EntityBuilderLua::EntityBuilderLua(Framework &framework, ECSManager &ecsManager)
        : framework(framework), ecsManager(ecsManager) {
    }

    std::shared_ptr<Entity> EntityBuilderLua::buildEntity(sol::table &entityTable,
                                                          const std::vector<std::shared_ptr<Layer> > &layers) const {
        EntityManager &manager = ecsManager.getEntityManager();

        // Entity properties.
        std::string name = "";
        if (entityTable["name"].valid()) {
            name = entityTable["name"];
        }
        int32_t layer = 0;
        if (entityTable["layer"].valid()) {
            layer = entityTable["layer"];
        }

        // Create entity.
        std::shared_ptr<Entity> entity = manager.createEntity(name);
        entity->setLayer(layers[layer]);

        // Add components.
        sol::table componentsTable = entityTable["components"];

        if (!componentsTable.valid()) {
            const std::string msg = "EntityBuilderLua::buildEntity Cannot create entity without components.";
            framework.getLogger().error(msg);
            throw std::runtime_error(msg);
        }

        // - Check if transform is available.
        if (componentsTable["rect_transform"].valid()) {
            sol::table transformTable = componentsTable["rect_transform"];
            buildRectTransform(*entity, transformTable);
        }

        // - Check if sprite renderer is available.
        if (componentsTable["sprite_renderer"].valid()) {
            sol::table spriteRendererTable = componentsTable["sprite_renderer"];
            buildSpriteRenderer(*entity, spriteRendererTable);
        }

        // - Check if animated sprite renderer is available.
        if (componentsTable["animated_sprite_renderer"].valid()) {
            sol::table animatedSpriteRendererTable = componentsTable["animated_sprite_renderer"];
            buildAnimatedSpriteRenderer(*entity, animatedSpriteRendererTable);
        }

        // - Check if box collider is available.
        if (componentsTable["box_collider_2d"].valid()) {
            sol::table boxColliderTable = componentsTable["box_collider_2d"];
            buildBoxCollider2D(*entity, boxColliderTable);
        }

        // - Check if rigid body is available.
        if (componentsTable["rigid_body_2d"].valid()) {
            sol::table bodyTable = componentsTable["rigid_body_2d"];
            buildRigidBody2D(*entity, bodyTable);
        }

        return entity;
    }

    RectTransform *EntityBuilderLua::buildRectTransform(Entity &entity, sol::table &rectTransformTable) const {
        if (!rectTransformTable.valid()) {
            const std::string msg =
                    "'EntityBuilderLua::buildRectTransform': Cannot create 'RectTransform' without table.";
            framework.getLogger().error(msg);
            throw std::runtime_error(msg);
        }

        auto *rectTransform = entity.addComponent<RectTransform>();

        // Check if draw rect is available.
        if (rectTransformTable["draw_rect"].valid()) {
            sol::table drawRectTable = rectTransformTable["draw_rect"];
            // Read properties of draw rect.
            const int32_t x = drawRectTable["x"];
            const int32_t y = drawRectTable["y"];
            const int32_t width = drawRectTable["width"];
            const int32_t height = drawRectTable["height"];
            rectTransform->setDrawRectangle({x, y, width, height});
        }

        return rectTransform;
    }

    SpriteRenderer *EntityBuilderLua::buildSpriteRenderer(Entity &entity, sol::table &spriteRendererTable) const {
        if (!spriteRendererTable.valid()) {
            const std::string msg =
                    "EntityBuilderLua::buildSpriteRenderer: Cannot create 'SpriteRenderer' without table.";
            framework.getLogger().error(msg);
            throw std::runtime_error(msg);
        }

        auto *spriteRenderer = entity.addComponent<SpriteRenderer>();

        if (spriteRendererTable["texture_id"].valid()) {
            const std::string textureId = spriteRendererTable["texture_id"];
            const std::shared_ptr<Sprite> sprite = ecsManager.getSpriteManager().getSprite(textureId);
            spriteRenderer->setSprite(sprite);
        }

        return spriteRenderer;
    }

    AnimatedSpriteRenderer *EntityBuilderLua::buildAnimatedSpriteRenderer(Entity &entity,
                                                                          sol::table &animatedSpriteRendererTable)
    const {
        if (!animatedSpriteRendererTable.valid()) {
            const std::string msg =
                    "EntityBuilderLua::buildAnimatedSpriteRenderer: Cannot create 'AnimatedSpriteRenderer' without table.";
            framework.getLogger().error(msg);
            throw std::runtime_error(msg);
        }

        auto *animatedSpriteRenderer = entity.addComponent<AnimatedSpriteRenderer>();

        if (animatedSpriteRendererTable["texture_id"].valid()) {
            const std::string textureId = animatedSpriteRendererTable["texture_id"];
            const std::shared_ptr<Sprite> sprite = ecsManager.getSpriteManager().getSprite(textureId);
            animatedSpriteRenderer->setSprite(sprite);
        }

        // Go through the animations.
        if (animatedSpriteRendererTable["animations"].valid()) {
            sol::table luaAnimations = animatedSpriteRendererTable["animations"];
            uint32_t animationIndex = 0;
            while (true) {
                if (const sol::optional<sol::table> exists = luaAnimations[animationIndex]; !exists) {
                    break;
                }

                sol::table luaAnimation = luaAnimations[animationIndex];
                std::string name = luaAnimation["name"];
                sol::table luaFrames = luaAnimation["frames"];

                std::vector<Rect> frames;
                uint32_t frameIndex = 0;

                while (true) {
                    if (const sol::optional<sol::table> existsFrame = luaFrames[frameIndex]; !existsFrame) {
                        break;
                    }
                    sol::table luaFrame = luaFrames[frameIndex];
                    const int32_t x = luaFrame["x"];
                    const int32_t y = luaFrame["y"];
                    const int32_t width = luaFrame["width"];
                    const int32_t height = luaFrame["height"];
                    frames.push_back({x, y, width, height});
                    frameIndex++;
                }

                animatedSpriteRenderer->addAnimation(name, frames);
                animationIndex++;
            }
        }

        return animatedSpriteRenderer;
    }

    BoxCollider2D * EntityBuilderLua::buildBoxCollider2D(Entity &entity, const sol::table &boxColliderTable) const {
        if (!boxColliderTable.valid()) {
            const std::string msg = "EntityBuilderLua::buildBoxCollider2D: Cannot create 'BoxCollider2D' without table.";
            framework.getLogger().error(msg);
            throw std::runtime_error(msg);
        }

        auto *boxCollider2D = entity.addComponent<BoxCollider2D>();

        // PROPERTIES
        const float density = getValueOrDefault<float>(boxColliderTable, "density");
        boxCollider2D->setDensity(density);

        return boxCollider2D;
    }

    RigidBody2D *EntityBuilderLua::buildRigidBody2D(Entity &entity, const sol::table &rigidBodyTable) const {
        if (!rigidBodyTable.valid()) {
            const std::string msg = "EntityBuilderLua::buildRigidBody2D: Cannot create 'RigidBody2D' without table.";
            framework.getLogger().error(msg);
            throw std::runtime_error(msg);
        }

        auto *rigidBody = entity.addComponent<RigidBody2D>();

        // BODY TYPE
        BodyType2D bodyType = BodyType2D::StaticBody;
        const std::string type = getValueOrDefault<std::string>(rigidBodyTable, "type");

        if (type == "dynamic") {
            bodyType = BodyType2D::DynamicBody;
        }
        else if (type == "kinematic") {
            bodyType = BodyType2D::KinematicBody;
        }

        rigidBody->setBodyType(bodyType);

        return rigidBody;
    }
}
