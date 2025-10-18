#include <iostream>
#include <sstream>
#include "Framework.h"
#include "asset_toolkit/asset_bundle/AssetBundle.h"
#include "asset_toolkit/asset_bundle/AssetBundleLoader.h"
#include "background/Background.h"
#include "tile/TileManager.h"


// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main(int argc, char* argv[]) {
	// spdlog::info("Sample Info output.", 1);
	// spdlog::warn("Sample Warn output.");
	// spdlog::error("Sample Error output.");

	std::cout << "Hello, World!" << std::endl;

	mars::Framework framework(mars::FrameworkOptions{
		mars::WindowBounds(1920, 1080),
		mars::RenderingBackend::D3D11,
		glm::vec2(1920, 1080)
		});

	framework.initialize();
	TileManager::Initialize(framework.getContentManager());

	std::unique_ptr<Background> background = std::make_unique<Background>(framework.getContentManager());

	framework.subscribeToUpdateEvent([&](const mars::Time time) {
		background->update(const_cast<mars::Time&>(time));
		});

	framework.subscribeToRenderEvent([&]() {
		framework.getSpriteBatch().begin();
		background->render(framework.getSpriteBatch());
		TileManager::Draw(framework.getSpriteBatch());
		framework.getSpriteBatch().end();
		});


	framework.runEventLoop();
	framework.destroy(); // SPDLOG_TRACE("Sample Trace output.");

	return 0;
}


// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.
