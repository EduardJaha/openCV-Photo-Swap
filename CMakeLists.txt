cmake_minimum_required (VERSION 3.10)
project(example_5_swap)

find_package(OpenCV REQUIRED)

set(CMAKE_CXX_FLAGS 
  "-O1 \
  -O2 \
  -O3"
)

include_directories(
  include/ 
  ${OpenCV_INCLUDE_DIRS}
)

add_library( ${PROJECT_NAME}_lib
  src/swapper.cpp
)

add_executable( ${PROJECT_NAME}_exec
  main.cpp
)

target_link_libraries( ${PROJECT_NAME}_exec
  ${PROJECT_NAME}_lib
  ${OpenCV_LIBS}
)