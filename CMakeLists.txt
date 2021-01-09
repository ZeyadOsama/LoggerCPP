# Set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
cmake_policy(SET CMP0048 NEW)

# Project settings.
project(Logger-System VERSION 1.0.0)

# Set C++ standard to c++11.
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(prerequisites)
include_directories(include)

add_subdirectory(src)

option(LoggerCPP_BUILD_EXAMPLES "Build the example of LoggerCPP." OFF)
if (LoggerCPP_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif ()

option(LoggerCPP_BUILD_TESTS "Build the tests of LoggerCPP." OFF)
if (LoggerCPP_BUILD_TESTS)
    add_subdirectory(tests)
    include(CTest)
    add_test(NAME System-Tests
            COMMAND system-tests
            )
endif ()