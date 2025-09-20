#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int32_t main() {

    string img_name = "bla.webp";

    Mat img = imread(img_name);
    if (img.empty()) {
        return 0;
    }

    Rect roi = selectROI("img", img);
    cout << roi.area() << endl;

    Mat cropped = img(roi);
    imshow("hello", cropped);

    waitKey(0);

    return 0;
}