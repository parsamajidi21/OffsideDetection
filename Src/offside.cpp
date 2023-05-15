#include <opencv2/opencv.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include "edgeDetection.h"



int main(int argc, char** argv){


    /**************************************************************Reading the image******************************************************************************/
    cv::CommandLineParser parser(argc, argv, "{@input | ./LAB5/offside_images/offside2.jpg | Input Image}");
    cv::Mat src = cv::imread(cv::samples::findFile(parser.get<cv::String>("@input")), cv::IMREAD_COLOR);
    /*************************************************************************************************************************************************************/
    /**************************************************************Edge Detection******************************************************************************/
    edgeDetector edge{src};
    edge.do_edgeDetection();
    /*************************************************************************************************************************************************************/
    cv::imshow("img", src);



    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;   
}
