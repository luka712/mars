//
// Created by Luka Erkapic on 18.06.25.
//

#if __APPLE__

#ifndef METAL_FUNCTION_UTILITY_H
#define METAL_FUNCTION_UTILITY_H

#include <string>
#include "core/log/Logger.h"
#include "gpu_util/metal.h"
#include "gpu_util/logger.h"

namespace gpu_util {
    class MetalFunctionUtility {
        public:
        explicit MetalFunctionUtility(Logger& logger)
        : logger(logger) {}

        MTL::Function* create(MTL::Library* library, const std::string& functionName);

    private:
        Logger& logger;
    };
}

#endif //METAL_FUNCTION_UTILITY_H

#endif