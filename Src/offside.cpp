#include <opencv2/opencv.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include "edgeDetection.h"
#include "ObjectDetection.h"


int main(int argc, char** argv){


    /**************************************************************Reading the image******************************************************************************/
    cv::CommandLineParser parser(argc, argv, "{@input | /home/parsa/Documents/Unipd/2ndSem-30/3-ComputerVision-21-June/LAB5/offside_images/offside2.jpg | Input Image}");
    cv::Mat src = cv::imread(cv::samples::findFile(parser.get<cv::String>("@input")), cv::IMREAD_COLOR);
    /*************************************************************************************************************************************************************/
    /**************************************************************Edge Detection******************************************************************************/
    edgeDetector edge{src};
    edge.do_edgeDetection();
    objDetection obj{src};
    obj.do_objDetection();
    /*************************************************************************************************************************************************************/
    cv::imshow("img", src);



    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;   
}
