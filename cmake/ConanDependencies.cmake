
# Install dependencies as suggested by conan.
find_package(spdlog REQUIRED)
find_package(glm REQUIRED)
find_package(EnTT REQUIRED)
find_package(tinyxml2 REQUIRED)
find_package(box2d REQUIRED)
find_package(sol2 REQUIRED)
find_package(Boost)

find_package(PkgConfig REQUIRED)

pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_IMAGE REQUIRED SDL2_image)

set(PACKAGES_LIBRARIES
        ${PACKAGES}
        ${SDL2_LIBRARIES}
        ${SDL2_IMAGE_LIBRARIES}
        spdlog::spdlog
        glm::glm
        EnTT::EnTT
        tinyxml2::tinyxml2
       # Catch2::Catch2WithMain
        box2d::box2d
        sol2::sol2
        boost::boost
)

set(PACKAGES_INCLUDE
        ${PACKAGES_INCLUDE}
        ${SDL2_INCLUDE_DIRS}
)