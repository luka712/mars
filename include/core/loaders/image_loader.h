//
// Created by lukaa on 21.12.2024.
//

#ifndef IMAGE_LOADER_H
#define IMAGE_LOADER_H

#include <memory>
#include <string>
#include <unordered_map>
#include "core/data/ImageData.h"


namespace mars {

    class Framework;

    //! The ImageLoader class.
    //! Used for loading images.
    class ImageLoader {
    public:
        //! Construct a new ImageLoader object.
        //! @param framework The framework.
        explicit ImageLoader(Framework& framework);

        //! Load an image from the specified path.
        //! @param path The path to the image.
        //! @param cache If true, the image will be cached for later use.
        std::shared_ptr<ImageData> load(const std::string &path, bool cache = false);

        //! Dispose of the temporary cache.
        //! Used internally, call only if you know what you are doing.
        void disposeOfTemporaryCache();

    private:
        Framework& framework;
        std::unordered_map<std::string, std::shared_ptr<ImageData>> tempCache;
        std::unordered_map<std::string, std::shared_ptr<ImageData>> permanentCache;
    };
}

#endif //IMAGE_LOADER_H
