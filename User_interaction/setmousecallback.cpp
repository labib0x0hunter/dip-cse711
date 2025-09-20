#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void mouseHandler(int event, int x, int y, int, void *) {
    cout << event << " " << x << " " << y << endl;
}

int32_t main() {

    string img_name = "bla.webp";

    Mat img = imread(img_name);
    if (img.empty()) {
        return 0;
    }

    namedWindow("hello");
    setMouseCallback("hello", mouseHandler, nullptr);
    imshow("hello", img);

    waitKey(0);

    return 0;
}