#include <opencv2/opencv.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include "edgeDetection.h"
#include "ObjectDetection.h"
#include <opencv2/xfeatures2d.hpp>
#include "Histogram.h"
int main(int argc, char** argv){


    /**************************************************************Reading the image******************************************************************************/
    cv::CommandLineParser parser(argc, argv, "{@input | /home/parsa/Documents/Unipd/2ndSem-30/3-ComputerVision-21-June/LAB5/offside_images/offside2.jpg | Input Image}");
    cv::Mat src = cv::imread(cv::samples::findFile(parser.get<cv::String>("@input")), cv::IMREAD_COLOR);
    /*************************************************************************************************************************************************************/
    /**************************************************************Edge Detection******************************************************************************/
    cv::resize(src, src, cv::Size(src.cols * 0.75,src.rows * 0.75));
    cv::Mat img = src.clone();
    //edgeDetector edge{src};
    //edge.do_edgeDetection();
    histoGram obj1{src};
    obj1.do_Histogram();
    objDetection obj{img};
    obj.do_objDetection();
    /*************************************************************************************************************************************************************/
    cv::imshow("Original Image", src);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;   
}
