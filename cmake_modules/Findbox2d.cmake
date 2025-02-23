include(FetchContent)

FetchContent_Declare(
  box2d
  GIT_REPOSITORY https://github.com/erincatto/box2d.git
  GIT_TAG v2.4.2
)

FetchContent_MakeAvailable(box2d)

SET(BOX2D_LIBRARY box2d)
SET(BOX2D_INCLUDE_DIR ${box2d_SOURCE_DIR}/include)

