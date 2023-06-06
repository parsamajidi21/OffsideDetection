#include "edgeDetection.h"

/*************************************************************************************/
int lowerThreshold = 1;
int maxThreshold = 500;
cv::Mat EdgeImage, gaussianImage, grayImage, cdst, dst;
std::vector<cv::Vec4i> lines;
int kernel=1;
int max_value = 11; 
double th1, th2;
/*************************************************************************************/


/***************************************Constructor and Destroctore**********************************************/
    edgeDetector::edgeDetector(cv::Mat c_input) : input_img{c_input} {}
    edgeDetector::~edgeDetector() {}
/****************************************************************************************************************/
/*******************************************Call back Functions for Trackbars*************************************/
    void 
    edgeDetector::callBackTrackBarCanny(int, void*){
        cv::Mat hsvImage = cdst.clone();
        cv::cvtColor(hsvImage, hsvImage, cv::COLOR_BGR2HSV);
        //Green Range
        cv::Scalar lowerBound(36,25,25);
        cv::Scalar upperBound(70,255,255);
        //white Range
        //cv::Scalar lowerBound_W(0, 0, 200);
        //cv::Scalar upperBound_W(180, 30, 255);
        //Green Range
        //cv::Scalar lowerBound(36,25,25);
        //cv::Scalar upperBound(70,255,255);

        cv::Mat maskGreen;
        //cv::Mat maskWhite;
        cv::inRange(hsvImage, lowerBound, upperBound, maskGreen);
        //cv::inRange(hsvImage, lowerBound_W, upperBound_W, maskWhite);
        dst = cdst.clone();
        cv::Mat maskedImage_green;
        //cv::Mat maskedImage_white;
        dst.copyTo(maskedImage_green, maskGreen);
        //dst.copyTo(maskedImage_white, maskWhite);
        //cv::Mat maskedImage;
        //cv::bitwise_or(maskedImage_green, maskedImage_white, maskedImage);
        //cv::imshow("masked imagegreen", maskedImage_green);
       // cv::imshow("masked imagewhite", maskedImage_white);
        cv::imshow("masked image", maskedImage_green);
        th1 = lowerThreshold;
        th2 = th1 * 0.4;    
        cv::Canny(maskedImage_green, EdgeImage, th1, th2);  
          // apply hough line transform
        cv::HoughLinesP(EdgeImage, lines, 2, CV_PI/180, 50, 10, 100);
        std::vector<cv::Point> vertices;
        // Draw the lines
        for( size_t i = 0; i < lines.size(); i++ ){
        cv::Vec4i l = lines[i];
        vertices.push_back(cv::Point(l[0], l[1]));
        vertices.push_back(cv::Point(l[2], l[3]));
        line( dst, cv::Point(l[0], l[1]), cv::Point(l[2], l[3]), cv::Scalar(128,0,128), 2, cv::LINE_AA);
        }
        //cv::fillPoly(dst, std::vector<std::vector<cv::Point>>{vertices}, cv::Scalar(0, 0, 255));
        cv::imshow("edgeImages", EdgeImage);
        cv::imshow("Detected Lines (in red) - Standard Hough Line Transform", dst);
    }
/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
    void 
    edgeDetector::callBackTrackBarFilter(int kernel, void*){
        if (kernel % 2 == 0) {  // check if the value is even
			kernel++;  // make it odd
			if (kernel > max_value) {
				kernel = max_value;  // make sure it doesn't exceed the maximum
			}
			cv::setTrackbarPos("MyTrackbar", "MyWindow", kernel);  // update the trackbar
		}
        cv::GaussianBlur(grayImage, gaussianImage, cv::Size(kernel,kernel), 3);
    }
/************************************************************************************************************************/
/*************************************************************************************************************************/
    void 
    edgeDetector::do_edgeDetection() {
        result_img = input_img.clone();
        cdst = input_img.clone();
        /************************BGR Converted to Gray*****************/
        cv::cvtColor(input_img, grayImage, cv::COLOR_BGR2GRAY);
        /*************************Passing the Filter*******************/
        cv::namedWindow("edgeImages", cv::WINDOW_AUTOSIZE);
        cv::createTrackbar("Kernel Size:","edgeImages", &kernel, max_value, callBackTrackBarFilter);
        callBackTrackBarFilter(0,0);
        /****************implementation of Canny edge Detection**********/
        cv::namedWindow("edgeImages", cv::WINDOW_AUTOSIZE);
        cv::createTrackbar("Min Threshold:","edgeImages", &lowerThreshold, maxThreshold, callBackTrackBarCanny);
        callBackTrackBarCanny(0,0);
        /****************************************************/

    }
/************************************************************************************************************************************/