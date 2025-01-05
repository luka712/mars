//
// Created by lukaa on 5.1.2025..
//

#include <fstream>
#include "Framework.h"
#include "core/loaders/SpriteFontLoader.h"


namespace mars {
    SpriteFontLoader::SpriteFontLoader(Framework &framework)
        : framework(framework) {
    }

    std::shared_ptr<SpriteFont> SpriteFontLoader::createSnowBSpriteFont(
        tinyxml2::XMLNode &fontNode,
        const std::shared_ptr<Texture2D>& texture) const {

        tinyxml2::XMLNode *commonNode = fontNode.FirstChildElement("common");
        if (commonNode == nullptr) {
            const std::string msg = "The xml file does not contain a 'common' node. Please check xml format.";
            framework.getLogger().error(msg);
            throw std::runtime_error(msg);
        }

        float lineHeight = commonNode->ToElement()->FloatAttribute("lineHeight");
        if (lineHeight == 0.0f) {
            const std::string msg = "The xml file does not contain a 'lineHeight' attribute in the 'common' node. Please check xml format.";
            framework.getLogger().error(msg);
            throw std::runtime_error(msg);
        }

        std::shared_ptr<SpriteFont> spriteFont = std::make_shared<SpriteFont>(texture, lineHeight);

        auto textureWidth = static_cast<float>(texture->getWidth());
        auto textureHeight = static_cast<float>(texture->getHeight());

        tinyxml2::XMLElement *charsNode = fontNode.FirstChildElement("chars");
        if (charsNode == nullptr) {
            const std::string msg = "The xml file does not contain a 'chars' node. Please check xml format.";
            framework.getLogger().error(msg);
            throw std::runtime_error(msg);
        }

        tinyxml2::XMLElement* charNode = charsNode->FirstChildElement();
        while (charNode != nullptr) {
            const int id = charNode->IntAttribute("id");
            const float x = charNode->FloatAttribute("x");
            const float y = charNode->FloatAttribute("y");
            const float width = charNode->FloatAttribute("width");
            const float height = charNode->FloatAttribute("height");
            const float xOffset = charNode->FloatAttribute("xoffset");
            const float yOffset = charNode->FloatAttribute("yoffset");
            const float xAdvance = charNode->FloatAttribute("xadvance");

            const float x1 = x / textureWidth;
            const float y1 = y / textureHeight;
            const float x2 = (x + width) / textureWidth;
            const float y2 = (y + height) / textureHeight;

            Quad textureCoords = Quad(
                glm::vec2(x1,y1),
                glm::vec2(x2, y1),
                glm::vec2(x1, y2),
                glm::vec2(x2, y2));
            spriteFont->createCharacter(
                static_cast<char>(id),
                glm::vec2(width, height),
                glm::vec2(xOffset, yOffset),
                textureCoords,
                xAdvance);

            charNode = charNode->NextSiblingElement();
        }

        return spriteFont;
    }


    std::shared_ptr<SpriteFont> SpriteFontLoader::loadSnowBSpriteFont(
        const std::string &xmlPath,
        std::string texturePath) const {
        tinyxml2::XMLDocument doc;
        doc.LoadFile(xmlPath.c_str());

        if (doc.Error()) {
            const std::string msg = "Failed to load xml file: " + xmlPath;
            framework.getLogger().error(msg);
            throw std::runtime_error(msg);
        }

        // Check if font node exists.
        tinyxml2::XMLElement *fontElement = doc.FirstChildElement("font");
        if (fontElement == nullptr) {
            const std::string msg =
                    "The xml file does not contain a 'font' node. Please check xml format or provide 'texturePath'.";
            framework.getLogger().error(msg);
            throw std::runtime_error(msg);
        }

        if (texturePath.empty()) {

            // Check if pages node exists.
            tinyxml2::XMLElement *pagesElement = fontElement->FirstChildElement("pages");
            if (pagesElement == nullptr) {
                const std::string msg =
                        "The xml file does not contain a 'pages' node. Please check xml format or provide 'texturePath'.";
                framework.getLogger().error(msg);
                throw std::runtime_error(msg);
            }

            // Check if page node exists.
            tinyxml2::XMLElement *pageElement = pagesElement->FirstChildElement("page");
            if (pageElement == nullptr) {
                const std::string msg =
                        "The xml file does not contain a 'page' node. Please check xml format or provide 'texturePath'.";
                framework.getLogger().error(msg);
                throw std::runtime_error(msg);
            }

            const tinyxml2::XMLAttribute *fileAttr = pageElement->FindAttribute("file");
            if (fileAttr == nullptr) {
                const std::string msg =
                        "The xml file does not contain a 'file' attribute in the 'page' node. Please check xml format or provide 'texturePath'.";
                framework.getLogger().error(msg);
                throw std::runtime_error(msg);
            }

            texturePath = fileAttr->Value();

            size_t lastSlashIndex = xmlPath.rfind('\\');
            if (lastSlashIndex == std::string::npos) {
                lastSlashIndex = xmlPath.rfind('/');
            }

            std::string directory = xmlPath.substr(0, lastSlashIndex);
            texturePath = directory + "/" + texturePath;
        }

        std::shared_ptr<Texture2D> texture = framework
                .getTextureFactory()
                .createTextureFromImageFile(texturePath);

        return createSnowBSpriteFont(*fontElement, texture);
    }
}
