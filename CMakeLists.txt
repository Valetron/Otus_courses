cmake_minimum_required(VERSION 3.10)

set(PATCH_VERSION "2" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(helloworld VERSION ${PROJECT_VESRION})

configure_file(version.h.in version.h)

#find_package(Boost COMPONENTS unit_test_framework REQUIRED)
find_package(GTest REQUIRED)

add_executable(helloworld_cli main.cpp)
add_library(helloworld lib.cpp)
add_executable(test_version google_test.cpp)

set_target_properties(
    helloworld_cli PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON)

target_include_directories(helloworld
    PRIVATE ${CMAKE_BINARY_DIR})

target_link_libraries(helloworld_cli
	PUBLIC
	${GTEST_LIBRARIES}
	PRIVATE
    helloworld)

target_include_directories(test_version PUBLIC ${GTEST_INCLUDE_DIRS})

target_link_libraries(test_version
	${GTEST_MAIN_LIBRARIES}
	helloworld)

target_compile_options(helloworld_cli PRIVATE
    -Wall -Wextra -pedantic -Werror)

target_compile_options(helloworld PRIVATE
    -Wall -Wextra -pedantic -Werror)

target_compile_options(test_version PRIVATE
    -Wall -Wextra -pedantic -Werror)

install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

enable_testing()

add_test(test_version test_version)
