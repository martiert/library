project(Library CXX)

cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/Modules" CACHE STRING "Path to cmake modules")

if(NOT LIBRARY_OUTPUT_PATH)
  set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
endif(NOT LIBRARY_OUTPUT_PATH)

if(NOT EXECUTABLE_OUTPUT_PATH)
  set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
endif(NOT EXECUTABLE_OUTPUT_PATH)

set(CppUTest_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/cpputest/include")
enable_testing()
include(CTest)

find_package(CXX11 REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX11_FLAGS}")

add_subdirectory(cpputest)
add_subdirectory(core)
