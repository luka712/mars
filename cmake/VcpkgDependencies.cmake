

ADD_COMPILE_DEFINITIONS(USE_STBIMAGE)
ADD_COMPILE_DEFINITIONS(LOAD_PNG)

# Install dependencies as suggested by vcpkg.
find_package(SDL3 CONFIG REQUIRED)
find_package(SDL3_image CONFIG REQUIRED)
FIND_PACKAGE(Stb REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(lua CONFIG REQUIRED)
# find_package(boost CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(tinyxml2 CONFIG REQUIRED)
find_package(EnTT CONFIG REQUIRED)
find_package(box2d CONFIG REQUIRED)
find_package(sol2 CONFIG REQUIRED)
find_package(boost_optional CONFIG REQUIRED)
# Note that tmxlite does not have a config file.
if(WIN32)
set(TMXLITE_LIB ${VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/debug/lib/tmxlite-d.lib)
endif()

if(APPLE)
    set(TMXLITE_LIB ${VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/debug/lib/libtmxlite-s-d.a
                    ${VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/debug/lib/libpugixml.a
                    ${VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/debug/lib/libzstd.a
    )
endif()

set(PACKAGES_LIBRARIES
        ${PACKAGES}
        SDL3::SDL3
        SDL3_image::SDL3_image
        $<IF:$<TARGET_EXISTS:SDL3_image::SDL3_image-shared>,SDL3_image::SDL3_image-shared,SDL3_image::SDL3_image-static>
        ${Stb_INCLUDE_DIR}
        spdlog::spdlog
        glm::glm
        EnTT::EnTT
        tinyxml2::tinyxml2
        # Catch2::Catch2WithMain
        box2d::box2d
        sol2::sol2
        Boost::optional

        ${TMXLITE_LIB}
)

set(PACKAGES_INCLUDE
        ${PACKAGES_INCLUDE}
        ${SDL3_INCLUDE_DIRS}
)