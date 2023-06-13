#ifndef HIST
#define HIST

#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <iostream>
#include <vector>


class histoGram{

    private:
        cv::Mat input_image;
        cv::Mat output_image;

    public:
        
        histoGram(cv::Mat in_im);
        ~histoGram();

        void do_Histogram();
        void showHistogram(std::vector<cv::Mat>& hists);

};






#endif //HIST