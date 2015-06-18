### CMakeLists.txt Snippets


```cmake
SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES VS_KEYWORD Qt4VSv1.0)
```


```cmake
set( CMAKE_COLOR_MAKEFILE ON )
set_property( GLOBAL PROPERTY USE_FOLDERS ON )

# Set the include directories
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR})
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/src)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

LINK_DIRECTORIES(${CMAKE_BINARY_DIR})

# Setup output directories
SET(LIBRARY_OUTPUT_PATH 
	${PROJECT_BINARY_DIR}/bin
	CACHE
	PATH
	"Single directory for all libraries")
	
SET(EXECUTABLE_OUTPUT_PATH 
	${PROJECT_BINARY_DIR}/bin
	CACHE
	PATH
	"Single directory for all executables")

#ADD_DEFINITIONS(-DUNICODE)
ADD_DEFINITIONS(-D_CRT_SECURE_NO_WARNINGS)
# enable warnings
#ADD_DEFINITIONS( -Wall )
```

cross platform

```cmake
#large address aware option setting
IF(${MINGW})
	SET(LARGEADDRESSAWARE "--large-address-aware")
ELSE(${MINGW})
	IF (WIN32)
		SET(LARGEADDRESSAWARE "/LARGEADDRESSAWARE")
	ELSE (WIN32)
		SET(LARGEADDRESSAWARE " ")
	ENDIF (WIN32)
ENDIF (${MINGW})
```


```cmake
# libs

# this command finds Qt4 libraries and sets all required variables
# note that it's Qt4, not QT4 or qt4
FIND_PACKAGE( Qt4 REQUIRED)

SET(QT_USE_QTMAIN TRUE)
SET(QT_USE_QTOPENGL TRUE)
SET(QT_USE_QTXML TRUE)

# (QT_USE_FILE is a variable defined by FIND_PACKAGE( Qt4 ) that contains a path to CMake script)
INCLUDE( ${QT_USE_FILE} )

SET(RSCS img.qrc)

QT4_WRAP_CPP(MOC_SRCS ${HDRS_FILES})
QT4_ADD_RESOURCES(RSC_SRCS ${RSCS})
QT4_WRAP_UI(UI_HDRS ${UI_FILES})

SET(FILES_TO_TRANSLATE ${FILES_TO_TRANSLATE} ${SRCS_FILES} ${UI_FILES} ${HDRS_FILES} PARENT_SCOPE)

SOURCE_GROUP("UI Files" FILES ${UI_FILES})
SOURCE_GROUP("Generated Files" FILES ${MOC_SRCS} ${UI_HDRS} ${RSC_SRCS})
SOURCE_GROUP("Class Diagrams" FILES ${CD_FILES} )
SOURCE_GROUP("Resources" FILES ${RSCS} )

ADD_EXECUTABLE(${PROJECT_NAME} ${SRCS_FILES} ${UI_FILES} ${HDRS_FILES} ${MOC_SRCS} ${UI_HDRS} ${RSC_SRCS} ${CD_FILES})
set_source_files_properties(${CD_FILES} PROPERTIES HEADER_FILE_ONLY TRUE) #DO NOT COMPILE CS FILES
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${QT_LIBRARIES} ${OPENGL_LIBRARY} ${GLUT_LIBRARIES} ${OpenCV_LIBS})
SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES LINK_FLAGS ${LARGEADDRESSAWARE})
SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES VS_KEYWORD Qt4VSv1.0)

INSTALL(TARGETS ${PROJECT_NAME} DESTINATION bin)

# this command finds OpenCV libraries and sets all required variables
FIND_PACKAGE(OpenCV REQUIRED)
INCLUDE_DIRECTORIES(${OPENCV_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR})



FIND_PACKAGE(OpenGL REQUIRED)
FILE(GLOB_RECURSE HDRS_FILES *.h *.hpp)
FILE(GLOB_RECURSE SRCS_FILES *.cpp)
FILE(GLOB_RECURSE UI_FILES *.ui)
FILE(GLOB CD_FILES *.cd)

```

recursive
```cmake
ADD_SUBDIRECTORY(src)
```

Qt more.
```
SET(QT_USE_QTMAIN TRUE)                                               # GUI support
ADD_EXECUTABLE(example WIN32 main.cpp mainwindow.cpp ${example_MOCS}) # WIN32 needed
```

### CGAL

```cmake

```