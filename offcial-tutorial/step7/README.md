# How CMake Works & How to Work Properly with CMake 

* [TutorialConfig.h.in](TutorialConfig.h.in)

    // the configured options and settings for Tutorial
    #define Tutorial_VERSION_MAJOR @Tutorial_VERSION_MAJOR@
    #define Tutorial_VERSION_MINOR @Tutorial_VERSION_MINOR@
    #cmakedefine USE_MYMATH
    
    // does the platform provide exp and log functions?
    #cmakedefine HAVE_LOG
    #cmakedefine HAVE_EXP

* build/TutorialConfig.h  <===cmake====  TutorialConfig.h.in
    // the configured options and settings for Tutorial
    #define Tutorial_VERSION_MAJOR 1
    #define Tutorial_VERSION_MINOR 0
    #define USE_MYMATH
    
    // does the platform provide exp and log functions?
    #define HAVE_LOG
    #define HAVE_EXP