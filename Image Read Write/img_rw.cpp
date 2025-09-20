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

    // int n = img.rows;
    // int m = img.cols;

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         cout << (int)img.at<uchar>(i,j) << " ";
    //     }
    //     cout << endl;
    // }

    Mat img_col = imread(img_name, IMREAD_COLOR);
    if (img_col.empty()) {
        return 0;
    }

    imshow("Image-01", img_col);
    waitKey(0);

    Mat img_unchanged = imread(img_name, IMREAD_UNCHANGED);
    if (img_unchanged.empty()) {
        return 0;
    }

    imshow("Image-02", img_unchanged);
    waitKey(0);

    Mat img_gray = imread(img_name, IMREAD_GRAYSCALE);
    if (img_gray.empty()) {
        return 0;
    }

    imshow("Image-03", img_gray);
    waitKey(0);

    imwrite("temp_" + img_name, img_gray);

    return 0;

}