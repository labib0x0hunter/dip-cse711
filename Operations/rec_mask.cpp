#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat Negative(Mat& img, Mat& mask) {
    Mat neg;
    img.copyTo(neg); // what does it do ??
    bitwise_not(img, neg, mask);
    return neg;
}

int32_t main() {

    string img_name = "xray_lungs.jpg";

    Mat img = imread(img_name, IMREAD_GRAYSCALE);
    if (img.empty()) {
        return 0;
    }

    Mat mask = Mat::zeros(img.size(), CV_8UC1);

    // cout << img.cols << " " << img.rows << endl;
    rectangle(mask, Point(50, 50), Point(200, 200), Scalar(255), -1);


    Mat out = Negative(img, mask);

    imshow("log-neg", out);
    waitKey(0);

    return 0;
}