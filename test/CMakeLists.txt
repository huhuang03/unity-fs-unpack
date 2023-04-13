include(CTest)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/master.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(unity14_test unity14_test.cc)
find_package(Boost REQUIRED COMPONENTS filesystem)
target_link_libraries(unity14_test  GTest::gtest_main unity-fs-unpack-lib Boost::filesystem reader-util)
include(GoogleTest)
gtest_discover_tests(unity14_test)