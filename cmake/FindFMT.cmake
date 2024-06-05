find_path(FMT_INCLUDE_DIR NAMES fmt/core.h HINTS ${FMT_ROOT_DIR})
 
if(CMAKE_SYSTEM_NAME STREQUAL "Darwin") 
    find_library(FMT_LIBRARIES NAMES fmt "libfmt.dylib" HINTS ${FMT_ROOT_DIR})
else()
    find_library(FMT_LIBRARIES NAMES fmt "libfmt.so" HINTS ${FMT_ROOT_DIR})
endif()


include(FindPackageHandleStandardArgs)
 
find_package_handle_standard_args(FMT DEFAULT_MSG FMT_LIBRARIES FMT_INCLUDE_DIR)
