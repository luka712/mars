//
// Created by lukaa on 31.12.2024..
//

#ifndef CONTENTMANAGER_H
#define CONTENTMANAGER_H

#include <memory>
#include <string>
#include <map>
#include "core/texture/Texture2D.h"

namespace mars {

    class Framework;

    class ContentManager {

    public:
        //! Construct a new ContentManager object.
        //! @param framework The framework.
        explicit ContentManager(Framework &framework);

        //! Get the root directory.
        //! @return The root directory.
        const std::string& getRootDirectory();

        //! Set the root directory.
        //! @param rootDirectory The root directory.
        void setRootDirectory(const std::string &rootDirectory);

        //! Load an asset from the file.
        //! @param assetFilePath The path to the asset.
        //! @param typeInfo The type of the asset.
        //! @return The shared pointer to the asset.
        std::shared_ptr<AContent> load(const std::string &assetFilePath, const std::type_info& typeInfo);

        //! Load an asset from the file.
        //! @tparam T The type of the asset.
        //! @param assetFilePath The path to the asset.
        //! @return The shared pointer to the asset.
        template<typename T>
        std::shared_ptr<T> load(const std::string &assetFilePath) {
            std::shared_ptr<AContent> content = load(assetFilePath, typeid(T));
            T* ptr = static_cast<T *>(content.get());
            return std::shared_ptr<T>(ptr);
        }

    private:
        Framework& framework;
        std::map<std::string, std::shared_ptr<AContent>> contentMap;
        std::string rootDirectory;
    };

}

#endif //CONTENTMANAGER_H
