//
// Created by lukaa on 29.11.2024..
//

#include "core/time/TimeManager.h"
#include <chrono>
#include <SDL3/SDL_timer.h>
#include <iostream>

namespace mars {
    TimeManager::TimeManager(const float desiredFPS)
    : time(0, 0), startTime(0) {
        desiredMsPerFrame = 1000 / desiredFPS;
    }

    void TimeManager::prepareStart() {
        time = Time(0, 0);
    }

    void TimeManager::frameStart() {
        startTime = static_cast<float>(SDL_GetTicks());
    }

    void TimeManager::frameEnd() {
        // Delta time in milliseconds.
        float deltaTime = static_cast<float>(SDL_GetTicks()) - startTime;

        // If the frame was faster than desiredMsPerFrame, we need to delay it since we want to have a fixed frame rate.
        // Essentially we are running too fast, so we need to slow down.
        if(desiredMsPerFrame > deltaTime)
        {
            float delay = desiredMsPerFrame - deltaTime;
            // std::cout << "Elapsed time: " << time.getElapsedTimeMS() << "ms, Delta time: " << time.getDeltaTimeMS() << "ms" << std::endl;

            deltaTime += delay;

            // DELAY.
            SDL_Delay(static_cast<Uint32>(delay));
        }

        time = Time(time.getElapsedTimeMS() + deltaTime, deltaTime);

    }
}
