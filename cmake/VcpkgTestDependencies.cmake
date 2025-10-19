find_package(Catch2 CONFIG REQUIRED)

set(TEST_PACKAGES_LIBRARIES
        ${PACKAGES}
        Catch2::Catch2
        Catch2::Catch2WithMain
)

set(TEST_PACKAGES_INCLUDE
        ${PACKAGES_INCLUDE}
)