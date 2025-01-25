//
// Created by lukaa on 10.1.2025..
//

#include <sstream>
#include "Framework.h"
#include "ecs/tilemap/TileMap.h"
#include "ecs/entity/Entity.h"
#include "ecs/sprite/AnimatedSpriteRenderer.h"

namespace mars {
    TileMap::TileMap(Entity* entity)
        : AComponent(entity), color(Color::white()), tileSize(0,0), texture(nullptr) {
    }

    const RectTransform* TileMap::getRectTransform() const {
        return rectTransform;
    }

    void TileMap::initialize() {

        // Entity must have RectTransform component.
        rectTransform = entity->getComponent<RectTransform>();
        if (rectTransform == nullptr) {
            const std::string msg = "TileMap component requires RectTransform component.";
            framework.getLogger().error(msg.c_str());
            throw std::runtime_error(msg);
        }

        // Entity cannot have sprite renderer component.
        if (entity->getComponent<SpriteRenderer>() != nullptr) {
            const std::string msg = "TileMap component cannot be attached to entity with SpriteRenderer component.";
            framework.getLogger().error(msg.c_str());
            throw std::runtime_error(msg);
        }

        // Entity cannot have animated sprite renderer component.
        if (entity->getComponent<AnimatedSpriteRenderer>() != nullptr) {
            const std::string msg = "TileMap component cannot be attached to entity with AnimatedSpriteRenderer component.";
            framework.getLogger().error(msg.c_str());
            throw std::runtime_error(msg);
        }
    }

    void TileMap::loadTiles(const glm::vec2 tileSize, const std::vector<std::vector<int32_t>> &tiles) {

        if (texture == nullptr) {
            const std::string msg = "TileMap component requires texture to be set.";
            framework.getLogger().error(msg.c_str());
            throw std::runtime_error(msg);
        }

        this->tileSize = tileSize;

        auto textureColumns = static_cast<int32_t>(static_cast<float>(texture->getWidth()) / tileSize.x);

        const auto tw = static_cast<int32_t>(tileSize.x);
        const auto th = static_cast<int32_t>(tileSize.y);

        int32_t y = 0;
        for (auto& row : tiles) {
            int32_t x = 0;
            for (auto& index: row) {

                Rect sourceRect{};
                const int32_t tx = index % textureColumns;
                const int32_t ty = index / textureColumns;

                sourceRect.x = tx * tw;
                sourceRect.y = ty * th;
                sourceRect.width = tw;
                sourceRect.height = th;
                chunks.emplace_back(x,y, sourceRect);
                x++;
            }
            y++;
        }
    }

    void TileMap::render(SpriteBatch &spriteBatch, Camera2D& camera) const {

        const Rect cameraDrawRect = camera.getRectTransform()->getDrawRectangle();

        for (auto& chunk : chunks) {

            Rect drawRect{};
            drawRect.x = chunk.getX() * static_cast<int32_t>(tileSize.x) - cameraDrawRect.x;
            drawRect.y = chunk.getY() * static_cast<int32_t>(tileSize.y) - cameraDrawRect.y;
            drawRect.width = static_cast<int32_t>(tileSize.x);
            drawRect.height = static_cast<int32_t>(tileSize.y);

            spriteBatch.draw(texture.get(), drawRect, chunk.getSourceRect(), color);
        }
    }

    std::string TileMap::toString() {
        std::stringstream result;

        result << "TileMap\n";
        // TODO: print tiles.

        return result.str();
    }
}
