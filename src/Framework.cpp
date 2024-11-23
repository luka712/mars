//
// Created by lukaa on 23.11.2024..
//

#include "Framework.h"


namespace mars {
    Framework::Framework(FrameworkOptions options){
        windowManager = new WindowManager(WindowManagerOptions {
            options.windowBounds
        });
    };

    void Framework::Initialize() {
        windowManager->Initialize();

        // TODO: Other initialization code goes here.

        windowManager->RunEventLoop();
    }

    void Framework::Destroy() {


        windowManager->Destroy();
        delete windowManager;
    }
}
