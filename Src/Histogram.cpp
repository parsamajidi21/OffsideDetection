#include "Histogram.h"
#include "edgeDetection.h"
#include "ObjectDetection.h"


        histoGram::histoGram(cv::Mat in_im) : input_image{in_im} {}
        histoGram::~histoGram() {}


        void histoGram::showHistogram(std::vector<cv::Mat>& hists){
            double h_max[3] = {0,0,0};
            double min;
            cv::minMaxLoc(hists[0], &min, &h_max[0]);
            cv::minMaxLoc(hists[1], &min, &h_max[1]);
            cv::minMaxLoc(hists[2], &min, &h_max[2]);

            std::string wname[3] = { "Blue", "Green", "Red" };
            cv::Scalar colors[3] = { cv::Scalar(255,0,0), cv::Scalar(0,255,0),
                                    cv::Scalar(0,0,255) };

            std::vector<cv::Mat> canvas(hists.size());

            // Display each histogram in a canvas
            for (int i = 0, end = hists.size(); i < end; i++)
            {
                canvas[i] = cv::Mat::ones(125, hists[0].rows, CV_8UC3);

                for (int j = 0, rows = canvas[i].rows; j < hists[0].rows-1; j++)
                {
                cv::line(
                        canvas[i],
                        cv::Point(j, rows),
                        cv::Point(j, rows - (hists[i].at<float>(j) * rows/h_max[i])),
                        hists.size() == 1 ? cv::Scalar(300,300,300) : colors[i],
                        1, 8, 0
                        );
                }

                cv::imshow(hists.size() == 1 ? "Value" : wname[i], canvas[i]);
            }
        }
        void histoGram::do_Histogram(){

            std::vector<cv::Mat> _bgr;
            cv::split(input_image, _bgr);
            int histsize = 256;
            float range[] = {0, 256};
            const float* histRange[] = {{range}};
            bool uniform=true, accumulate = false;

            cv::Mat b_hist, g_hist, r_hist;  

            cv::calcHist(&_bgr[0],1, 0, cv::Mat(), b_hist, 1, &histsize, histRange, uniform, accumulate);
	        cv::calcHist(&_bgr[1],1, 0, cv::Mat(), g_hist, 1, &histsize, histRange, uniform, accumulate);
	        cv::calcHist(&_bgr[2],1, 0, cv::Mat(), r_hist, 1, &histsize, histRange, uniform, accumulate);

            showHistogram(_bgr);
	        //cv::imshow("clacHist", input_image);
            cv::Mat equlizedImg;
            cv::equalizeHist(_bgr[0], _bgr[0]);
            cv::equalizeHist(_bgr[1], _bgr[1]);
            cv::equalizeHist(_bgr[2], _bgr[2]);
            cv::merge(_bgr, equlizedImg);
            showHistogram(_bgr);
            cv::imshow("EqualizedHist", equlizedImg);
        }   
