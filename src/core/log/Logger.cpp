//
// Created by luka on 06/12/24.
//

#include "core/log/Logger.h"

namespace mars {

    void Logger::info(const std::string& msg) {
        info(msg.c_str());
    }

    void Logger::warn(const std::string& msg) {
        warn(msg.c_str());
    }

    void Logger::error(const std::string& msg) {
        error(msg.c_str());
    }
}