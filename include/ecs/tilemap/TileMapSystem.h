//
// Created by erkapic luka on 11.1.2025.
//

#ifndef TILEMAPSYSTEM_H
#define TILEMAPSYSTEM_H

#include <vector>
#include "ecs/tilemap/TileMap.h"
#include "ecs/layer/Layer.h"
#include "ecs/camera/Camera2D.h"

namespace mars {

    class Framework;

    //! The system that renders the tile map components.
    class TileMapSystem {
    public:
        //! Construct a new TileMapSystem object.
        //! @param framework The framework.
        explicit TileMapSystem(Framework& framework);

        //! Add a tile map component to the system.
        //! @param tileMap The tile map component.
        void add(TileMap* tileMap);

        //! Called when frame starts. Prepares the system for rendering, by sorting according to layer order.
        void frameStart();

        //! Remove a tile map component from the system.
        //! @param tileMap The tile map component.
        void remove(const TileMap *tileMap);

        //! Render the tile map components.
        //! @param currentLayerOrder The current layer order.
        //! @param camera The camera.
        void render(uint32_t currentLayerOrder, Camera2D& camera);
    private:
        Framework& framework;
        std::vector<TileMap*> tileMaps;

        //! Layer order is key, while sprites to render are values.
        std::map<uint32_t, std::vector<TileMap *> > layerOrderTileMapsMap;
        //! Layer order is key, while sprites to render count is value.
        std::map<uint32_t, uint32_t> layerOrderTileMapCountMap;

        //! Move the tile map to the layer map.
        //! @param tileMap The tile map.
        void moveToLayerMap(TileMap *tileMap);
    };
}

#endif //TILEMAPSYSTEM_H
