/**
 * @file evenC_evenR.cpp
 * @author Eduard Jaha (jaha.eduard@gmail.com)
 * @brief Functions from class Swapper, that are implemented to be used in main
 * @version 0.1
 * @date 2022-01-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Swapper/swapper.hpp"

void Swapper::evenC_evenR(const cv::Mat &image) {
  cv::Size size_of = image.size();

  cv::Rect rectangleTopLeft(0, 0, size_of.width / 2, size_of.height / 2);
  cv::Rect rectangleTopRight(size_of.width / 2, 0, size_of.width / 2,
                             size_of.height / 2);
  cv::Rect rectangleBottomLeft(0, size_of.height / 2, size_of.width / 2,
                               size_of.height / 2);
  cv::Rect rectangleBottomRight(size_of.width / 2, size_of.height / 2,
                                size_of.width / 2, size_of.height / 2);

  cv::Mat cropped_image1 = image(rectangleTopLeft);
  cv::Mat cropped_image2 = image(rectangleTopRight);
  cv::Mat cropped_image3 = image(rectangleBottomLeft);
  cv::Mat cropped_image4 = image(rectangleBottomRight);

  std::cout << "img1 cols : " << cropped_image1.cols << "\t"
            << "img1rows : " << cropped_image1.rows << std::endl;
  std::cout << "img2 cols : " << cropped_image2.cols << "\t"
            << "img2rows : " << cropped_image2.rows << std::endl;
  std::cout << "img3 cols : " << cropped_image3.cols << "\t"
            << "img3rows : " << cropped_image3.rows << std::endl;
  std::cout << "img4 cols : " << cropped_image4.cols << "\t"
            << "img4rows : " << cropped_image4.rows << std::endl;

  cv::Mat resImg(image.rows, image.cols, image.type(),
                 cv::Scalar(200, 100, 50));

  cropped_image1.copyTo(resImg(rectangleBottomRight));
  cropped_image2.copyTo(resImg(rectangleBottomLeft));
  cropped_image3.copyTo(resImg(rectangleTopRight));
  cropped_image4.copyTo(resImg(rectangleTopLeft));

  cv::namedWindow("Swapping", cv::WINDOW_NORMAL);
  cv::imshow("Swapping", resImg);
  cv::waitKey(0);
}
