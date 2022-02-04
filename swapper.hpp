#ifndef EXAMPLE_5_SWAP_SWAPPER_H
#define EXAMPLE_5_SWAP_SWAPPER_H

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/photo/photo.hpp>

class Swapper {
 private:
  /**
   * @brief Declaration of variables that stores the cropped images
   */
  cv::Mat cropped_image1;
  cv::Mat cropped_image2;
  cv::Mat cropped_image3;
  cv::Mat cropped_image4;

  /**
   * @brief Declration of variables that stores the space of blankImg where the
   * cropped part of the original images will be coppied to
   */
  cv::Rect rectangleTopLeft_blankImg;
  cv::Rect rectangleTopRight_blankImg;
  cv::Rect rectangleBottomLeft_blankImg;
  cv::Rect rectangleBottomRight_blankImg;

 public:
  /**
   * @brief This method is used to display a swaped imaged with even number of
   * coloms and rows
   *
   * @param image to be displayed
   */
  cv::Mat evenC_evenR(const cv::Mat &image);
  /**
   * @brief This method is used to display a swapped image with even number of
   * coloms and odd number of rows
   *
   * @param image to be displayed
   */
  cv::Mat evenC_oddR(const cv::Mat &image);
  /**
   * @brief This method is used to display a swaped imaged with odd number of
   * coloms and even number of rows
   *
   * @param image to be displayed
   */
  cv::Mat oddC_evenR(const cv::Mat &image);
  /**
   * @brief This method is used to display a swaped imaged with odd number of
   * coloms and odd number of rows
   *
   * @param image to be displayed
   */
  cv::Mat oddC_oddR(const cv::Mat &image);
  /**
   * @brief This method is used to crop the original image
   *
   * @param image to be cropped
   * @param rectangleTopLeft, cropped part of image
   * @param rectangleTopRight, cropped part of image
   * @param rectangleBottomLeft, cropped part of image
   * @param rectangleBottomRight, cropped part of image
   */
  void cropped_Img(const cv::Mat &image, const cv::Rect &rectangleTopLeft,
                   const cv::Rect &rectangleTopRight,
                   const cv::Rect &rectangleBottomLeft,
                   const cv::Rect &rectangleBottomRight);
   /*
   * @brief This method is used to crop the blank image
   *
   * @param blankImg
   * @param rectangleBottomRight_blankImg, cropped part of blank image
   * @param rectangleBottomLeft_blankImg, cropped part of blank image
   * @param rectangleTopRight_blankImg, cropped part of blank image
   * @param rectangleTopLeft_blankImg, cropped part of blank image
   */
  void cropped_blankImg(const cv::Mat &blankImg,
                        const cv::Rect &rectangleBottomRight_blankImg,
                        const cv::Rect &rectangleBottomLeft_blankImg,
                        const cv::Rect &rectangleTopRight_blankImg,
                        const cv::Rect &rectangleTopLeft_blankImg);
  /**
   * @brief This method is used to display the swapped image
   *
   * @param blankImg
   */
  void display(const cv::Mat &blankImg);
  /**
   * @brief This method is used to print the sizes of the cropped image cols and
   * rows
   *
   * @param image, original image
   */
  void sizes(const cv::Mat &image);
};

#endif  // EXAMPLE_5_SWAP_SWAPPER_H
