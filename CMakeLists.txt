cmake_minimum_required(VERSION 3.12.0)

if (WIN32)
    set(CMAKE_TOOLCHAIN_FILE $ENV{vcpkg_root}/scripts/buildsystems/vcpkg.cmake)
endif ()
project(unity-fs-unpack)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
        src/main.cc
        src/i_unity_file.h src/unity_file.cc src/unity_file.h src/model/serialized_type.cc src/model/serialized_type.h src/model/type_tree_node.cc src/model/type_tree_node.h src/core/i_parseable.h src/object_info.cc src/object_info.h)

add_subdirectory(thirdpart/reader-util/src/)

target_link_libraries(unity-fs-unpack reader-util)