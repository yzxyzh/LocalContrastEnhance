//
//  main.cpp
//  LocalContrastEnhance
//
//  Created by Yanzixu on 14-8-29.
//  Copyright (c) 2014年 Yanzixu. All rights reserved.
//

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <string>

using namespace std;
using namespace cv;


int main(int argc, const char * argv[])
{

    string fileName="/Users/yanzixu/Desktop/123.png";
    Mat img=imread(fileName,CV_LOAD_IMAGE_GRAYSCALE);
    
    const int kerSize=51;
    Mat gBlur;
    cv::GaussianBlur(img, gBlur, cv::Size(kerSize,kerSize), kerSize/3.0);
    
    Mat result;
    cv::addWeighted(img, 1.5, gBlur, -0.5, 0, result);
    
    imshow("RESULT",result);
    waitKey(0);
    
    return 0;
}

