//
// Created by Erkapic Luka on 27.2.2025.
//

#ifndef BOX2D_FIXTURE_H
#define BOX2D_FIXTURE_H

#include "box2d/b2_fixture.h"
#include "core/physics2d/fixture/AFixture2D.h"

namespace mars {

    class Box2DFixture : public AFixture2D {

    public:
        //! Construct a new Box2DFixture object.
        //! @param fixture The fixture.
        Box2DFixture(b2Fixture* fixture);

    private:
        b2Fixture* fixture{};
    };
}


#endif //BOX2D_FIXTURE_H
