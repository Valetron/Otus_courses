cmake_minimum_required(VERSION 3.10)

set(PATCH_VERSION "2" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(helloworld VERSION ${PROJECT_VESRION})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(helloworld_cli main.cpp)

set_target_properties(helloworld_cli PROPERTIES
                        CXX_STANDARD 14
                        CXX_STANDARD_REQUIRED ON)
