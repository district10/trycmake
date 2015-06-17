


---
### Configuration: CMakeLists.txt *v.s.* Command line
in CMakeLists.txt
```
set (CMAKE_BUILD_TYPE Release)
```
in command line
```shell
cmake -DCMAKE_BUILD_TYPE=Debug .
```

---
### If, Foreach, While
```cmake
# IF-ELSE-ENDIF
if (exp)
...
else (exp)
...
endif (exp)

# FOREACH
foreach (list)
...
endforeach (list)

# WHILE
while (cond)
...
endwhile (cond)
```


---
### Headers & Libs
* headers ==> **`include_directories`** --> PATH & LD_LIBRARY_PATH
* libraries ==> **`find_library`**(good) or **`link_directories`**(bad)

0. include: `*.h` ==> `-I` in gcc
0. link dir: `{*.so/*.dll/*.lib/*.dylib/...}` ==> `-L` in gcc
0. link file: `*.so/*.dll/*.lib/*.dylib/...` ==> `-l` in gcc

Use `FindXXXX.cmake` & set `${CMAKE_MODULE_PATH}` to
```cmake
find_package( Qt4 REQUIRED ) # think of it as an #include
```
Or create your own finders
```cmake
get_filename_component( ... )

# lib files
find_library( ... ) # CMAKE_LIBRARY_PATH

# header files
find_file( ... )    # CMAKE_INCLUDE_PATH

# MISC
find_program( ... )
try_compile( ... )
try_run( ... )
```

PkgConfig

`UsePkgConfig.cmake`
`FindPkgConfig.cmake`

---
### Qt with CMake

```cmake
project( pfrac )
find_package( qt4 REQUIRED )
include( ${QT_USE_FILE} )
SET( pfrac_SRCS main.cpp client.h client.cpp )
SET( pfrac_MOC_HEADERS client.h )
QT4_ADD_RESOURCES( pfrac_SRCS
     ${PROJECT_SOURCE_DIR}/pfrac.qrc )
QT4_WRAP_CPP( pfrac_MOC_SRCS
     ${pfrac_MOC_HEADERS} )
ADD_EXECUTABLE( pfrac ${pfrac_SRCS} $
{pfrac_MOC_SRCS}
TARGET_LINK_LIBRARIES( pfrac ${QT_LIBRARIES} )
```

### Congfigure file
`CMakeLists.txt`:
```cmake
set( VALUE 23 )
configure_file( conf.h.in conf.h )
check_include_file( unistd.h HAVE_UNISTD )
```

`conf.h.in`:
```
#cmakedefine VAL
#define KEY @VALUE@
```

`conf.h`:
```
#define VAL
#define KEY 23
```

`*.h`:
```
#ifdef VAL
    int keys[KEY];
#endif

#include "conf.h"
#ifdef HAVE_UNISTD
    // ...
#else
    // ...
#endif
```

---
### MISC

```cmake
# MESSAGE
message( [SEND_ERROR | STATUS | FATAL_ERROR] "message to display" ... )

# LINK
target_link_libraries( wakeup RELEASE ${SRC} )
target_link_libraries( wakeupd DEBUG ${SRC} )

# INSTALL
install( TARGETS ... RUNTIME DESTINATION bin LIBRARY DESTINATION lib )

# MACRO (text substitution)
macro (INSERT_INTO_MAP _KEY _VALUE)
  set ("MyMap_${_KEY}" "${_VALUE}")
endmacro (INSERT_INTO_MAP)

set (MyKey "foo")
set (MyValue "bar")
INSERT_INTO_MAP("${MyKey}" "${MyValue}")

# FUNCTION
...

# EXECUTE_PROCESS
execute_process( )

# TARGET
add_custom_targets

# CACHE
set (num 23 CACHE) # use cached 'num' if possible, and save to it
set (num 23 CACHE FORCE) # force overwrite Cache.

# POLICY (for Back/Forward?compatibility)
...

# Properties
cmake_minimum_required( ... )
option( ... )
get_cmake_property( ... )
get_target_property( ... )
set_target_property( ... )
set_source_files_properties( ... )

# Useful Varibles
CMAKE_BINARY_DIR     CMAKE_CURRENT_BINARY_DIR   
CMAKE_SOURCE_DIR     CMAKE_CURRENT_SOURCE_DIR

PROJECT_BINARY_DIR   EXECUTABLE_OUTPUT_PATH
PROJECT_SOURCE_DIR   LIBRARY_OUTPUT_PATH

$ENV{name}
```

---
### MISC
0. `*.ilk` => incremental linker file
0. `LD_LIBRARY_PATH` ==> Link Dynamically Lib Path

---
### CPack (for installer packaging)

---
### CTest & CDash (for code testing & testing result displaying)