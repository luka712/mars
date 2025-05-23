# Avoid multiple calls to find_package to append duplicated properties to the targets
include_guard()########### VARIABLES #######################################################################
#############################################################################################
set(entt_FRAMEWORKS_FOUND_RELEASE "") # Will be filled later
conan_find_apple_frameworks(entt_FRAMEWORKS_FOUND_RELEASE "${entt_FRAMEWORKS_RELEASE}" "${entt_FRAMEWORK_DIRS_RELEASE}")

set(entt_LIBRARIES_TARGETS "") # Will be filled later


######## Create an interface target to contain all the dependencies (frameworks, system and conan deps)
if(NOT TARGET entt_DEPS_TARGET)
    add_library(entt_DEPS_TARGET INTERFACE IMPORTED)
endif()

set_property(TARGET entt_DEPS_TARGET
             APPEND PROPERTY INTERFACE_LINK_LIBRARIES
             $<$<CONFIG:Release>:${entt_FRAMEWORKS_FOUND_RELEASE}>
             $<$<CONFIG:Release>:${entt_SYSTEM_LIBS_RELEASE}>
             $<$<CONFIG:Release>:>)

####### Find the libraries declared in cpp_info.libs, create an IMPORTED target for each one and link the
####### entt_DEPS_TARGET to all of them
conan_package_library_targets("${entt_LIBS_RELEASE}"    # libraries
                              "${entt_LIB_DIRS_RELEASE}" # package_libdir
                              "${entt_BIN_DIRS_RELEASE}" # package_bindir
                              "${entt_LIBRARY_TYPE_RELEASE}"
                              "${entt_IS_HOST_WINDOWS_RELEASE}"
                              entt_DEPS_TARGET
                              entt_LIBRARIES_TARGETS  # out_libraries_targets
                              "_RELEASE"
                              "entt"    # package_name
                              "${entt_NO_SONAME_MODE_RELEASE}")  # soname

# FIXME: What is the result of this for multi-config? All configs adding themselves to path?
set(CMAKE_MODULE_PATH ${entt_BUILD_DIRS_RELEASE} ${CMAKE_MODULE_PATH})

########## GLOBAL TARGET PROPERTIES Release ########################################
    set_property(TARGET EnTT::EnTT
                 APPEND PROPERTY INTERFACE_LINK_LIBRARIES
                 $<$<CONFIG:Release>:${entt_OBJECTS_RELEASE}>
                 $<$<CONFIG:Release>:${entt_LIBRARIES_TARGETS}>
                 )

    if("${entt_LIBS_RELEASE}" STREQUAL "")
        # If the package is not declaring any "cpp_info.libs" the package deps, system libs,
        # frameworks etc are not linked to the imported targets and we need to do it to the
        # global target
        set_property(TARGET EnTT::EnTT
                     APPEND PROPERTY INTERFACE_LINK_LIBRARIES
                     entt_DEPS_TARGET)
    endif()

    set_property(TARGET EnTT::EnTT
                 APPEND PROPERTY INTERFACE_LINK_OPTIONS
                 $<$<CONFIG:Release>:${entt_LINKER_FLAGS_RELEASE}>)
    set_property(TARGET EnTT::EnTT
                 APPEND PROPERTY INTERFACE_INCLUDE_DIRECTORIES
                 $<$<CONFIG:Release>:${entt_INCLUDE_DIRS_RELEASE}>)
    # Necessary to find LINK shared libraries in Linux
    set_property(TARGET EnTT::EnTT
                 APPEND PROPERTY INTERFACE_LINK_DIRECTORIES
                 $<$<CONFIG:Release>:${entt_LIB_DIRS_RELEASE}>)
    set_property(TARGET EnTT::EnTT
                 APPEND PROPERTY INTERFACE_COMPILE_DEFINITIONS
                 $<$<CONFIG:Release>:${entt_COMPILE_DEFINITIONS_RELEASE}>)
    set_property(TARGET EnTT::EnTT
                 APPEND PROPERTY INTERFACE_COMPILE_OPTIONS
                 $<$<CONFIG:Release>:${entt_COMPILE_OPTIONS_RELEASE}>)

########## For the modules (FindXXX)
set(entt_LIBRARIES_RELEASE EnTT::EnTT)
