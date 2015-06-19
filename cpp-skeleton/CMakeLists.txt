cmake_minimum_required( VERSION 2.6 )
project( SKELETON )

add_executable( ${PROJECT_NAME} main.cpp )

find_package(Qt4 REQUIRED)
include( ${QT_USE_FILE} )
SET(QT_USE_QTNETWORK TRUE)

find_package(Boost REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
set(Boost_USE_STATIC_LIBS        OFF)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME     OFF)
set(BOOST_ALL_DYN_LINK           ON)   # force dynamic linking for all libraries

target_link_libraries( ${PROJECT_NAME} ${QT_LIBRARIES} )
target_link_libraries( ${PROJECT_NAME} ${Boost_LIBRARIES} )

# include_directories( "${PROJECT_SOURCE_DIR}" "C:/Qt/qt-4.8.6-x64-msvc2010/qt-4.8.6-x64-msvc2010/include/QtNetwork" )
# add_subdirectory( )
# add_library( LibSquare square.c )
# set( EXTRA_LIBS ${EXTRA_LIBS} LibSquare )