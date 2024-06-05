find_path(Boost_INCLUDE_DIR NAMES boost/uuid/uuid.hpp HINTS ${Boost_ROOT_DIR})

if(CMAKE_SYSTEM_NAME STREQUAL "Darwin") 
    find_library(Boost_LIBRARIES NAMES boost "libboost_random.dylib" HINTS ${Boost_ROOT_DIR})
else() 
    find_library(Boost_LIBRARIES NAMES boost "libboost_random.so" HINTS ${Boost_ROOT_DIR})
endif()

 
include(FindPackageHandleStandardArgs)
 
find_package_handle_standard_args(Boost DEFAULT_MSG Boost_LIBRARIES Boost_INCLUDE_DIR)
