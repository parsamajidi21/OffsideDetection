#include "ObjectDetection.h"
#include "edgeDetection.h"
#include "Histogram.h"
//****************************Variables*************************************//
//**************************************************************************//


//*****************************Const and Desctructor **********************//
objDetection::objDetection(cv::Mat o_input) : input_img_o{o_input} {}
objDetection::~objDetection() {}
//*************************************************************************//


void objDetection::do_objDetection() {
    cv::dnn::Net net;
    net = cv::dnn::readNetFromDarknet("../darknet/cfg/yolov3.cfg", "../darknet/yolov3.weights");
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
        "Yello Team",
        "Red Team",
        "Ball",
        "Goalkeeper",
        "Referee"
    };
    std::vector<int> indices;
    cv::dnn::NMSBoxes(boxes, confidences, confidenceThreshold, nmsThreshold, indices);

    cv::Mat hsv;
    cv::cvtColor(input_img_o, hsv, cv::COLOR_BGR2HSV);
    //**********************************Threasholding the Colors***********************************************************//
    cv::Scalar lower_yello(20, 100, 100);
    cv::Scalar upper_yello(30, 255, 255);
    cv::Scalar lower_red1(0, 50, 50);
    cv::Scalar upper_red1(10, 255, 255);
    cv::Scalar lower_red2(160, 50, 50);
    cv::Scalar upper_red2(179, 255, 255);
    cv::Scalar lower_white(0, 0, 200);
    cv::Scalar upper_white(255, 30, 255);
    //**********************************************************************************************************************//

    std::vector<cv::Point> playerPositions;

    for (size_t i = 0; i < indices.size(); ++i) {
        int idx = indices[i];
        cv::Rect box = boxes[idx];
        std::cout << (box.x + (box.x + box.width))/2 << ", " << (box.y + (box.y + box.height))/2 << std::endl; 
        cv::circle(input_img_o, cv::Point((box.x + (box.x + box.width))/2, (box.y + (box.y + box.height))/2), 8, cv::Scalar(255,255,255), -1);  
        cv::Point line1Start(171, 295);  
        cv::Point line1End(708, 523);  

        cv::Point line2Start(632, 492);  
        cv::Point line2End(899, 605);    

        double line1Slope = static_cast<double>(line1End.y - line1Start.y) / (line1End.x - line1Start.x);

        double line2Slope = static_cast<double>(line2End.y - line2Start.y) / (line2End.x - line2Start.x);

        double averageSlope = (line1Slope + line2Slope) / 2.0;

        cv::Point givenPoint((box.x + (box.x + box.width))/2, (box.y + (box.y + box.height))/2);  

        double parallelIntercept = givenPoint.y - averageSlope * givenPoint.x;

        int parallelStartX = 0;
        int parallelEndX = input_img_o.cols;

        int parallelStartY = averageSlope * parallelStartX + parallelIntercept;
        int parallelEndY = averageSlope * parallelEndX + parallelIntercept;

        cv::line(input_img_o, line1Start, line1End, cv::Scalar(0, 0, 255), 2);

        cv::line(input_img_o, line2Start, line2End, cv::Scalar(0, 0, 255), 2);

        cv::line(input_img_o, cv::Point(parallelStartX, parallelStartY), cv::Point(parallelEndX, parallelEndY), cv::Scalar(0, 255, 0), 2);


        cv::rectangle(input_img_o, box, cv::Scalar(0, 255, 0), 3);

        cv::Mat roi = hsv(box);
        cv::Mat blueMask, redMask, whiteMask, yellowMask;
        cv::inRange(roi, lower_yello, upper_yello, yellowMask);
        cv::inRange(roi, lower_red1, upper_red1, redMask);
        cv::inRange(roi, lower_red2, upper_red2, redMask);
        cv::inRange(roi, lower_white, upper_white, whiteMask);

        double yellowPixels = cv::countNonZero(yellowMask);
        double redPixels = cv::countNonZero(redMask);
        double whitePixels = cv::countNonZero(whiteMask);

        std::string label;
        if (whitePixels > yellowPixels && whitePixels > redPixels) {
            label = classNames[3];  // Goalkeeper
        } else if (yellowPixels > redPixels) {
            label = classNames[0];  // Team 1
        } else {
            label = classNames[1];  // Team 2
        }

        cv::Size labelSize = cv::getTextSize(label, cv::FONT_HERSHEY_SIMPLEX, 0.5, 1, nullptr);
        cv::putText(input_img_o, label, cv::Point(box.x, box.y - labelSize.height / 2),
                    cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 255, 0), 1);
    }
    edgeDetector edge{input_img_o};
    edge.do_edgeDetection();
    cv::imshow("Detected Objects", input_img_o);
}
