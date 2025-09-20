#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// s = c * r ^ y

int32_t main() {

    string img_name = "test.jpg";

    Mat img = imread(img_name, IMREAD_GRAYSCALE);
    if (img.empty()) {
        return 0;
    }

    Mat img_float;
    img.convertTo(img_float, CV_32F, 1.0/255.0);

    double gamma = 1.7;
    Mat img_gamma = Mat::zeros(img.size(), CV_32F);

    int n = img.rows, m = img.cols;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            img_gamma.at<float>(i,j) = pow(img_float.at<float>(i, j), gamma);
        }
    }

    Mat out;
    img_gamma.convertTo(out, CV_8U, 255.0);

    imshow("Image-00", out);
    waitKey(0);

    return 0;
}