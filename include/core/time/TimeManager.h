//
// Created by lukaa on 29.11.2024
//

#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include "core/time/Time.h"

namespace mars {

    //! The time manager.
    class TimeManager {
    public:
        //! Construct a new TimeManager object.
        //! @param desiredFPS The desired frames per second. By default, it is 60.
        explicit TimeManager(float desiredFPS = 60.0f);

        //! Get the time.
        Time& getTime() { return time; }

        //! Called once before the first frame starts to prepare the time.
        void prepareStart();

        //! Should be called at the start of the frame.
        void frameStart();

        //! Should be called at the end of the frame.
        void frameEnd();

    private:
        Time time;
        float desiredMsPerFrame;
        float startTime{};
    };
}


#endif //TIMEMANAGER_H
