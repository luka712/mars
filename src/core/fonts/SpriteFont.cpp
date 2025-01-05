//
// Created by luka on 04/01/25.
//

#include <utility>

#include "core/fonts/SpriteFont.h"

namespace mars {
    SpriteFont::SpriteFont(const std::shared_ptr<Texture2D> &texture, float lineHeight)
        : texture(texture), lineHeight(lineHeight) {
        state = CREATED;
    }

    void SpriteFont::createCharacter(
        char character,
        const glm::vec2 size,
        const glm::vec2 offset,
        const Quad &textureCoords,
        const float advance) {
        characters[character] = new SpriteFontCharacter(
          character,
          textureCoords,
          size,
          offset,
          advance);
    }

    glm::vec2 SpriteFont::measureString(const std::string &text) const {
        float x = 0;
        float y = 0;
        float maxX = 0;
        for (char character: text) {
            if (character == '\n') {
                y += lineHeight;
                maxX = std::max(maxX, x);
                x = 0;
                continue;
            }

            auto it = characters.find(character);
            if (it != characters.end()) {
                x += it->second->getAdvance();
            }
        }

        maxX = std::max(maxX, x);
        return {maxX, y + lineHeight};
    }

    void SpriteFont::destroy() {
        for (auto& [key, value] : characters) {
            delete value;
        }
        characters.clear();
    }
}
