# Photo swap example using OpenCV

## What is OpenCV

OpenCV is an open source library and machine learing software, that is used for computer vision.

The aim of this project is to implement OpenCV in an example, where we will read an image and try to display it in diffrent parts without loosing a pixel.

The aim of this project is to implement OpenCV in an example, where we will read an image and try to display it in diffrent parts without loosing a pixel.


---


The project will be in created in the head file called Example_5_swap. In the following you can see the dependencies of the files.


### Example_5_swap
* images/

* include/
  * Swapper/
    * swapper.hpp

* src/
  * evenC_evenR.cpp
  * evenC_oddR.cpp
  * oddC_evenR.cpp
  * oddC_oddR.cpp
  
* CMakeLists.txt
* Doxyfile
* main.cpp

---

### Libraries which need to be installed in terminal:

* CMake
```bash
$ sudo apt install cmake
```
* OpenCV
```bash
$ cd ~/path/to/working/directory
$ git clone https://github.com/opencv/opencv.git
$ cd OpenCV
$ mkdir build
$ cd build
$ cmake ..
$ make
$ sudo make install
```

---

## Method to run the project
For the project to be runned and build, you need to open the terminal and do the following:

```bash
/Example_5_swap$ mkdir build
/Example_5_swap$ cd build
$ cmake ..
$ cmake --build .
$ ./Example_5_swap_exec <path of the image file>
```
