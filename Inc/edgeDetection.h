#ifndef EDGE_DETECTION
#define EDGE_DETECTION

#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <iostream>
#include <vector>

class edgeDetector{
    
    private:

        cv::Mat input_img;
       //std::vector<cv::Point> playesrPositions;
       cv::Mat result_img;
        
    public:
        edgeDetector(cv::Mat c_input);

        ~edgeDetector();

        static std::vector <cv::Point> linePos;
        
        void do_edgeDetection();
        
        static void callBackTrackBarFilter(int, void *);

        static void callBackTrackBarCanny(int, void *);
        
        std::vector <cv::Point>& getLinePoint() const;

};


#endif //EDGE_DETECTION