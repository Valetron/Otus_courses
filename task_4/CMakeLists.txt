cmake_minimum_required(VERSION 3.10)

set(PROJECT_VESRION 1.0.0)
project(print_ip VERSION ${PROJECT_VESRION})

add_executable(${PROJECT_NAME} main.cpp foo.hpp)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(print_ip PRIVATE
        -g
        -Wall
        -Wextra
#        -Werror
        -pedantic)

elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(print_ip PRIVATE
        /EHsc
        /W4
        /WX)
endif()

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)
