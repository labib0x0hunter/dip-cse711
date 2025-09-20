# dip-cse711

---
**Mac Setup**
- install opencv
```bash
brew install opencv
```

- verify
```bash
pkg-config --modversion opencv4
```

- code `dip.cpp`
```c++
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
```bash
g++ -std=c++20 dip.cpp -o dip `pkg-config --cflags --libs opencv4` && (./dip)
```
---

**python3**
- create virtual environment
```bash
python3 -m venv opencv_dip
source opencv_dip/bin/activate
```
- install opencv
```bash
pip install numpy-2.2.6, opencv-python-4.12.0.88
```

---
**Topics**
- image negative
- log transformation
- gamma transformation