find_path(DPP_INCLUDE_DIR NAMES dpp/dpp.h HINTS ${DPP_ROOT_DIR})

if(CMAKE_SYSTEM_NAME STREQUAL "Darwin") 
    find_library(DPP_LIBRARIES NAMES dpp "libdpp.dylib" HINTS ${DPP_ROOT_DIR})
else()
    find_library(DPP_LIBRARIES NAMES dpp "libdpp.so" HINTS ${DPP_ROOT_DIR})    
endif()

include(FindPackageHandleStandardArgs)
 
find_package_handle_standard_args(DPP DEFAULT_MSG DPP_LIBRARIES DPP_INCLUDE_DIR)