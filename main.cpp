/**
 * @file main.cpp
 * @author Eduard Jaha (jaha.eduard@gmail.com)
 * @brief This program will cut the image in equally in 4 rectangulars and swap
 * their places without loosing a line or row of pixels
 * @version 0.1
 * @date 2022-01-19
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>

#include "Swapper/swapper.hpp"

int main(int argc, char **argv) {
  Swapper swap;

  if (argc != 2) {
    std::cout << "Please write write two aguments to run the program"
              << std::endl;
    return -1;
  }

  cv::Mat img = cv::imread(argv[1], cv::IMREAD_UNCHANGED);

  if (!img.empty()) {
    cv::Size size_of_img = img.size();

    int Col_Remainder = size_of_img.width % 2;
    int Row_Remainder = size_of_img.height % 2;

    if (Row_Remainder == 0 && Col_Remainder == 0) {
      swap.evenC_evenR(img);
      return 0;
    }

    if (Row_Remainder != 0 && Col_Remainder == 0) {
      swap.evenC_oddR(img);
      return 0;
    }

    if (Row_Remainder == 0 && Col_Remainder != 0) {
      swap.oddC_evenR(img);
      return 0;
    }

    if (Row_Remainder != 0 && Col_Remainder != 0) {
      swap.oddC_oddR(img);
      return 0;
    }
  }
  std::cout << "Could not find picture, path must be incorrect!!!" << std::endl;

  return -1;
}
