#include "ObjectDetection.h"


//****************************Variables*************************************//

//**************************************************************************//


//*****************************Const and Desctructor **********************//
objDetection::objDetection(cv::Mat o_input) : input_img_o{o_input} {}
objDetection::~objDetection() {}
//*************************************************************************//

void objDetection::do_objDetection(){
    cv::dnn::Net net;
    net = cv::dnn::readNetFromDarknet("/home/parsa/workspace/darknet/cfg/yolov3.cfg", "/home/parsa/workspace/darknet/yolov3.weights");
    cv::Mat blob;
    cv::dnn::blobFromImage(input_img_o, blob, 1 / 255.0, cv::Size(416, 416), cv::Scalar(0, 0, 0), true, false);

    net.setInput(blob);
    cv::Mat output = net.forward();

    float confidenceThreshold = 0.5;
    float nmsThreshold = 0.4;

    std::vector<int> classIds;
    std::vector<float> confidences;
    std::vector<cv::Rect> boxes;

    for (int i = 0; i < output.rows; ++i) {
        cv::Mat scores = output.row(i).colRange(5, output.cols);
        cv::Point classIdPoint;
        double confidence;
        cv::minMaxLoc(scores, 0, &confidence, 0, &classIdPoint);

        if (confidence > confidenceThreshold) {
            int centerX = static_cast<int>(output.at<float>(i, 0) * input_img_o.cols);
            int centerY = static_cast<int>(output.at<float>(i, 1) * input_img_o.rows);
            int width = static_cast<int>(output.at<float>(i, 2) * input_img_o.cols);
            int height = static_cast<int>(output.at<float>(i, 3) * input_img_o.rows);

            int left = centerX - width / 2;
            int top = centerY - height / 2;

            classIds.push_back(classIdPoint.x);
            confidences.push_back(static_cast<float>(confidence));
            boxes.push_back(cv::Rect(left, top, width, height));
        }
    }
    std::vector<std::string> classNames = {
    "Class 1",  // Replace with actual class names
    "Class 2"
    // Add more class names as needed
    };
    std::vector<int> indices;
    cv::dnn::NMSBoxes(boxes, confidences, confidenceThreshold, nmsThreshold, indices);

    for (size_t i = 0; i < indices.size(); ++i) {
    int idx = indices[i];
    cv::Rect box = boxes[idx];

    cv::rectangle(input_img_o, box, cv::Scalar(0, 255, 0), 2);

    std::string label = cv::format("%s: %.2f", classNames[classIds[idx]].c_str(), confidences[idx]);
    int baseLine;
    cv::Size labelSize = cv::getTextSize(label, cv::FONT_HERSHEY_SIMPLEX, 0.5, 1, &baseLine);
    cv::putText(input_img_o, label, cv::Point(box.x, box.y - labelSize.height / 2),
                    cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 255, 0), 1);
    }

    cv::imshow("Detected Objects", input_img_o);
    cv::waitKey(0);
    cv::destroyAllWindows();
}