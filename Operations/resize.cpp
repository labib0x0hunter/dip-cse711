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

    // Not Working ?/
    // Mat img_new;
    // resize(img, img_new, Size(30, 300));

    // imshow("Image-01", img_new);
    // waitKey(0);

    return 0;
}