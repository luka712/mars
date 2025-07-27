//
// Created by Erkapic Luka on 31.12.2024.
//

#ifndef CONTENT_MANAGER_H
#define CONTENT_MANAGER_H

#include <memory>
#include <string>
#include <map>
#include "core/texture/texture2d.h"

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
        //! @param key The optional key by which asset can be found. If empty <code>("")</code> asset is saved only by <code>assetFilePath</code>.
        //! @return The shared pointer to the asset.
        std::shared_ptr<AContent> load(const std::string &assetFilePath, const std::type_info& typeInfo, const std::string& key = "");

        //! Load an asset from the file.
        //! @tparam T The type of the asset.
        //! @param assetFilePath The path to the asset.
        //! @param key The optional key by which asset can be found. If empty <code>("")</code> asset is saved only by <code>assetFilePath</code>.
        //! @return The shared pointer to the asset.
        template<typename T>
        std::shared_ptr<T> load(const std::string &assetFilePath, const std::string& key = "") {
            const std::shared_ptr<AContent> content = load(assetFilePath, typeid(T), key);
            T* ptr = static_cast<T *>(content.get());
            return std::shared_ptr<T>(ptr);
        }

    private:
        Framework& framework;
        //! The map of the content.
        //! Note that same content can be saved twice. It's always saved by the <code>assetFilePath</code>.
        //! Optionally, it can be saved by the <code>key</code> when <code>load</code> method is called with the <code>key</code> parameter.
        std::map<std::string, std::shared_ptr<AContent>> contentMap;
        std::string rootDirectory;
    };

}

#endif //CONTENT_MANAGER_H
