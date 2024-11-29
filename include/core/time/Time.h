//
// Created by lukaa on 29.11.2024
//

#ifndef TIME_H
#define TIME_H

namespace mars {
    //! Provides information about time.
    struct Time {

        //! Construct a new Time object.
        //! @param elapsedTimeMS The total elapsed time in milliseconds.
        //! @param deltaTimeMs The delta time in milliseconds.
        Time(const float elapsedTimeMS, const float deltaTimeMs)
            : elapsedTimeMS(elapsedTimeMS), deltaTimeMs(deltaTimeMs) {
        }

        //! Total elapsed time in milliseconds.
        [[nodiscard]] float getElapsedTimeMS() const { return elapsedTimeMS; }

        //! Total elapsed time in seconds.
        [[nodiscard]] float getElapsedTimeSec() const { return elapsedTimeMS / 1000.0f; }

        //! Delta time in seconds. This is the time between the current frame and the last frame in seconds.
        [[nodiscard]] float getDeltaTimeSec() const { return deltaTimeMs / 1000.0f; }

        //! Delta time in milliseconds. This is the time between the current frame and the last frame in milliseconds.
        [[nodiscard]] float getDeltaTimeMS() const { return deltaTimeMs; }

    private:
        float elapsedTimeMS = 0.0f;
        float deltaTimeMs = 0.0f;
    };
}

#endif //TIME_H
