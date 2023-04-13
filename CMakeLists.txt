cmake_minimum_required(VERSION 3.14.0)

if (WIN32)
    set(CMAKE_TOOLCHAIN_FILE $ENV{vcpkg_root}/scripts/buildsystems/vcpkg.cmake)
endif ()
project(unity-fs-unpack)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE unity-fs-unpack-lib-src src/* ${CMAKE_CURRENT_SOURCE_DIR}/include/*)
list(FILTER unity-fs-unpack-lib-src EXCLUDE REGEX ".*main.cc$")

add_library(unity-fs-unpack-src-lib ${unity-fs-unpack-lib-src})
add_executable(${PROJECT_NAME} ${unity-fs-unpack-lib-src} src/main.cc)

target_include_directories(unity-fs-unpack-src-lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(thirdpart/reader-util/src/)

target_link_libraries(unity-fs-unpack reader-util)

add_subdirectory(test)