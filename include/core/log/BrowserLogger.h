//
// Created by luka on 06/12/24.
//
#ifndef BROWSERLOGGER_H
#define BROWSERLOGGER_H

#if __EMSCRIPTEN__

#include "core/log/Logger.h"

namespace mars {
    //! Logs information to the browser console.
    //! Used for __EMSCRIPTEN__ builds.
    class BrowserLogger : public Logger {
        public:
            void info(const char *msg) override;

            void warn(const char *msg) override;

            void error(const char *msg) override;
    };
}


#endif //BROWSERLOGGER_H

#endif