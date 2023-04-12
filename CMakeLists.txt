cmake_minimum_required(VERSION 3.12.0)

project(unity-fs-unpack)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} src/main.cc)

add_subdirectory(thirdpart/reader-util/src/)

target_link_libraries(unity-fs-unpack reader-util)