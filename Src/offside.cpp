#include <opencv2/opencv.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include "edgeDetection.h"
#include "ObjectDetection.h"
#include <opencv2/xfeatures2d.hpp>
int main(int argc, char** argv){


    /**************************************************************Reading the image******************************************************************************/
    cv::CommandLineParser parser(argc, argv, "{@input | /home/parsa/Documents/Unipd/2ndSem-30/3-ComputerVision-21-June/LAB5/offside_images/offside2.jpg | Input Image}");
    cv::Mat src = cv::imread(cv::samples::findFile(parser.get<cv::String>("@input")), cv::IMREAD_COLOR);
    /*************************************************************************************************************************************************************/
    cv::resize(src, src, cv::Size(src.cols * 0.75,src.rows * 0.75));
    cv::Mat img = src.clone();
/**************************************************************Object Detection******************************************************************************/
    objDetection obj{img};
    obj.do_objDetection();
    //std::vector<cv::Point> playerPoint = obj.getPlayerPositions();
    edgeDetector edge{src};
    edge.do_edgeDetection();
    std::vector<cv::Point>& linePoint = edge.getLinePoint();
    //std::cout << "playerPoints:\n" << playerPoint << std::endl;
    std::cout << "*********************************************************" << std::endl;
    std::cout << "linePoints:\n" << linePoint << std::endl;
  /*************************************************************************************************************************************************************/
    cv::imshow("Original Image", src);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;   
}
