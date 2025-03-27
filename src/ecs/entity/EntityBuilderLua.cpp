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

    RigidBody2D *EntityBuilderLua::buildRigidBody2D(Entity &entity, sol::table &rigidBodyTable) const {
        if (!rigidBodyTable.valid()) {
            const std::string msg = "'EntityBuilderLua::buildRigidBody2D': Cannot create 'RigidBody2D' without table.";
            framework.getLogger().error(msg);
            throw std::runtime_error(msg);
        }

        auto *rigidBody = entity.addComponent<RigidBody2D>();

        // PROPERTIES - TODO: Add more properties.

        return rigidBody;
    }
}
