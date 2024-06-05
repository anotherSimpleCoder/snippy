find_path(SNDFILE_INCLUDE_DIR NAMES "sndfile.h" HINTS ${SNDFILE_ROOT_DIR})

if(CMAKE_SYSTEM_NAME STREQUAL "Darwin") 
    find_library(SNDFILE_LIBRARIES NAMES sndfile "libsndfile.dylib" HINTS ${SNDFILE_ROOT_DIR})
else()
find_library(SNDFILE_LIBRARIES NAMES sndfile "libsndfile.dylib" HINTS ${SNDFILE_ROOT_DIR})
endif()

include(FindPackageHandleStandardArgs)
 
find_package_handle_standard_args(SNDFILE DEFAULT_MSG SNDFILE_LIBRARIES SNDFILE_INCLUDE_DIR)