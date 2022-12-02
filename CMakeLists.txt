cmake_minimum_required(VERSION 3.23)
project(satreci C)

set(CMAKE_C_STANDARD 99)

#program excution code
add_executable(satreci studentMS/main.c studentMS/func.c studentMS/func.h)

#testing excution code
#add_executable(satreci studentMS/func.c studentMS/func.h studentMS_tests/unit_test.c)
