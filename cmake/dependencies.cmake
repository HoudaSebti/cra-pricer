set(LIBS "")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules")

# Find Quantlib
find_package(QuantLib REQUIRED)
include_directories(SYSTEM ${QUANTLIB_INCLUDE_DIR})
list(APPEND LIBS ${QUANTLIB_LIBRARY})

# Find Boost
set(Boost_USE_STATIC_LIBS        OFF)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME     OFF)

find_package(Boost REQUIRED filesystem system)
include_directories(SYSTEM ${Boost_INCLUDE_DIRS})
list(APPEND LIBS ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY})

#Find Catch2
include(${CMAKE_SOURCE_DIR}/cmake/modules/FindCatch2.cmake)
enable_testing(true)
