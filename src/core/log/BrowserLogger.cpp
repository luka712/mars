//
// Created by luka on 06/12/24.
//

#if __EMSCRIPTEN__


#include <emscripten.h>
#include "core/log/BrowserLogger.h"

namespace mars {
    void BrowserLogger::info(const char *msg) {
        EM_ASM(console.log(UTF8ToString($0)), msg);
    }

    void BrowserLogger::warn(const char *msg) {
        EM_ASM(console.warn(UTF8ToString($0)), msg);
    }

    void BrowserLogger::error(const char *msg) {
        EM_ASM(console.error(UTF8ToString($0)), msg);
    }
}

#endif