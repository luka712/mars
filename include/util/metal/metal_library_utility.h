//
// Created by Luka Erkapic on 18.06.25.
//

#if __APPLE__

#ifndef METAL_LIBRARY_UTILITY_H
#define METAL_LIBRARY_UTILITY_H

#include <string>
#include "util/metal.h"
#include "util/logger.h"

namespace gpu_util {
    class MetalLibraryUtility {
    public:
        //! The constructor.
        //! @param logger The optional logger.
        explicit MetalLibraryUtility(Logger &logger) : logger(logger) {
        }

        //! Creates a Metal shader library from a precompiled `.metallib` file.
        //!
        //! This function loads a Metal shader library using the specified file path
        //! and Metal device. The file must be a valid `.metallib` compiled with Xcode or `metal` CLI tools.
        //!
        //! @param device
        //!     A valid pointer to an MTL::Device. This represents the GPU context in which the library will be used.
        //!
        //! @param filePath
        //!     A `std::string` containing the full path to a compiled Metal library file (with `.metallib` extension).
        //!
        //! @return
        //!     A pointer to an `MTL::Library` object if the library was successfully loaded; otherwise, `nullptr`.
        //!
        //! @note
        //!     The caller is responsible for releasing the returned `MTL::Library*` when it is no longer needed.
        //!
        //! @see https://developer.apple.com/documentation/metal/mtldevice/1433400-newlibrary
        //!
        MTL::Library *create(MTL::Device *device, const std::string &filePath);

    private:
        Logger &logger;
    };
}

#endif //METAL_LIBRARY_UTILITY_H

#endif
