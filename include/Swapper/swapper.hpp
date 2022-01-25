#ifndef EXAMPLE_5_SWAP_SWAPPER_H
#define EXAMPLE_5_SWAP_SWAPPER_H

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/photo/photo.hpp>

class Swapper {
 public:
  /**
   * @brief This method is used to display a swaped imaged with even number of
   * coloms and rows
   *
   * @param image to be displayed
   */
  void evenC_evenR(const cv::Mat &image);
  /**
   * @brief This method is used to display a swapped image with even number of
   * coloms and odd number of rows
   *
   * @param image to be displayed
   */
  void evenC_oddR(const cv::Mat &image);
  /**
   * @brief This method is used to display a swaped imaged with odd number of
   * coloms and even number of rows
   *
   * @param image to be displayed
   */
  void oddC_evenR(const cv::Mat &image);
  /**
   * @brief This method is used to display a swaped imaged with odd number of
   * coloms and odd number of rows
   *
   * @param image to be displayed
   */
  void oddC_oddR(const cv::Mat &image);
};

#endif  // EXAMPLE_5_SWAP_SWAPPER_H
