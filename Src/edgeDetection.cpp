#include "edgeDetection.h"
#include "ObjectDetection.h"

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
std::vector<cv::Point> edgeDetector::linePos;
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
    /***************************************************MASKING IMAGE ***********************************************************/
    cv::Mat maskGreen;
    cv::inRange(hsvImage, lowerBound, upperBound, maskGreen);
    dst = cdst.clone();
    dst.copyTo(maskedImage_green, maskGreen);
    //cv::imshow("masked image for green", maskedImage_green);
    /******************************************************************************************************************************/

    /*****************************************************************************************************************************************************
     ***************************************************************************************************************************************************/
    
    /************************************************************************HOUGH TRANSFORM****************************************************************/
    th1 = lowerThreshold;
    th2 = th1 * 0.4;    
    cv::Canny(maskedImage_green, EdgeImage, th1, th2);  
        // apply hough line transform
    cv::HoughLinesP(EdgeImage, lines, 2, CV_PI/180, 50, 250, 25);
    std::vector<cv::Point> vertices;
    // Draw the lines
    std::vector<int> line;
    for( size_t i = 0; i < lines.size(); i++ ){
        cv::Vec4i l = lines[i];
        //std::cout << "Points of the Line: (" << l[0] << ", " << l[1] <<"), (" << l[2] << ", " << l[3] << ")" << std::endl;
        //std::cout << "SLOPE of the line is: "<<  (float)(l[3] - l[1]) / (float)(l[2] - l[0])  << std::endl;
        vertices.push_back(cv::Point(l[0], l[1]));
        vertices.push_back(cv::Point(l[2], l[3]));
        linePos = vertices; 
        cv::line( dst, cv::Point(l[0], l[1]), cv::Point(l[2], l[3]), cv::Scalar(128,0,128), 2, cv::LINE_AA);
    }
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

std::vector <cv::Point>&
edgeDetector::getLinePoint() const{
    return linePos;
}
/************************************************************************************************************************************/