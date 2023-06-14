#ifndef OBJ_DETECTION
#define OBJ_DETECTION

#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/cuda.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <iostream>
#include <vector>

class objDetection{
    
    private:

        cv::Mat input_img_o;


    public:
        objDetection(cv::Mat o_input);

        ~objDetection();

        void do_objDetection();
        std::vector<cv::Point> getPlayerPositions() const;

};


#endif //OBJ_DETECTION