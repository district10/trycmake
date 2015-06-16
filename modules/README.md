# CMake Demo

This demo shows how to organize code with CMake.

[calc.c](calc.c) use two modules:

* module [square](square)
* module [cubic](cubic)

好处是两个人可以分别开发 square 和 cubic，只需提供
相应接口给 calc.c 即可：
```c
//--module square
// api:
double square(double x);
// usage:
include "square.h"
square(3.0); // ==> 9.0

//--module cubic
// api:
double cubic(double x);
// usage:
include "cubic.h"
cubic(3.0); // ==> 27.0
```

---

# Coding Style
TODO

# MISC
* encoding: UTF-8 without BOM
