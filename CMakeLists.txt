cmake_minimum_required(VERSION 3.10)
project(Figures)

set(CMAKE_CXX_STANDARD 17)

add_executable(figures_main
    main.cpp
    figure.cpp
    triangle.cpp
    square.cpp
    octagon.cpp
    figure_array.cpp
)

find_package(GTest REQUIRED)

target_link_libraries(figures_tests GTest::gtest GTest::gtest_main)