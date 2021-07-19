cmake_minimum_required(VERSION 3.1.0)
#hunter setup
include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/cpp-pm/hunter/archive/v0.23.297.tar.gz"
    SHA1 "3319fe6a3b08090df7df98dee75134d68e2ef5a3"
)

project(sparroh
  VERSION 0.1
  LANGUAGES C CXX)

add_definitions(-D_GNU_SOURCE)
set(HUNTER_ROOT "${CMAKE_BINARY_DIR}/hunter")
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${PROJECT_SOURCE_DIR}/cmake")
include(HunterFind)

find_package_or_hunter(SDL2)

set(DILIT_FLAGS "-Wall -Wextra -Werror")

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

#this is not correct, you need the compiler option for every platform

if(CMAKE_BUILD_TYPE MATCHES Debug)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb3")
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -fPIC")
endif()
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# include_directories(include)
add_subdirectory(subprojects)
add_subdirectory(src)
