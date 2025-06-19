
# Install dependencies as suggested by vcpkg.
find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(lua CONFIG REQUIRED)
find_package(boost CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(tinyxml2 CONFIG REQUIRED)
find_package(EnTT CONFIG REQUIRED)
find_package(box2d CONFIG REQUIRED)
find_package(sol2 CONFIG REQUIRED)
find_package(boost_optional CONFIG REQUIRED)

set(PACKAGES_LIBRARIES
        ${PACKAGES}
        $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main> $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
        $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>
        spdlog::spdlog
        glm::glm
        EnTT::EnTT
        tinyxml2::tinyxml2
        # Catch2::Catch2WithMain
        box2d::box2d
        sol2::sol2
        Boost::optional
)

set(PACKAGES_INCLUDE
        ${PACKAGES_INCLUDE}
        ${SDL2_INCLUDE_DIRS}
)