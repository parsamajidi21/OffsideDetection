#ifndef OBJ_DETECTION
#define OBJ_DETECTION

#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <iostream>
#include <vector>

class objDetection{
    
    private:

        cv::Mat input_img_o;
        
        cv::Mat result_img;

    public:
        objDetection(cv::Mat o_input);

        ~objDetection();

        void do_objDetection();
};


#endif //OBJ_DETECTION