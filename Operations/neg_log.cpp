#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat Negative(Mat& img) {
    Mat neg;
    bitwise_not(img, neg);
    return neg;
}

Mat Log_transfer(Mat& img) {
    Mat tmp; // float
    img.convertTo(tmp, CV_32F);

    double r;
    minMaxLoc(tmp, nullptr, &r);

    double c = (double)255 / log(1 + r);
    Mat logg;

    log(tmp + 1, logg);
    logg = c * logg;
    logg.convertTo(tmp, CV_8U);
    return tmp;
}

int32_t main() {

    string img_name = "xray_lungs.jpg";

    Mat img = imread(img_name, IMREAD_GRAYSCALE);
    if (img.empty()) {
        return 0;
    }

    Mat out = Negative(img);
    out = Log_transfer(out);

    imshow("Neg-log", out);
    waitKey(0);

    out = Log_transfer(img);
    out = Negative(out);

    imshow("log-neg", out);
    waitKey(0);

    return 0;
}