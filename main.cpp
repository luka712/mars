#include <iostream>
#include "Framework.h"
// #include "spdlog/spdlog.h"
// #include "spdlog/sinks/basic_file_sink.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main(int argc, char* argv[]) {

    // spdlog::info("Sample Info output.", 1);
    // spdlog::warn("Sample Warn output.");
    // spdlog::error("Sample Error output.");

    mars::Framework framework(mars::FrameworkOptions {
        mars::WindowBounds(1280, 720)
    });
    framework.subscribeToRenderEvent([&]() {

        framework.getSpriteBatch().begin();
        framework.getSpriteBatch().draw({ 100, 100, 200, 200}, mars::Color::red());
        framework.getSpriteBatch().end();

    });
    framework.initialize();
    framework.destroy();

    // auto filelog = spdlog::basic_logger_mt("sample-logger", "sample-log.txt");

  //   filelog.get()->info("Sample Info output.");
   // filelog.get()->warn("Sample Warn output.");
   // filelog.get()->error("Sample Error output.");

    // SPDLOG_TRACE("Sample Trace output.");

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.