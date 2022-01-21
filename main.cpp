/**
 * @file main.cpp
 * @author Eduard Jaha (jaha.eduard@gmail.com)
 * @brief This program will cut the image in equally in 4 rectangulars and swap
 * their places without pixel
 * @version 0.1
 * @date 2022-01-19
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/photo/photo.hpp>

int main(int argc, char **argv) {
  /**
   * @brief Load the image; cv::imread() determines the file format,
   * cv::IMREAD_COLOR uploads the picture with colors
   */
  cv::Mat image = cv::imread("../images/elefant.jpg");
  /**
   * @brief Size will calculate all dimensions of the uploaded image saved as
   * "image"
   */
  cv::Size sz = image.size();

  /**
   * @brief Check to see if an image was in fact read
   */
  if (!image.empty()) {
    /**
     * @brief Use this condition if the image has even coloms and rows of pixels
     */
    if (sz.height % 2 == 0 && sz.width % 2 == 0) {
      /**
       * @brief Create a rectangular space r1,r2,r3,r4 in image .png with the
       * following dimensions:
       */
      cv::Rect r1(0, 0, sz.width / 2, sz.height / 2);
      cv::Rect r2(sz.width / 2, 0, sz.width / 2, sz.height / 2);
      cv::Rect r3(0, sz.height / 2, sz.width / 2, sz.height / 2);
      cv::Rect r4(sz.width / 2, sz.height / 2, sz.width / 2, sz.height / 2);

      /**
       * @brief Crop image based with the dimensions r1, r2, r3, r4 and save it
       * as cropped_image (1, 2, 3, 4)
       */
      cv::Mat cropped_image1 = image(r1);
      cv::Mat cropped_image2 = image(r2);
      cv::Mat cropped_image3 = image(r3);
      cv::Mat cropped_image4 = image(r4);

      /**
       * @brief Print the size of the colums and rows of all the 4 cuted images
       */
      std::cout << "img1 cols : " << cropped_image1.cols << "\t"
                << "img1rows : " << cropped_image1.rows << std::endl;
      std::cout << "img2 cols : " << cropped_image2.cols << "\t"
                << "img2rows : " << cropped_image2.rows << std::endl;
      std::cout << "img3 cols : " << cropped_image3.cols << "\t"
                << "img3rows : " << cropped_image3.rows << std::endl;
      std::cout << "img4 cols : " << cropped_image4.cols << "\t"
                << "img4rows : " << cropped_image4.rows << std::endl;

      /**
       * @brief Create a new empty image
       */
      cv::Mat resImg(image.rows, image.cols, image.type(),
                     cv::Scalar(200, 100, 50));

      /**
       * @brief Copy cropped_image (1, 2, 3, 4) to resImg on the coordinates of
       * r4,r3,r2,r1
       */
      cropped_image1.copyTo(resImg(r4));
      cropped_image2.copyTo(resImg(r3));
      cropped_image3.copyTo(resImg(r2));
      cropped_image4.copyTo(resImg(r1));

      /**
       * @brief Print the swapped images in a new window
       */
      cv::namedWindow("Swapping", cv::WINDOW_NORMAL);
      cv::imshow("Swapping", resImg);
      cv::waitKey(0);

      return 0;
    }

    /**
     * @brief Use this condition if the image has even coloms and odd rows of pixels
     */
    if (sz.height % 2 == 1 && sz.width % 2 == 0) {
      /**
       * @brief Create a rectangular space r1, r2, r3, r4 in image .png with the
       * following dimensions:
       */
      cv::Rect r1(0, 0, sz.width / 2, sz.height / 2);
      cv::Rect r2(sz.width / 2, 0, sz.width / 2, sz.height / 2);
      cv::Rect r3(0, sz.height / 2, sz.width / 2, (sz.height / 2) + 1);
      cv::Rect r4(sz.width / 2, sz.height / 2, sz.width / 2,
                  (sz.height / 2) + 1);

      /**
       * @brief Crop image based with the dimensions r1,r2,r3,r4 and save it as
       * cropped_image (1, 2, 3, 4)
       */
      cv::Mat cropped_image1 = image(r1);
      cv::Mat cropped_image2 = image(r2);
      cv::Mat cropped_image3 = image(r3);
      cv::Mat cropped_image4 = image(r4);

      /**
       * @brief Print the size of the colums and rows of all the 4 cuted images
       */
      std::cout << "img1 cols : " << cropped_image1.cols << "\t"
                << "img1rows : " << cropped_image1.rows << std::endl;
      std::cout << "img2 cols : " << cropped_image2.cols << "\t"
                << "img2rows : " << cropped_image2.rows << std::endl;
      std::cout << "img3 cols : " << cropped_image3.cols << "\t"
                << "img3rows : " << cropped_image3.rows << std::endl;
      std::cout << "img4 cols : " << cropped_image4.cols << "\t"
                << "img4rows : " << cropped_image4.rows << std::endl;

      /**
       * @brief Create a new empty image
       */
      cv::Mat resImg(image.rows, image.cols, image.type(),
                     cv::Scalar(200, 200, 200));

      /**
       * @brief Size will calculate all dimensions of the uploaded image saved
       * as "image"
       */
      cv::Size sz_1 = resImg.size();

      /**
       * @brief Create a rectangular space r1_1, r2_2, r3_3, r4_4 in resImg.png
       * with the following dimensions:
       */
      cv::Rect r1_1(0, 0, sz_1.width / 2, (sz_1.height / 2) + 1);
      cv::Rect r2_2(sz_1.width / 2, 0, sz_1.width / 2, (sz_1.height / 2) + 1);
      cv::Rect r3_3(0, (sz_1.height / 2) + 1, sz_1.width / 2,
                    (sz_1.height / 2));
      cv::Rect r4_4(sz_1.width / 2, (sz_1.height / 2) + 1, sz_1.width / 2,
                    sz_1.height / 2);

      /**
       * @brief Copy cropped_image (1, 2, 3, 4) to resImg on the coordinates of
       * r4_4, r3_3, r2_2, r1_1
       */
      cropped_image1.copyTo(resImg(r4_4));
      cropped_image2.copyTo(resImg(r3_3));
      cropped_image3.copyTo(resImg(r2_2));
      cropped_image4.copyTo(resImg(r1_1));

      /**
       * @brief Print the swapped images in a new window
       */
      cv::namedWindow("Swapping", cv::WINDOW_NORMAL);
      cv::imshow("Swapping", resImg);
      cv::waitKey(0);

      return 0;
    }

    /**
     * @brief Use this condition if the image has odd coloms and even rows of pixels
     */
    if (sz.height % 2 == 0 && sz.width % 2 == 1) {
      /**
       * @brief Create a rectangular space r1, r2, r3, r4 in image .png with the
       * following dimensions:
       */
      cv::Rect r1(0, 0, (sz.width / 2) + 1, sz.height / 2);
      cv::Rect r2(sz.width / 2, 0, (sz.width / 2), sz.height / 2);
      cv::Rect r3(0, sz.height / 2, (sz.width / 2) + 1, sz.height / 2);
      cv::Rect r4(sz.width / 2, sz.height / 2, (sz.width / 2), sz.height / 2);

      /**
       * @brief Crop image based with the dimensions r1,r2,r3,r4 and save it as
       * cropped_image (1, 2, 3, 4)
       */
      cv::Mat cropped_image1 = image(r1);
      cv::Mat cropped_image2 = image(r2);
      cv::Mat cropped_image3 = image(r3);
      cv::Mat cropped_image4 = image(r4);

      /**
       * @brief Print the size of the colums and rows of all the 4 cuted images
       */
      std::cout << "img1 cols : " << cropped_image1.cols << "\t"
                << "img1rows : " << cropped_image1.rows << std::endl;
      std::cout << "img2 cols : " << cropped_image2.cols << "\t"
                << "img2rows : " << cropped_image2.rows << std::endl;
      std::cout << "img3 cols : " << cropped_image3.cols << "\t"
                << "img3rows : " << cropped_image3.rows << std::endl;
      std::cout << "img4 cols : " << cropped_image4.cols << "\t"
                << "img4rows : " << cropped_image4.rows << std::endl;

      /**
       * @brief Create a new empty image
       */
      cv::Mat resImg(image.rows, image.cols, image.type(),
                     cv::Scalar(0, 0, 200));

      /**
       * @brief Size will calculate all dimensions of the uploaded image saved
       * as "image"
       */
      cv::Size sz_1 = resImg.size();

      /**
       * @brief Create a rectangular space r1_1, r2_2, r3_3, r4_4 in resImg.png
       * with the following dimensions:
       */
      cv::Rect r1_1(0, 0, (sz_1.width / 2), sz_1.height / 2);
      cv::Rect r2_2(sz_1.width / 2, 0, (sz_1.width / 2) + 1, sz_1.height / 2);
      cv::Rect r3_3(0, (sz_1.height / 2), (sz_1.width / 2), (sz_1.height / 2));
      cv::Rect r4_4(sz_1.width / 2, sz_1.height / 2, (sz_1.width / 2) + 1,
                    sz_1.height / 2);

      /**
       * @brief Copy cropped_image (1, 2, 3, 4) to resImg on the coordinates of
       * r4_4, r3_3, r2_2, r1_1
       */
      cropped_image1.copyTo(resImg(r4_4));
      cropped_image2.copyTo(resImg(r3_3));
      cropped_image3.copyTo(resImg(r2_2));
      cropped_image4.copyTo(resImg(r1_1));

      /**
       * @brief Print the swapped images in a new window
       */
      cv::namedWindow("Swapping", cv::WINDOW_NORMAL);
      cv::imshow("Swapping", resImg);
      cv::waitKey(0);

      return 0;
    }

    /**
     * @brief Use this condition if the image has odd coloms and rows of pixels
     */
    if (sz.height % 2 == 1 && sz.width % 2 == 1) {
      /**
       * @brief Create a rectangular space r1, r2, r3, r4 in image .png with the
       * following dimensions:
       */
      cv::Rect r1(0, 0, (sz.width / 2) + 1, sz.height / 2);
      cv::Rect r2(sz.width / 2, 0, (sz.width / 2) + 1, sz.height / 2);
      cv::Rect r3(0, sz.height / 2, (sz.width / 2) + 1, (sz.height / 2) + 1);
      cv::Rect r4(sz.width / 2, sz.height / 2, (sz.width / 2) + 1,
                  (sz.height / 2) + 1);

      /**
       * @brief Crop image based with the dimensions r1, r2, r3, r4 and save it
       * as cropped_image (1, 2, 3, 4)
       */
      cv::Mat cropped_image1 = image(r1);
      cv::Mat cropped_image2 = image(r2);
      cv::Mat cropped_image3 = image(r3);
      cv::Mat cropped_image4 = image(r4);

      /**
       * @brief Print the size of the colums and rows of all the 4 cuted images
       */
      std::cout << "img1 cols : " << cropped_image1.cols << "\t"
                << "img1rows : " << cropped_image1.rows << std::endl;
      std::cout << "img2 cols : " << cropped_image2.cols << "\t"
                << "img2rows : " << cropped_image2.rows << std::endl;
      std::cout << "img3 cols : " << cropped_image3.cols << "\t"
                << "img3rows : " << cropped_image3.rows << std::endl;
      std::cout << "img4 cols : " << cropped_image4.cols << "\t"
                << "img4rows : " << cropped_image4.rows << std::endl;

      /**
       * @brief Create a new empty image
       */
      cv::Mat resImg(image.rows, image.cols, image.type(),
                     cv::Scalar(200, 200, 200));

      /**
       * @brief Size will calculate all dimensions of the uploaded image saved
       * as "image"
       */
      cv::Size sz_1 = resImg.size();

      /**
       * @brief Create a rectangular space r1_1, r2_2, r3_3, r4_4 in resImg.png
       * with the following dimensions:
       */
      cv::Rect r1_1(0, 0, (sz_1.width / 2) + 1, (sz_1.height / 2) + 1);
      cv::Rect r2_2(sz_1.width / 2, 0, (sz_1.width / 2) + 1,
                    (sz_1.height / 2) + 1);
      cv::Rect r3_3(0, (sz_1.height / 2) + 1, (sz_1.width / 2) + 1,
                    (sz_1.height / 2));
      cv::Rect r4_4(sz_1.width / 2, (sz_1.height / 2) + 1, (sz_1.width / 2 + 1),
                    sz_1.height / 2);

      /**
       * @brief Copy cropped_image (1, 2, 3, 4) to resImg on the coordinates of
       * r4_4, r3_3, r2_2, r1_1
       */
      cropped_image1.copyTo(resImg(r4_4));
      cropped_image2.copyTo(resImg(r3_3));
      cropped_image3.copyTo(resImg(r2_2));
      cropped_image4.copyTo(resImg(r1_1));

      /**
       * @brief Print the swapped images in a new window
       */
      cv::namedWindow("Swapping", cv::WINDOW_NORMAL);
      cv::imshow("Swapping", resImg);
      cv::waitKey(0);

      return 0;
    }
  }
  /**
   * @brief If picture is not found
   */
  std::cout << "Could not find picture!!!" << std::endl;

  return -1;
}
