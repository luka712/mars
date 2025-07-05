# PRE-SETUP
if(WIN32)
    # Find and set the manifest tool path
    FIND_PROGRAM(CMAKE_MT mt.exe
            PATHS
            "C:/Program Files (x86)/Windows Kits/10/bin/10.0.22621.0/x64"
            DOC "Path to mt.exe"
    )

    if(NOT CMAKE_MT)
        MESSAGE(WARNING "mt.exe not found - manifest embedding may fail")
    endif()
endif()


SET(WINDOWS_LIBRARIES d3d11 dxgi d3dcompiler)
