# -------------------------------------------------------------------------
# Build LibImageCpp
# -------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.0)

project( imagecpp )

# -------------------------------------------------------------------------
# ---------------------   External Dependencies       ---------------------
# -------------------------------------------------------------------------
find_package(Imlib2)
SET( LIBS ${LIBS} ${IMLIB2_LIBRARIES} )
SET( INCLUDES ${INCLUDES} ${IMLIB2_INCLUDE_DIR} )

# -------------------------------------------------------------------------
# -----------------------   Compile Binary          -----------------------
# -------------------------------------------------------------------------
include_directories(${ROOT} ${INCLUDES})
aux_source_directory( ${PROJECT_SOURCE_DIR} LIBIMAGECPP_SOURCES )

add_library( imagecpp SHARED ${LIBIMAGECPP_SOURCES} )
target_link_libraries( imagecpp ${LIBS})

#add headers for editor
FILE(GLOB_RECURSE HeaderFiles "${PROJECT_SOURCE_DIR}/*.h")
add_custom_target(libimagecpp-headers SOURCES ${HeaderFiles})
