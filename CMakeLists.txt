cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 11)

project(cra_pricer CXX)

include(cmake/compilers.cmake)
include(cmake/dependencies.cmake)

include_directories(BEFORE "${PROJECT_SOURCE_DIR}/src/include")

add_subdirectory(src/lib lib)

add_subdirectory(src/bin bin)


