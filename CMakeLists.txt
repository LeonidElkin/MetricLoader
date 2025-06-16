cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(MetricLoader LANGUAGES CXX)

SET(BUILD_EXAMPLE ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(lib)

if (BUILD_EXAMPLE)
    add_subdirectory(example)
endif ()