#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat Negative(Mat& img, Mat& mask) {
    Mat neg;
    img.copyTo(neg);
    bitwise_not(img, neg, mask);
    return neg;
}

int32_t main() {

    string img_name = "bla.webp";

    Mat img = imread(img_name, IMREAD_GRAYSCALE);
    if (img.empty()) {
        return 0;
    }

    Rect roi = selectROI("img", img);

    cout << roi.x << " " << roi.y << endl;
    cout << roi.x + roi.width - 1 << " " << roi.y + roi.height - 1 << endl;

    int start_x, start_y, end_x, end_y;
    start_x = roi.x;
    start_y = roi.y;
    end_x = start_x + roi.width - 1;
    end_y = start_y + roi.height - 1;

    Mat mask = Mat::zeros(img.size(), CV_8UC1);

    // // cout << img.cols << " " << img.rows << endl;
    rectangle(mask, Point(start_x, start_y), Point(end_x, end_y), Scalar(255), -1);


    Mat out = Negative(img, mask);

    imshow("log-neg", out);
    waitKey(0);

    return 0;
}