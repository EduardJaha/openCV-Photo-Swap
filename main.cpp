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
    cv::Size sz = img.size();

    if (sz.height % 2 == 0 && sz.width % 2 == 0) {
      swap.evenC_evenR(img);
      return 0;
    }

    if (sz.height % 2 == 1 && sz.width % 2 == 0) {
      swap.evenC_oddR(img);
      return 0;
    }

    if (sz.height % 2 == 0 && sz.width % 2 == 1) {
      swap.oddC_evenR(img);
      return 0;
    }

    if (sz.height % 2 == 1 && sz.width % 2 == 1) {
      swap.oddC_oddR(img);
      return 0;
    }
  }
  std::cout << "Could not find picture, path must be incorrect!!!" << std::endl;

  return -1;
}
