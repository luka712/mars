# Outputs:
# SDL2_IMAGE_INCLUDE_DIR - where to find SDL_image.h.
# SDL2_IMAGE_LIBRARY - the name of the library to link against

# Inputs:
# SDL2_IMAGE_PATH - path to SDL2image installation if a custom path is needed.

# Set the search paths for the SDL2image library
SET(SDL2_IMAGE_SEARCH_PATHS
        ~/Library/Frameworks
        /Library/Frameworks
        /usr/local
        /usr
        /sw # Fink
        /opt/local # DarwinPorts
        /opt/csw # Blastwave
        /opt
        ${SDL2_IMAGE_PATH}
)

# Find the SDL2image include directory
FIND_PATH(SDL2_IMAGE_INCLUDE_DIR SDL_image.h
        PATH_SUFFIXES include/SDL2 include
        PATHS ${SDL2_IMAGE_SEARCH_PATHS}
)

# Determine the library path suffixes based on the architecture
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(PATH_SUFFIXES lib64 lib/x64 lib)
else()
    set(PATH_SUFFIXES lib/x86 lib)
endif()

FIND_LIBRARY(SDL2_IMAGE_LIBRARY
        NAMES SDL2_image
        HINTS
        PATH_SUFFIXES ${PATH_SUFFIXES}
        PATHS ${SDL2_IMAGE_SEARCH_PATHS}
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(SDL2_image REQUIRED_VARS SDL2_IMAGE_LIBRARY SDL2_IMAGE_INCLUDE_DIR)