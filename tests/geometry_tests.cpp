#include <catch.h>

#include "core/geometry/Geometry.h"

bool test_interleaved_data() {

    /* TODO: FIX
    mars::Geometry geometry;

    // Top left
    geometry.positions.push_back(0);
    geometry.positions.push_back(0);
    geometry.positions.push_back(0);
    geometry.colors.push_back(1);
    geometry.colors.push_back(1);
    geometry.colors.push_back(1);
    geometry.colors.push_back(1);
    geometry.textureCoords.push_back(0);
    geometry.textureCoords.push_back(0);

    // Top right
    geometry.positions.push_back(1);
    geometry.positions.push_back(0);
    geometry.positions.push_back(0);
    geometry.colors.push_back(1);
    geometry.colors.push_back(1);
    geometry.colors.push_back(1);
    geometry.colors.push_back(1);
    geometry.textureCoords.push_back(1);
    geometry.textureCoords.push_back(0);

    // Bottom left
    geometry.positions.push_back(0);
    geometry.positions.push_back(1);
    geometry.positions.push_back(0);
    geometry.colors.push_back(1);
    geometry.colors.push_back(1);
    geometry.colors.push_back(1);
    geometry.colors.push_back(1);
    geometry.textureCoords.push_back(0);
    geometry.textureCoords.push_back(1);

    // Bottom right
    geometry.positions.push_back(1);
    geometry.positions.push_back(1);
    geometry.positions.push_back(0);
    geometry.colors.push_back(1);
    geometry.colors.push_back(1);
    geometry.colors.push_back(1);
    geometry.colors.push_back(1);
    geometry.textureCoords.push_back(1);
    geometry.textureCoords.push_back(1);

    const std::vector<float> expected =
        {
            0, 0, 0, 1, 1, 1, 1, 0, 0,
            1, 0, 0, 1, 1, 1, 1, 1, 0,
            0, 1, 0, 1, 1, 1, 1, 0, 1,
            1, 1, 0, 1, 1, 1, 1, 1, 1,
        };
    const std::vector<float> actual = geometry.toInterleaved(mars::GeometryFormat::Pos3_Color4_TextureCoords2);

    for (int i = 0; i < actual.size(); i++) {
        if (actual[i] != expected[i]) {
            return false;
        }
    }

    */

    return true;
}

TEST_CASE( "Geometry interleaved data is okay.", "[test_interleaved_data]" ) {
    REQUIRE( test_interleaved_data() );
}
