//
// Created by lukaa on 29.11.2024..
//

#include "core/time/TimeManager.h"
#include <chrono>
#include <SDL_timer.h>

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

        if(desiredMsPerFrame > deltaTime)
        {
            float delay = desiredMsPerFrame - deltaTime;
            deltaTime += delay;

            SDL_Delay(static_cast<Uint32>(delay));
        }

        time = Time(time.getElapsedTimeMS() + deltaTime, deltaTime);
    }
}
