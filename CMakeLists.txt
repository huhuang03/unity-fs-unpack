cmake_minimum_required(VERSION 3.12.0)

project(unity-fs-unpack)

add_executable(${PROJECT_NAME} src/main.cc)

add_subdirectory(thirdpart/reader-util/src/)

target_link_libraries(unity-fs-unpack reader-util)