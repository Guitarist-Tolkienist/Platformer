cmake_minimum_required(VERSION 3.10)
project(Platformer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14") # optional

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include_directories(include)
include_directories(include/Headers)
include_directories(Sources)
file(GLOB SOURCE_FILES "Sources/*.cpp" CTimer.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# SFML
include(SFML-2.5.1-Compiled/AddSFML.cmake)

target_link_libraries(${PROJECT_NAME} sfml-audio sfml-graphics sfml-window sfml-system sfml-network)

message(${CMAKE_BUILD_TYPE})
