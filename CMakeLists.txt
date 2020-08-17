cmake_minimum_required(VERSION 3.16)
project(Logger-System)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(logger)
include_directories(logger/include)

option(LoggerCPP_BUILD_EXAMPLE "Build the example of LoggerCPP." OFF)
if (LoggerCPP_BUILD_EXAMPLE)
    # add the example executable, linked with the LoggerCPP library
    add_executable(LoggerCPP_Example examples/main.cpp)
    target_link_libraries(LoggerCPP_Example LoggerCPP ${SYSTEM_LIBRARIES})
endif ()