cmake_minimum_required( VERSION 2.6 )
project( QT_CONSOLE )

add_executable( ${PROJECT_NAME} main.cpp )

find_package(Qt4)
if(QT4_FOUND)
  include( ${QT_USE_FILE} )
  # find_package(QGLViewer)
  set( QT_DONT_USE_QTGUI TRUE )
  target_link_libraries( ${PROJECT_NAME}  ${QT_LIBRARIES} )
endif(QT4_FOUND)