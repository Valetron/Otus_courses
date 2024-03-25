cmake_minimum_required(VERSION 3.10)
project(server LANGUAGES CXX)

set(QT_CREATOR_SKIP_CONAN_SETUP ON)

find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ${CCACHE_PROGRAM})
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_SETTINGS_DIR ${CMAKE_SOURCE_DIR}/cmake)

include_directories(${PROJECT_SOURCE_DIR}/headers)

file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

add_executable(${PROJECT_NAME}
               ${HEADERS}
               ${SOURCES}
               main.cpp)
