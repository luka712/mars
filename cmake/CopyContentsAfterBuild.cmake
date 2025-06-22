
# Validate required variables
if(NOT TARGET_NAME )
    message(FATAL_ERROR "TARGET_NAME must be set before including this file")
endif()

add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
               "${CMAKE_SOURCE_DIR}/content"
               "$<TARGET_FILE_DIR:${TARGET_NAME}>/content"
        COMMENT "Copying content folder to binary folder"
)
