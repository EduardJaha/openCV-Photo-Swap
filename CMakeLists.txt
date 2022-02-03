cmake_minimum_required (VERSION 3.10)
project(example_5_swap)

find_package(OpenCV REQUIRED)

include_directories(
  include/ 
  ${OpenCV_INCLUDE_DIRS}
)

file(GLOB SOURCES "swapper.cpp")

add_library( ${PROJECT_NAME}_lib SHARED ${SOURCES})

target_link_libraries(
  ${PROJECT_NAME}_lib
  ${OpenCV_LIBS}
)