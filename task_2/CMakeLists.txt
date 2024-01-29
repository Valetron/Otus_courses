cmake_minimum_required(VERSION 3.10)

set(PROJECT_VESRION 1.0.0)
project(ip_filter VERSION ${PROJECT_VESRION})

add_executable(${PROJECT_NAME} main.cpp)

set_target_properties(
    ${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

# target_compile_options(${PROJECT_NAME} PRIVATE
    # -Wall -Wextra -pedantic -Werror)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

enable_testing()

add_test(test_version test_version)
