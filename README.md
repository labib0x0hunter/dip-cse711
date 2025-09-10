# dip-cse711

---
**Mac Setup**
- install opencv
```
brew install opencv
```

- verify
```
pkg-config --modversion opencv4
```

- code `dip.cpp`
```
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	Mat img = imread("test.jpg");
	if (img.empty()) {
		return -1;
	}
	imshow("Image", img);
	waitKey(0);
	return 0;
}
```

- compile & run
```
g++ -std=c++20 dip.cpp -o dip `pkg-config --cflags --libs opencv4` && (./dip)
```
---