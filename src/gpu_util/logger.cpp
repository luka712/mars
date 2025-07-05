//
// Created by Luka Erkapic on 20.06.25.
//

#include "gpu_util/logger.h"
#include "spdlog/spdlog.h"

namespace gpu_util {
    void Logger::info(const std::string &msg) {
        info(msg.c_str());
    }

    void Logger::warn(const std::string &msg) {
        warn(msg.c_str());
    }

    void Logger::error(const std::string &msg) {
        error(msg.c_str());
    }

    void SpdLogger::info(const char *msg) {
        spdlog::info(msg);
    }

    void SpdLogger::warn(const char *msg) {
        spdlog::warn(msg);
    }

    void SpdLogger::error(const char *msg) {
        spdlog::error(msg);
    }

    void MockLogger::info(const char *msg) {
    }

    void MockLogger::warn(const char *msg) {
    }

    void MockLogger::error(const char *msg) {
    }
}
