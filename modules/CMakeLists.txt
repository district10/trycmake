# cmake & project
cmake_minimum_required (VERSION 3.2)
project (CALC)

# module square
include_directories ("${PROJECT_SOURCE_DIR}/square")
add_subdirectory (square)
set (EXTRA_LIBS ${EXTRA_LIBS} LibSquare)

# module cubic
include_directories ("${PROJECT_SOURCE_DIR}/cubic")
add_subdirectory (cubic)
set (EXTRA_LIBS ${EXTRA_LIBS} LibCubic)

# how to compile & link executable?
add_executable(Calc calc.c)
target_link_libraries (Calc  ${EXTRA_LIBS})

# add the install targets
install (TARGETS Calc DESTINATION bin)
