//
// Created by Luka Erkapic on 18.06.25.
//

#if __APPLE__

#include "gpu_util/metal/metal_function_utility.h"

namespace gpu_util {
    MTL::Function *MetalFunctionUtility::create(MTL::Library *library, const std::string &functionName) {
        MTL::FunctionDescriptor *descriptor = MTL::FunctionDescriptor::alloc()->init();

        // Set function name.
        NS::String *nsFnName = NS::String::string(functionName.c_str(), NS::StringEncoding::UTF8StringEncoding);
        descriptor->setName(nsFnName);

        NS::Error *error;
        MTL::Function *function = library->newFunction(descriptor, &error);

        // release
        descriptor->release();
        nsFnName->release();

        // Handle error
        if (error) {
            const char *c_str = error->description()->string()->cString(NS::StringEncoding::UTF8StringEncoding);
            const std::string msg = "MetalFunctionUtility::create: Failed to create new function. Error: " +
                                    std::string(c_str);
            logger.error(msg);
            error->release();
            return nullptr;
        }

        return function;
    }
}

#endif
