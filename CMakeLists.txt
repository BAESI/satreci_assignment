cmake_minimum_required(VERSION 3.23)
project(satreci C)

set(CMAKE_C_STANDARD 99)

#add_executable(satreci studentMS/main.c studentMS/func.c studentMS/func.h studentMS_tests/unit_test.c studentMS_tests/unit_test.h)
#add_executable(satreci studentMS/main.c studentMS/func.c studentMS/func.h)
add_executable(satreci studentMS/func.c studentMS/func.h studentMS_tests/unit_test.c)
