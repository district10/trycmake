cmake_minimum_required (VERSION 3.2)
project (CALC)

# square
include_directories ("${PROJECT_SOURCE_DIR}/square")
add_subdirectory (square)
set (EXTRA_LIBS ${EXTRA_LIBS} LibSquare)

# cubic
include_directories ("${PROJECT_SOURCE_DIR}/cubic")
add_subdirectory (cubic)
set (EXTRA_LIBS ${EXTRA_LIBS} LibCubic)

add_executable(Calc calc.c)
target_link_libraries (Calc  ${EXTRA_LIBS})

# add the install targets
install (TARGETS Calc DESTINATION bin)
