/**
 * @file swapper.cpp
 * @author Eduard Jaha (jaha.eduard@gmail.com)
 * @brief Functions from class Swapper, that are implemented to be used in main
 * @version 0.1
 * @date 2022-01-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "swapper.hpp"

#include <iostream>

void Swapper::CroppedImg(const cv::Mat &image, const cv::Rect &rectangleTopLeft,
                         const cv::Rect &rectangleTopRight,
                         const cv::Rect &rectangleBottomLeft,
                         const cv::Rect &rectangleBottomRight) {
  cropped_image1 = image(rectangleTopLeft);
  cropped_image2 = image(rectangleTopRight);
  cropped_image3 = image(rectangleBottomLeft);
  cropped_image4 = image(rectangleBottomRight);
}

void Swapper::SizesColRows(const cv::Mat &image) {
  std::cout << "RectangleTopLeft cols : " << cropped_image1.cols << "\t"
            << "RectangleTopLeft rows : " << cropped_image1.rows << std::endl;
  std::cout << "RectangleTopRight cols : " << cropped_image2.cols << "\t"
            << "RectangleTopRight rows : " << cropped_image2.rows << std::endl;
  std::cout << "RectangleBottomLeft cols : " << cropped_image3.cols << "\t"
            << "RectangleBottomLeft rows : " << cropped_image3.rows
            << std::endl;
  std::cout << "RectangleBottomRight cols : " << cropped_image4.cols << "\t"
            << "RectangleBottomRight rows : " << cropped_image4.rows
            << std::endl;
}

void Swapper::CroppedBlankImg(const cv::Mat &blankImg,
                              const cv::Rect &rectangleBottomRight_blankImg,
                              const cv::Rect &rectangleBottomLeft_blankImg,
                              const cv::Rect &rectangleTopRight_blankImg,
                              const cv::Rect &rectangleTopLeft_blankImg) {
  cropped_image1.copyTo(blankImg(rectangleBottomRight_blankImg));
  cropped_image2.copyTo(blankImg(rectangleBottomLeft_blankImg));
  cropped_image3.copyTo(blankImg(rectangleTopRight_blankImg));
  cropped_image4.copyTo(blankImg(rectangleTopLeft_blankImg));
}

cv::Mat Swapper::EvenCEvenR(const cv::Mat &image) {
  cv::Size size_of_img = image.size();

  cv::Rect rectangleTopLeft(0, 0, size_of_img.width / 2,
                            size_of_img.height / 2);
  cv::Rect rectangleTopRight(size_of_img.width / 2, 0, size_of_img.width / 2,
                             size_of_img.height / 2);
  cv::Rect rectangleBottomLeft(0, size_of_img.height / 2, size_of_img.width / 2,
                               size_of_img.height / 2);
  cv::Rect rectangleBottomRight(size_of_img.width / 2, size_of_img.height / 2,
                                size_of_img.width / 2, size_of_img.height / 2);

  CroppedImg(image, rectangleTopLeft, rectangleTopRight, rectangleBottomLeft,
             rectangleBottomRight);

  SizesColRows(image);

  cv::Mat BlankImg(image.rows, image.cols, image.type(),
                   cv::Scalar(200, 100, 50));

  cropped_image1.copyTo(BlankImg(rectangleBottomRight));
  cropped_image2.copyTo(BlankImg(rectangleBottomLeft));
  cropped_image3.copyTo(BlankImg(rectangleTopRight));
  cropped_image4.copyTo(BlankImg(rectangleTopLeft));

  return BlankImg;
}

cv::Mat Swapper::EvenCOddR(const cv::Mat &image) {
  cv::Size size_of_img = image.size();

  cv::Rect rectangleTopLeft(0, 0, size_of_img.width / 2,
                            size_of_img.height / 2);
  cv::Rect rectangleTopRight(size_of_img.width / 2, 0, size_of_img.width / 2,
                             size_of_img.height / 2);
  cv::Rect rectangleBottomLeft(0, size_of_img.height / 2, size_of_img.width / 2,
                               (size_of_img.height / 2) + 1);
  cv::Rect rectangleBottomRight(size_of_img.width / 2, size_of_img.height / 2,
                                size_of_img.width / 2,
                                (size_of_img.height / 2) + 1);

  CroppedImg(image, rectangleTopLeft, rectangleTopRight, rectangleBottomLeft,
             rectangleBottomRight);

  SizesColRows(image);

  cv::Mat BlankImg(image.rows, image.cols, image.type(), cv::Scalar(0, 0, 200));

  cv::Size size_of_blankImg = BlankImg.size();

  cv::Rect rectangleTopLeft_blankImg(0, 0, size_of_blankImg.width / 2,
                                     (size_of_blankImg.height / 2) + 1);
  cv::Rect rectangleTopRight_blankImg(size_of_blankImg.width / 2, 0,
                                      size_of_blankImg.width / 2,
                                      (size_of_blankImg.height / 2) + 1);
  cv::Rect rectangleBottomLeft_blankImg(0, (size_of_blankImg.height / 2) + 1,
                                        size_of_blankImg.width / 2,
                                        (size_of_blankImg.height / 2));
  cv::Rect rectangleBottomRight_blankImg(
      size_of_blankImg.width / 2, (size_of_blankImg.height / 2) + 1,
      size_of_blankImg.width / 2, size_of_blankImg.height / 2);

  CroppedBlankImg(BlankImg, rectangleBottomRight_blankImg,
                  rectangleBottomLeft_blankImg, rectangleTopRight_blankImg,
                  rectangleTopLeft_blankImg);

  return BlankImg;
}

cv::Mat Swapper::OddCEvenR(const cv::Mat &image) {
  cv::Size size_of_img = image.size();

  cv::Rect rectangleTopLeft(0, 0, (size_of_img.width / 2) + 1,
                            size_of_img.height / 2);
  cv::Rect rectangleTopRight(size_of_img.width / 2, 0, (size_of_img.width / 2),
                             size_of_img.height / 2);
  cv::Rect rectangleBottomLeft(0, size_of_img.height / 2,
                               (size_of_img.width / 2) + 1,
                               size_of_img.height / 2);
  cv::Rect rectangleBottomRight(size_of_img.width / 2, size_of_img.height / 2,
                                (size_of_img.width / 2),
                                size_of_img.height / 2);

  CroppedImg(image, rectangleTopLeft, rectangleTopRight, rectangleBottomLeft,
             rectangleBottomRight);

  SizesColRows(image);

  cv::Mat BlankImg(image.rows, image.cols, image.type(), cv::Scalar(0, 0, 200));

  cv::Size size_of_blankImg = BlankImg.size();

  cv::Rect rectangleTopLeft_blankImg(0, 0, (size_of_blankImg.width / 2),
                                     size_of_blankImg.height / 2);
  cv::Rect rectangleTopRight_blankImg(size_of_blankImg.width / 2, 0,
                                      (size_of_blankImg.width / 2) + 1,
                                      size_of_blankImg.height / 2);
  cv::Rect rectangleBottomLeft_blankImg(0, (size_of_blankImg.height / 2),
                                        (size_of_blankImg.width / 2),
                                        (size_of_blankImg.height / 2));
  cv::Rect rectangleBottomRight_blankImg(
      size_of_blankImg.width / 2, size_of_blankImg.height / 2,
      (size_of_blankImg.width / 2) + 1, size_of_blankImg.height / 2);

  CroppedBlankImg(BlankImg, rectangleBottomRight_blankImg,
                  rectangleBottomLeft_blankImg, rectangleTopRight_blankImg,
                  rectangleTopLeft_blankImg);

  return BlankImg;
}

cv::Mat Swapper::OddCOddR(const cv::Mat &image) {
  cv::Size size_of_img = image.size();

  cv::Rect rectangleTopLeft(0, 0, (size_of_img.width / 2) + 1,
                            size_of_img.height / 2);
  cv::Rect rectangleTopRight(size_of_img.width / 2, 0,
                             (size_of_img.width / 2) + 1,
                             size_of_img.height / 2);
  cv::Rect rectangleBottomLeft(0, size_of_img.height / 2,
                               (size_of_img.width / 2) + 1,
                               (size_of_img.height / 2) + 1);
  cv::Rect rectangleBottomRight(size_of_img.width / 2, size_of_img.height / 2,
                                (size_of_img.width / 2) + 1,
                                (size_of_img.height / 2) + 1);

  CroppedImg(image, rectangleTopLeft, rectangleTopRight, rectangleBottomLeft,
             rectangleBottomRight);

  SizesColRows(image);

  cv::Mat BlankImg(image.rows, image.cols, image.type(), cv::Scalar(0, 0, 200));

  cv::Size size_of_blankImg = BlankImg.size();

  cv::Rect rectangleTopLeft_blankImg(0, 0, (size_of_blankImg.width / 2) + 1,
                                     (size_of_blankImg.height / 2) + 1);
  cv::Rect rectangleTopRight_blankImg(size_of_blankImg.width / 2, 0,
                                      (size_of_blankImg.width / 2) + 1,
                                      (size_of_blankImg.height / 2) + 1);
  cv::Rect rectangleBottomLeft_blankImg(0, (size_of_blankImg.height / 2) + 1,
                                        (size_of_blankImg.width / 2) + 1,
                                        (size_of_blankImg.height / 2));
  cv::Rect rectangleBottomRight_blankImg(
      size_of_blankImg.width / 2, (size_of_blankImg.height / 2) + 1,
      (size_of_blankImg.width / 2) + 1, size_of_blankImg.height / 2);

  CroppedBlankImg(BlankImg, rectangleBottomRight_blankImg,
                  rectangleBottomLeft_blankImg, rectangleTopRight_blankImg,
                  rectangleTopLeft_blankImg);

  return BlankImg;
}
