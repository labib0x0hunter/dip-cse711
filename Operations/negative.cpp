#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// s = (L - 1) - r

int32_t main() {

    string img_name = "bla.webp";

    Mat img = imread(img_name, IMREAD_GRAYSCALE);
    if (img.empty()) {
        return 0;
    }

    imshow("Image-00", img);
    waitKey(0);

    Mat img_neg = 255 - img;

    imshow("Image-01", img_neg);
    waitKey(0);

    bitwise_not(img, img_neg);
    imshow("Image-02", img_neg);
    waitKey(0);

    return 0;
}