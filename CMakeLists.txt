cmake_minimum_required (VERSION 2.8.11)
project(example_5_swap)

find_package(OpenCV REQUIRED)

include_directories(
  include/ 
  ${OpenCV_INCLUDE_DIRS}
)

add_library( ${PROJECT_NAME}_lib
  src/evenC_evenR.cpp
  src/evenC_oddR.cpp
  src/oddC_evenR.cpp
  src/oddC_oddR.cpp
)

add_executable( ${PROJECT_NAME}_exec
  main.cpp
)

target_link_libraries( ${PROJECT_NAME}_exec
  ${PROJECT_NAME}_lib
  ${OpenCV_LIBS}
)