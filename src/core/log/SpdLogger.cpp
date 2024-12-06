//
// Created by luka on 06/12/24.
//

#ifndef __EMSCRIPTEN__

#include <spdlog/spdlog.h>
#include "core/log/SpdLogger.h"

namespace mars {

    void SpdLogger::info(const char *msg) {
        spdlog::info(msg);
    }

    void SpdLogger::warn(const char *msg) {
        spdlog::warn(msg);
    }

    void SpdLogger::error(const char *msg) {
        spdlog::error(msg);
    }
}

#endif
