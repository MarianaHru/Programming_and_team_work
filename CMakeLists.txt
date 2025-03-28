cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_TOOLCHAIN_FILE /Users/tarasgrudzinskij/Documents/vcpkg/scripts/buildsystems/vcpkg.cmake)

set(GTest_DIR /Users/tarasgrudzinskij/Documents/vcpkg/installed/x64-osx/share/gtest)
find_package(GTest CONFIG REQUIRED)

# Додаємо тести для lab3_2
add_executable(lab3_2_unit_test lab3_2/lab3_2_unit_test.cpp lab3_2/lab3_2.cpp)

target_compile_definitions(lab3_2_unit_test PRIVATE UNIT_TESTING)
target_link_libraries(lab3_2_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)