//
// Created by lukaa on 10.1.2025..
//

#ifndef TILEMAP2D_H
#define TILEMAP2D_H

#include "TileMapChunk.h"
#include "core/math/color.h"
#include "core/sprite/game_sprite.h"
#include "ecs/transform/RectTransform.h"
#include "ecs/camera/Camera2D.h"

namespace mars {

    class Framework;

    //! The TileMap class.
    //! Used to create a tile map.
    class TileMap : public AComponent {
    public:
        //! Construct a new TileMap object.
        //! @param entity The entity that the component is attached to.
        explicit TileMap(Entity* entity);

        //! Get the rect transform.
        //! @return The rect transform. If not set, returns nullptr.
        [[nodiscard]] const RectTransform* getRectTransform() const;

        //! Get the texture of the tile map.
        //! @return The texture of the tile map.
        [[nodiscard]] const std::shared_ptr<Texture2D> &getTexture() const { return texture; }

        //! Set the texture of the tile map.
        //! @param texture The texture of the tile map.
        void setTexture(const std::shared_ptr<Texture2D> &texture) { this->texture = texture; }

        void initialize() override;

        //! Loads the tiles into the tile map.
        //! @param tileSize The size of a tile in a tile map. All tiles in map should be of same size.
        //! @param tiles The tiles of a tile map. Tile map start at index 0 and each next
        //! tile is advanced by <code>tileSize.x</code> in a single row. So if tile map is 128x128 and tile size is
        //! 32x32 there will be 16 tiles. 4 per row, for 4 rows.
        void loadTiles(glm::vec2 tileSize, const std::vector<std::vector<int32_t>> &tiles);

        //! Render the tile map.
        //! @param spriteBatch The sprite batch.
        //! @param camera The camera.
        void render(SpriteBatch& spriteBatch, const Camera2D& camera) const;

        std::string toString() override;

        //! The size of tiles.
        glm::vec2 tileSize;

        //! The scale of tile map.
        float scale;

        //! The tint color of tile map.
        Color color;
    protected:
        RectTransform* rectTransform{};
        std::vector<TileMapChunk> chunks;
        std::shared_ptr<Texture2D> texture;
    };
}


#endif //TILEMAP2D_H
