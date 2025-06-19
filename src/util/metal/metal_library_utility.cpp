//
// Created by Luka Erkapic on 18.06.25.
//

#if __APPLE__

#include <fstream>
#include "util/metal/metal_library_utility.h"

namespace gpu_util {
    MTL::Library *MetalLibraryUtility::create(MTL::Device *device, const std::string &filePath) {

        logger->info("Creating Metal library");

        // Check if file exists.
        std::ifstream file(filePath);
        if (!file.good()) {
            const std::string msg = "MetalLibraryUtility::create: Cannot find file under path " + filePath + ".";
            if (logger != nullptr) {
                logger->error(msg);
            }
            file.close();
            return nullptr;
        }
        file.close();

        // Set the label.
        NS::String *nsFilePath = NS::String::string(filePath.c_str(), NS::StringEncoding::UTF8StringEncoding);

        NS::Error *error;
        MTL::Library *library = device->newLibrary(nsFilePath, &error);
        nsFilePath->release();

        // Handle error
        if (error) {
            const char *c_str = error->debugDescription()->cString(NS::StringEncoding::UTF8StringEncoding);
            const std::string msg = "MetalLibraryUtility::create: Failed to create new library. Error: " +
                                    std::string(c_str);
            if (logger != nullptr) {
                logger->error(msg);
            }
            error->release();
            return nullptr;
        }

        return library;
    }
}

#endif
