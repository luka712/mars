//
// Created by luka on 06/12/24.
//

#ifndef SPDLOGGER_H
#define SPDLOGGER_H

#ifndef __EMSCRIPTEN__

#include <core/log/Logger.h>

namespace mars {
    //! The spdlog implementation of a \see Logger
    class SpdLogger final : public Logger {
    public:
        void info(const char *msg) override;

        void warn(const char *msg) override;

        void error(const char *msg) override;
    };
}

#endif

#endif //SPDLOGGER_H
