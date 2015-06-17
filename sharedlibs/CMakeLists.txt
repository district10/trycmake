cmake_minimum_required (VERSION 3.2)
project (LINKERS)

include_directories ("${PROJECT_SOURCE_DIR}")
add_library (CALCLIBS STATIC square.c)
add_library (CALCLIBS STATIC cubic.c)

add_executable(Calc calc.c)
target_link_libraries (Calc  ${CALCLIBS})