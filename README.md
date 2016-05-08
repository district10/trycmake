请移步：[district10/cmake-templates: Some CMake Templates. Qt, Boost, OpenCV, C++11, etc.](https://github.com/district10/cmake-templates)。

---

# Try Some CMake, the cross-platform project builder

I prefer
`cmake_minimum_required( VERSION 2.6 )` than
`CMAKE_MINIMUM_REQUIRED (VERSION 2.6)`, etc.
Just for clarity.



### Notes
* [CMake Notes](notes-cmake.md)
* [Qt Notes](notes-qt.md)
* [CMakeLists.txt Snippets](notes-cmake-snippets.md)
* [Notes on Windows Configuration](notes-windows-configuration.md)

### Script: gen.sh

```shell
#!/bin/bash

BUILD="build"
rm -Rf $BUILD
mkdir $BUILD && cd $BUILD && \
cmake.exe -G"Visual Studio 10 2010 Win64" ../
```



