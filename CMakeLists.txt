cmake_minimum_required(VERSION 3.0)

project(LibImageCpp)

SET(MAJOR_VERSION "0")
SET(MINOR_VERSION "1")
SET(PATCH_VERSION "1" CACHE PATCH_VERSION "The package build number." )

# -------------------------------------------------------------------------
# -----------------------   Options and Parameters  -----------------------
# -------------------------------------------------------------------------
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
option(build_tests "Build all unit tests." OFF)
option(build_saples "Build samples." OFF)

SET(TESTFILES "/home/e3a/testfiles" CACHE TESTFILES "The path to the testfiles.")

# -------------------------------------------------------------------------
# -----------------------   Config Toolchain        -----------------------
# -------------------------------------------------------------------------
if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-std=c++14)
endif()
set(CMAKE_C_FLAGS_DEBUG ${CMAKE_C_FLAGS_DEBUG} -O0 -g)
add_definitions(-DDEBUG )
add_definitions(-DLIB_IMAGE_CPP_RELEASE="${MAJOR_VERSION}.${MINOR_VERSION}.${PATCH_VERSION}")
add_definitions(-DTESTFILES="${TESTFILES}/")
add_definitions(-DCMAKE_SOURCE_DIR="${CMAKE_SOURCE_DIR}/")
if( build_tests )
add_definitions(-DBUILD_TESTS)
endif()
add_definitions(-Wall -Wextra)

IF(CMAKE_BUILD_TYPE MATCHES RELEASE)
    add_definitions(-DNDEBUG)
    add_definitions(-DELPP_DISABLE_TRACE_LOGS)
ENDIF(CMAKE_BUILD_TYPE MATCHES RELEASE)

#add headers for editor
FILE(GLOB_RECURSE HeaderFiles "${PROJECT_SOURCE_DIR}/libimagecpp/*.h")
add_custom_target(headers SOURCES ${HeaderFiles})

# -------------------------------------------------------------------------
# -----------------------      Manage Modules       -----------------------
# -------------------------------------------------------------------------
add_subdirectory ( libimagecpp )
if( build_saples )
    add_subdirectory ( samples )
endif()
if( build_tests )
    add_subdirectory ( test )
endif()
