//
// Created by erkapic luka on 11.1.2025.
//

#ifndef TILEMAPSYSTEM_H
#define TILEMAPSYSTEM_H

#include <vector>
#include "ecs/tilemap/TileMap.h"

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

        //! Remove a tile map component from the system.
        //! @param tileMap The tile map component.
        void remove(const TileMap *tileMap);

        //! Render the tile map components.
        void render();
    private:
        Framework& framework;
        std::vector<TileMap*> tileMaps;
    };
}

#endif //TILEMAPSYSTEM_H
