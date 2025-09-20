#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// s = c * log(1 + r)

int32_t main() {

    string img_name = "bla.webp";

    Mat img = imread(img_name);
    if (img.empty()) {
        return 0;
    }

    Mat img_float;
    img.convertTo(img_float, CV_32F);

    double max_intensity;
    minMaxLoc(img_float, nullptr, &max_intensity);

    // cout << max_intensity << endl;

    double c = (double)255 / log(1 + max_intensity);

    // cout << c << endl;

    Mat img_log_tran, out;
    log(img_float + 1, img_log_tran);

    img_log_tran = c * img_log_tran;
    img_log_tran.convertTo(out, CV_8U);

    imshow("Image-00", out);
    waitKey(0);

    return 0;
}