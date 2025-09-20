#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int32_t main() {

    string img_name = "test.jpg";

    Mat img = imread(img_name);
    if (img.empty()) {
        return 0;
    }

    imshow("Image-00", img);
    waitKey(0);

    Mat img_gray;
    cvtColor(img, img_gray, COLOR_BGR2GRAY);

    imshow("Image-01", img_gray);
    waitKey(0);

    /*
        COLOR_BGR2GRAY
        COLOR_BGR2HSV
        COLOR_BGR2LAB
        COLOR_BGR2RGB
        COLOR_BGR2YCrCb
    */

    Mat img_float, img_uint;
    img.convertTo(img_float, CV_32F);
    img.convertTo(img_uint, CV_8U);

    return 0;
}