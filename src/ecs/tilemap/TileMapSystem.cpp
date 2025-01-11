//
// Created by erkapic luka on 11.1.2025.
//

#include "Framework.h"
#include "ecs/tilemap/TileMapSystem.h"

namespace mars {
    TileMapSystem::TileMapSystem(Framework &framework)
        : framework(framework) {
    }

    void TileMapSystem::add(TileMap *tileMap) {
        tileMaps.emplace_back(tileMap);
    }

    void TileMapSystem::remove(const TileMap *tileMap) {
        for (int i = 0; i < tileMaps.size(); i++) {
            if (tileMaps[i] == tileMap) {
                tileMaps.erase(tileMaps.begin() + i);
                break;
            }
        }
    }

    void TileMapSystem::render() {
        SpriteBatch &spriteBatch = framework.getSpriteBatch();

        for (TileMap* tileMap: tileMaps) {
            tileMap->render(spriteBatch);
        }
    }
}