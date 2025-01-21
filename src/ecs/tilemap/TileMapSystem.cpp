//
// Created by erkapic luka on 11.1.2025.
//

#include "Framework.h"
#include "ecs/tilemap/TileMapSystem.h"

#include <ecs/entity/Entity.h>


namespace mars {
    TileMapSystem::TileMapSystem(Framework &framework)
        : framework(framework) {
    }

    void TileMapSystem::add(TileMap *tileMap) {
        tileMaps.emplace_back(tileMap);
    }

    void TileMapSystem::frameStart() {
        // Reset the layer count map.
        for (auto &kvp: layerOrderTileMapCountMap) {
            kvp.second = 0;
        }

        // Update the sprite renderers.
        for (TileMap *tileMap: tileMaps) {
            moveToLayerMap(tileMap);
        }
    }

    void TileMapSystem::moveToLayerMap(TileMap *tileMap) {
        const Entity &entity = tileMap->getEntity();
        const Layer &layer = entity.getLayer();

        // If it's not safe to map, we need to add it.
        if (const uint32_t layerOrder = layer.getOrder(); !layerOrderTileMapsMap.contains(layerOrder)) {
            layerOrderTileMapsMap[layerOrder] = {tileMap};
            layerOrderTileMapCountMap[layerOrder] = 1;
        } else {
            uint32_t currentIndex = layerOrderTileMapCountMap[layerOrder];
            layerOrderTileMapsMap[layerOrder][currentIndex] = tileMap;
            layerOrderTileMapCountMap[layerOrder] = currentIndex + 1;
        }
    }


    void TileMapSystem::remove(const TileMap *tileMap) {
        for (int i = 0; i < tileMaps.size(); i++) {
            if (tileMaps[i] == tileMap) {
                tileMaps.erase(tileMaps.begin() + i);
                break;
            }
        }
    }

    void TileMapSystem::render(uint32_t layerOrder) {
        if (!layerOrderTileMapsMap.contains(layerOrder)) {
            return;
        }

        SpriteBatch &spriteBatch = framework.getSpriteBatch();

        for (TileMap *tileMap: layerOrderTileMapsMap[layerOrder]) {
            tileMap->render(spriteBatch);
        }
    }
}
