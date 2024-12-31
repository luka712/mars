//
// Created by lukaa on 31.12.2024..
//

#include "Framework.h"
#include "core/content/ContentManager.h"

namespace mars {

    ContentManager::ContentManager(Framework &framework)
        : framework(framework) , rootDirectory("Content"){
    }

    const std::string & ContentManager::getRootDirectory() {
        return rootDirectory;
    }

    void ContentManager::setRootDirectory(const std::string &rootDirectory) {
        this->rootDirectory = rootDirectory;
    }

    std::shared_ptr<AContent> ContentManager::load(const std::string &assetFilePath, const std::type_info &typeInfo) {

        std::string fullPath = rootDirectory + "/" + assetFilePath;

        if (contentMap.contains(fullPath)) {
            return  contentMap[fullPath];
        }

        if (typeInfo.name() == typeid(Texture2D).name()) {
            std::shared_ptr<AContent> content = framework.getTextureFactory().createTextureFromImageFile(fullPath);
            contentMap[fullPath] = content;
            return content;
        }

        const std::string msg = "Cannot resolve content type for asset \"" + assetFilePath + "\".";
        // ReSharper disable once CppClassIsIncomplete
        framework.getLogger().error(msg.c_str());
        throw std::runtime_error(msg);

    }
}
