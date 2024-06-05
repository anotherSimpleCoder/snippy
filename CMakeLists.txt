cmake_minimum_required(VERSION 3.8)
project(snippy)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

add_executable(${PROJECT_NAME} 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/audioMaker.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/bot.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/commandHandler.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/discordService.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utils.cc
)

find_package(DPP REQUIRED)
find_package(SNDFILE REQUIRED)
find_package(Boost REQUIRED)
find_package(FMT REQUIRED)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${DPP_INCLUDE_DIR}
    ${SNDFILE_INCLUDE_DIR}
    ${Boost_INCLUDE_DIR}
    ${FMT_INCLUDE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME} 
    ${DPP_LIBRARIES}
    ${SNDFILE_LIBRARIES}
    ${Boost_LIBRARIES}
    ${FMT_LIBRARIES}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)