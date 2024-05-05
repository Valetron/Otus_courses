cmake_minimum_required(VERSION 3.10)

set(PATCH_VERSION "2" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(tge VERSION ${PROJECT_VESRION} DESCRIPTION "Terminal graphic editor" LANGUAGES CXX)

set(MVC_FOLDER "${CMAKE_CURRENT_SOURCE_DIR}/MVC/")
set(FIGURES_FOLDER "${CMAKE_CURRENT_SOURCE_DIR}/figures/")

include_directories("${MVC_FOLDER}/headers")
include_directories("${FIGURES_FOLDER}/headers")

file(GLOB SOURCES "${MVC_FOLDER}/src/*.cpp")
file(GLOB HEADERS "${MVC_FOLDER}/headers/*.hpp")
file(GLOB SOURCES_f "${FIGURES_FOLDER}/src/*.cpp")
file(GLOB HEADERS_f "${FIGURES_FOLDER}/headers/*.hpp")
list(APPEND SOURCES ${SOURCES_f})
list(APPEND HEADERS ${HEADERS_f})

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} main.cpp)

set_target_properties(
    ${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON)

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic #[[-Werror]])
endif()

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)
