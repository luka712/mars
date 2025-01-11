//
// Created by lukaa on 10.1.2025..
//

#include "ecs/tilemap/TileMapChunk.h"

namespace mars {
    TileMapChunk::TileMapChunk(int32_t x, int32_t y, Rect sourceRect)
        : x(x), y(y), sourceRect(sourceRect){
    }
}
