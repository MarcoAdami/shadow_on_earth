cmake_minimum_required(VERSION 3.27)
project(shadow_on_earth)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(shadow_on_earth
        matrix_multiplication/matrix.cpp
        "print table/print_table.cpp"
        calculator.cpp
        try.cpp
        useful_functions.cpp
        useful_functions.h)
