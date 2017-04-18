cmake_minimum_required(VERSION 3.0)

project(LibImageCpp)

SET(MAJOR_VERSION "0")
SET(MINOR_VERSION "1")
SET(PATCH_VERSION "1" CACHE PATCH_VERSION "The package build number." )

# -------------------------------------------------------------------------
# -----------------------   Options and Parameters  -----------------------
# -------------------------------------------------------------------------
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

# -------------------------------------------------------------------------
# -----------------------   Config Toolchain        -----------------------
# -------------------------------------------------------------------------
if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-std=c++11)
    add_definitions(-Wall -Wextra)
    IF(CMAKE_BUILD_TYPE MATCHES RELEASE)
        add_definitions(-DNDEBUG)
        add_definitions(-DELPP_DISABLE_TRACE_LOGS)
    ENDIF(CMAKE_BUILD_TYPE MATCHES RELEASE)
    set(CMAKE_C_FLAGS_DEBUG ${CMAKE_C_FLAGS_DEBUG} -O0 -g)
endif()
add_definitions(-DLIB_IMAGE_CPP_RELEASE="${MAJOR_VERSION}.${MINOR_VERSION}.${PATCH_VERSION}")
add_definitions(-DCMAKE_SOURCE_DIR="${CMAKE_SOURCE_DIR}/")

#add headers for editor
FILE(GLOB_RECURSE HeaderFiles "${PROJECT_SOURCE_DIR}/libimagecpp/*.h")
add_custom_target(headers SOURCES ${HeaderFiles})

# -------------------------------------------------------------------------
# -----------------------      Manage Modules       -----------------------
# -------------------------------------------------------------------------
add_subdirectory ( libimagecpp )
