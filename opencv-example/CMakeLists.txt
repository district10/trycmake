PROJECT(opencv_example)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
if(COMMAND cmake_policy)
      cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

FIND_PACKAGE( OpenCV REQUIRED )

# Declare the target (an executable)
ADD_EXECUTABLE(opencv_example  minarea.c)

TARGET_LINK_LIBRARIES(opencv_example ${OpenCV_LIBS})

# MESSAGE(STATUS "OpenCV_LIBS: ${OpenCV_LIBS}")
# OpenCV_DIR: C:/dev/opencv/build/x86/vc10/lib
# OpenCV_LIBS: opencv_videostab;opencv_video;opencv_ts;opencv_superres;opencv_stitching;opencv_photo;opencv_ocl;opencv_objdetect;opencv_nonfree;opencv_ml;opencv_legacy;opencv_imgproc;opencv_highgui;opencv_gpu;opencv_flann;opencv_features2d;opencv_core;opencv_contrib;opencv_calib3d