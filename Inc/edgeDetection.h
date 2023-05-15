#ifndef EDGE_DETECTION
#define EDGE_DETECTION


#include <opencv2/opencv.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <iostream>
#include <vector>

class edgeDetector{
    
    private:

        cv::Mat input_img;
        
        cv::Mat result_img;

    public:
        edgeDetector(cv::Mat c_input);

        ~edgeDetector();

        void do_edgeDetection();

        static void callBackTrackBarFilter(int, void *);

        static void callBackTrackBarCanny(int, void *);
};


#endif //EDGE_DETECTION