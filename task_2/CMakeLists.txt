cmake_minimum_required(VERSION 3.10)

set(PROJECT_VESRION 0.0.1)
project(ip_filter VERSION ${PROJECT_VESRION})

add_executable(${PROJECT_NAME} main.cpp)

set_target_properties(
    ${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON)

if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE
        /W4)
else ()
    target_compile_options(${PROJECT_NAME} PRIVATE
        -Wall -Wextra -pedantic -Werror)
endif()

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

set(IP_LIST_TSV "ip_filter.tsv")
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/${IP_LIST_TSV}" "${CMAKE_CURRENT_BINARY_DIR}/${TEXT_FILE_NAME}")

# package
set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
