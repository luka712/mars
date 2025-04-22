//
// Created by lukaa on 10.1.2025..
//

#include <sstream>
#include "Framework.h"
#include "ecs/tilemap/TileMap.h"
#include "ecs/entity/Entity.h"

namespace mars {
    TileMap::TileMap(Entity* entity)
        : AComponent(entity), tileSize(0,0), scale(1), color(Color::white()), texture(nullptr) {
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
    }

    void TileMap::loadTiles(const glm::vec2 tileSize, const std::vector<std::vector<int32_t>> &tiles) {

        if (texture == nullptr) {
            const std::string msg = "TileMap component requires texture to be set.";
            framework.getLogger().error(msg.c_str());
            throw std::runtime_error(msg);
        }

        this->tileSize = tileSize;

        const auto textureColumns = static_cast<int32_t>(static_cast<float>(texture->getWidth()) / tileSize.x);

        const auto tw = static_cast<int32_t>(tileSize.x);
        const auto th = static_cast<int32_t>(tileSize.y);

        int32_t y = 0;
        for (auto& row : tiles) {
            int32_t x = 0;
            for (auto& index: row) {

                if (index < 0) {
                    TileMapChunk chunk(0,0, {});
                    chunk.empty = true;
                    chunks.emplace_back(chunk);
                    x++;
                    continue;
                }

                const int32_t tx = index % textureColumns;
                const int32_t ty = index / textureColumns;
                Rect sourceRect{};
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

    void TileMap::render(SpriteBatch &spriteBatch, const Camera2D& camera) const {

        const Rect cameraDrawRect = camera.getRectTransform()->getDrawRectangle();

        for (auto& chunk : chunks) {

            // Skip empty chunks.
            if (chunk.empty) {
                continue;
            }

            const int32_t sclX = static_cast<int32_t>(tileSize.x) * scale;
            const int32_t sclY = static_cast<int32_t>(tileSize.y) * scale;

            Rect drawRect{};
            drawRect.x = chunk.getX() * sclX - cameraDrawRect.x;
            drawRect.y = chunk.getY() * sclY - cameraDrawRect.y;
            drawRect.width = sclX;
            drawRect.height = sclY;

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
