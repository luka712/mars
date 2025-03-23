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

        return entity;
    }

    RectTransform* EntityBuilderLua::buildRectTransform(Entity &entity,
                                                                        sol::table &rectTransformTable) const {
        // RectTransform properties.
        if (!rectTransformTable.valid()) {
            const std::string msg = "EntityBuilderLua::buildRectTransform Cannot create RectTransform without table.";
            framework.getLogger().error(msg);
            throw std::runtime_error(msg);
        }

        RectTransform* rectTransform = entity.addComponent<RectTransform>();

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
}
