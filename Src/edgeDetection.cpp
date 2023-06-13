#include "edgeDetection.h"
#include "ObjectDetection.h"
#include "Histogram.h"
/*************************************************************************************/
int lowerThreshold = 1;
int maxThreshold = 500;
cv::Mat EdgeImage, gaussianImage, grayImage, cdst, dst;
std::vector<cv::Vec4i> lines;
int kernel=1;
int max_value = 11; 
double th1, th2;
int min_len = 20;
int max_len = 100;
cv::Mat maskedImage_green;
cv::Mat maskedImage_red;
cv::Mat maskedImage_blue;
cv::Mat dst2,dst3;
/*************************************************************************************/


/***************************************Constructor and Destroctore**********************************************/
edgeDetector::edgeDetector(cv::Mat c_input) : input_img{c_input} {}
edgeDetector::~edgeDetector() {}
/****************************************************************************************************************/
/*******************************************Call back Functions for Trackbars*************************************/

    
void 
edgeDetector::callBackTrackBarCanny(int, void*){
    /*****************************************************************************************************************************************************
     * ***************************************************************************************************************************************************
    */
    /******************************************************HSV Converter*******************************************************/
    cv::Mat hsvImage = cdst.clone();
    cv::cvtColor(hsvImage, hsvImage, cv::COLOR_BGR2HSV);
    /********************************************Color Thresholding***********************************************************/
    cv::Scalar lowerBound(36,25,25);
    cv::Scalar upperBound(70,255,255);
    cv::Scalar lowerRed1(0, 100, 20);
    cv::Scalar upperRed1(10, 255, 255);
    cv::Scalar lowerRed2(160, 100, 20);
    cv::Scalar upperRed2(179, 255, 255);
    cv::Scalar lower_blue(100, 50, 50);
    cv::Scalar upper_blue(130, 255, 255);
    /***************************************************MASKING IMAGE ***********************************************************/
    cv::Mat maskGreen, maskRed,maskBlue;
    cv::inRange(hsvImage, lowerBound, upperBound, maskGreen);
    cv::inRange(hsvImage, lowerRed1, upperRed1, maskRed);
    cv::inRange(hsvImage, lowerRed2, upperRed2, maskRed);
    cv::inRange(hsvImage, lower_blue, upper_blue, maskBlue);
    dst = cdst.clone();
    dst2 = cdst.clone();
    dst3 = cdst.clone();
    dst3.copyTo(maskedImage_blue, maskBlue);
    dst2.copyTo(maskedImage_red, maskRed);
    dst.copyTo(maskedImage_green, maskGreen);
    /******************************************************************************************************************************/
    //cv::imshow("masked image for green", maskedImage_green);
    //cv::imshow("masked image for red", maskedImage_red);
    //cv::imshow("masked image for blue", maskedImage_blue);
        /*****************************************************************************************************************************************************
     * ***************************************************************************************************************************************************/
    
    /************************************************************************HOUGH TRANSFORM****************************************************************/
    th1 = lowerThreshold;
    th2 = th1 * 0.4;    
    cv::Canny(maskedImage_green, EdgeImage, th1, th2);  
        // apply hough line transform
    cv::HoughLinesP(EdgeImage, lines, 2, CV_PI/180, 50, 250, 3);
    std::vector<cv::Point> vertices;
    // Draw the lines
    std::vector<int> line;
    std::cout << "***********************New Lines********************" << std::endl;
    for( size_t i = 0; i < lines.size(); i++ ){
        cv::Vec4i l = lines[i];
        std::cout << "Points of the Line: (" << l[0] << ", " << l[1] <<"), (" << l[2] << ", " << l[3] << ")" << std::endl;
        std::cout << "SLOPE of the line is: "<<  (float)(l[3] - l[1]) / (float)(l[2] - l[0])  << std::endl;
        vertices.push_back(cv::Point(l[0], l[1]));
        vertices.push_back(cv::Point(l[2], l[3]));
        //std::cout << "\n****************************Start Printing Points************************" << std::endl;
        cv::line( dst, cv::Point(l[0], l[1]), cv::Point(l[2], l[3]), cv::Scalar(128,0,128), 2, cv::LINE_AA);
    }
    //cv::fillPoly(dst, std::vector<std::vector<cv::Point>>{vertices}, cv::Scalar(0, 0, 255));
    cv::imshow("edgeImages", EdgeImage);
    cv::imshow("Detected Lines (in red) - Standard Hough Line Transform", dst);
}
/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

/********************************************************CALLBACK FUNCTION FOR GAUSSIAN**************************************************/
void 
edgeDetector::callBackTrackBarFilter(int kernel, void*){
    if (kernel % 2 == 0) {  // check if the value is even
        kernel++;  // make it odd
        if (kernel > max_value) {
            kernel = max_value;  // make sure it doesn't exceed the maximum
        }
        cv::setTrackbarPos("MyTrackbar", "MyWindow", kernel);  // update the trackbar
    }
    cv::bilateralFilter(grayImage, gaussianImage, kernel, 70,70);
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