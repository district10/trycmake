cmake_minimum_required( VERSION 2.6 )
project( BOOST )

add_executable( ${PROJECT_NAME} main.cpp )

find_package(Boost REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
set(Boost_USE_STATIC_LIBS        OFF)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME     OFF)
set(BOOST_ALL_DYN_LINK           ON)   # force dynamic linking for all libraries

target_link_libraries( ${PROJECT_NAME} ${Boost_LIBRARIES} )