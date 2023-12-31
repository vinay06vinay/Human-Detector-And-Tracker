/**
 * @file human_detector.hpp
 * @author Neha Nitin Madhekar, Rashmi Kapu, Vinay Krishna Bukka
 * @brief This file contains the import of YOLO model and detecting humans.
 * @version 0.1
 * @date 2023-10-31
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __HUMAN_DETECTOR_H__
#define __HUMAN_DETECTOR_H__
#pragma once
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <../include/my_macros.hpp>
#include <fstream>
#include <iostream>
#include <opencv2/opencv.hpp>

namespace perception {
/**
 * @class HumanDetector
 * @brief Class for detecting humans in images using YOLO (You Only Look Once)
 * object detection.
 */
class HumanDetector {
  float input_height;
  float input_width;
  cv::dnn::Net net;

public:
  std::vector<std::string> class_list;

public:
  /**
   * @brief Default constructor for the HumanDetector class.
   *
   * This constructor initializes the HumanDetector object with default values.
   */
  HumanDetector();

  /**
   * @brief Load the YOLO neural network model for object detection.
   *
   * @param model_path The path to the YOLO model
   * @return The YOLO neural network model.
   */
  cv::dnn::Net YoloModel(std::string &model_path);

  /**
   * @brief Preprocess the input image for object detection
   * and use model to detect humans
   * @param input Input image to be preprocessed.
   * @param model YOLO model for object detection.
   * @return A vector of preprocessed images.
   */
  std::vector<cv::Mat> preProcess(cv::Mat &input, cv::dnn::Net &model);

  /**
   * @brief Postprocess the output of object detection to obtain bounding boxes and labels.
   *
   * @param input Input image for detection.
   * @param detections Vector of detection results.
   * @param class_ids Vector to store detected class IDs.
   * @param confidences Vector to store detection confidences.
   * @param boxes Vector to store bounding boxes.
   * @param indices Vector to store indices of valid detections.
   * @return Processed image with bounding boxes and labels.
   */
  cv::Mat postProcess(const cv::Mat &input, const std::vector<cv::Mat> &detections,
                      std::vector<int>* class_ids,
                      std::vector<float>* confidences,
                      std::vector<cv::Rect>* boxes, std::vector<int>* indices);
};
} // namespace perception

#endif
