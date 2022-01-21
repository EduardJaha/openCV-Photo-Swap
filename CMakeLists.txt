cmake_minimum_required (VERSION 2.8.11)
project(example_5_swap)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable( ${PROJECT_NAME}_exec
  main.cpp
)

target_link_libraries(${PROJECT_NAME}_exec 
  ${OpenCV_LIBS}
)