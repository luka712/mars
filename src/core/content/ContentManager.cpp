//
// Created by Erkapic Luka on 31.12.2024.
//

#include <stdexcept>
#include "Framework.h"
#include "core/content/ContentManager.h"

namespace mars {
    ContentManager::ContentManager(Framework &framework)
        : framework(framework), rootDirectory("content") {
    }

    const std::string &ContentManager::getRootDirectory() {
        return rootDirectory;
    }

    void ContentManager::setRootDirectory(const std::string &rootDirectory) {
        this->rootDirectory = rootDirectory;
    }

    std::shared_ptr<AContent> ContentManager::load(
        const std::string &assetFilePath,
        const std::type_info &typeInfo,
        const std::string &key) {

        const std::string fullPath = rootDirectory + "/" + assetFilePath;

        // Check if content is already loaded by full path.
        if (contentMap.contains(fullPath)) {
            return contentMap[fullPath];
        }

        // Check if content is already saved by key.
        if (!key.empty() && contentMap.contains(key)) {
            return contentMap[key];
        }

        // Load the content.
        if (typeInfo.name() == typeid(Texture2D).name()) {
            std::shared_ptr<AContent> content = framework.getTextureFactory().createTextureFromImageFile(fullPath);

            if (!key.empty()) {
                contentMap[key] = content;
            }

            contentMap[fullPath] = content;

            return content;
        }

        const std::string msg = "Cannot resolve content type for asset \"" + assetFilePath + "\".";
        framework.getLogger().error(msg.c_str());
        throw std::runtime_error(msg);
    }
}
