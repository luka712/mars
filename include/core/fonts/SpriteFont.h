//
// Created by luka on 04/01/25.
//

#ifndef SPRITEFONT_H
#define SPRITEFONT_H

#include <memory>
#include <map>
#include "core/life_management/State.h"
#include "core/texture/texture2d.h"
#include "core/fonts/SpriteFontCharacter.h"

namespace mars {
    //! The SpriteFont class.
    class SpriteFont {
    public:

        //! Construct a new SpriteFont object.
        //! @param texture The texture of the font.
        //! @param lineHeight The line height of the font.
        SpriteFont(const std::shared_ptr<Texture2D>& texture, float lineHeight);

        //! Gets the texture of the font.
        //! @return The texture of the font.
        [[nodiscard]] Texture2D* getTexture() const {
            return texture.get();
        }

        //! Gets the character.
        [[nodiscard]] float getLineHeight() const {
            return lineHeight;
        }

        //! Gets the character.
        const SpriteFontCharacter* operator[] (const char character) const {
            return characters.at(character);
        }

        //! Gets the state.
        //! @return The state.
        [[nodiscard]] State getState() const {
            return state;
        }

        //! Create a character in the sprite font.
        //! @param character The character.
        //! @param size The size of the character.
        //! @param offset The offset of the character.
        //! @param textureCoords The texture coordinates of the character.
        //! @param advance The advance of the character.
        void createCharacter(char character, glm::vec2 size, glm::vec2 offset, const Quad &textureCoords, float advance);

        //! Measure the string.
        //! @param text The text.
        //! @return The size of the text.
        [[nodiscard]] glm::vec2 measureString(const std::string& text) const;

        //! Destroy the sprite font.
        void destroy();

    private:
        State state;
        std::map<char, SpriteFontCharacter*> characters;
        std::shared_ptr<Texture2D> texture;
        float lineHeight;
    };
}



#endif //SPRITEFONT_H
