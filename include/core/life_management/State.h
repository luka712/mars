//
// Created by lukaa on 29.11.2024..
//

#ifndef FRAMEWORKSTATE_H
#define FRAMEWORKSTATE_H

namespace mars {

    //! The current state of a resources.
    enum State {
        CREATED,
        INITIALIZED,
        DESTROYING,
        DESTROYED
    };

}

#endif //FRAMEWORKSTATE_H
